#include "steamfix/logging.hpp"

#include <windows.h>

#include <cerrno>
#include <cstdint>
#include <filesystem>
#include <iomanip>
#include <system_error>

namespace fs = std::filesystem;

namespace steamfix {
namespace {
constexpr std::uintmax_t max_log_size = 4U * 1024U * 1024U;

void rotate(const fs::path& path) noexcept {
    std::error_code error;
    if (fs::file_size(path, error) <= max_log_size || error) return;
    const fs::path old = path.parent_path() / (path.stem().native() + L".log.old");
    fs::remove(old, error);
    error.clear();
    fs::rename(path, old, error);
}
} // namespace

Logger::Logger(const fs::path& path) {
    rotate(path);
    errno = 0;
    file_.open(path, std::ios::out | std::ios::app);
    if (!file_) {
        const int code = errno == 0 ? EIO : errno;
        throw std::system_error(code, std::generic_category(), "open log");
    }
}

void Logger::info(const std::string_view message) const noexcept { write("INFO", message); }
void Logger::warn(const std::string_view message) const noexcept { write("WARN", message); }
void Logger::error(const std::string_view message) const noexcept { write("ERROR", message); }

void Logger::write(const std::string_view severity, const std::string_view message) const noexcept {
    try {
        SYSTEMTIME now{};
        GetSystemTime(&now);
        std::lock_guard lock(mutex_);
        size_t start = 0;
        do {
            const size_t end = message.find('\n', start);
            const std::string_view line =
                message.substr(start, end == std::string_view::npos ? end : end - start);
            file_ << std::setfill('0') << std::setw(4) << now.wYear << '-' << std::setw(2)
                  << now.wMonth << '-' << std::setw(2) << now.wDay << 'T' << std::setw(2)
                  << now.wHour << ':' << std::setw(2) << now.wMinute << ':' << std::setw(2)
                  << now.wSecond << '.' << std::setw(3) << now.wMilliseconds << "Z [" << severity
                  << "] [pid=" << GetCurrentProcessId() << "] [v" << STEAMFIX_VERSION << "] "
                  << line << '\n';
            if (end == std::string_view::npos) break;
            start = end + 1;
        } while (start <= message.size());
        file_.flush();
        if (!file_) OutputDebugStringW(L"D2SteamFix: writing steamfix.log failed.\n");
    } catch (...) {
        OutputDebugStringW(L"D2SteamFix: writing steamfix.log failed.\n");
    }
}

} // namespace steamfix
