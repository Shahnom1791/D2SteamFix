#pragma once

#include <stdexcept>
#include <string>
#include <utility>

namespace steamfix {

enum class ExitCode : int {
    invalid_invocation = 10,
    log_initialization = 11,
    validation = 12,
    existing_session = 13,
    steam_discovery = 14,
    overlay_loaded = 15,
    overlay_protection = 16,
    process_creation = 17,
    internal = 19,
};

class AppError final : public std::runtime_error {
public:
    AppError(ExitCode code, std::string stage, std::string detail)
        : std::runtime_error(stage + ": " + detail), code_(code), stage_(std::move(stage)),
          detail_(std::move(detail)) {}

    [[nodiscard]] ExitCode code() const noexcept { return code_; }
    [[nodiscard]] const std::string& stage() const noexcept { return stage_; }
    [[nodiscard]] const std::string& detail() const noexcept { return detail_; }
    [[nodiscard]] bool launcher_started() const noexcept { return launcher_started_; }
    AppError& after_launch() noexcept {
        launcher_started_ = true;
        return *this;
    }

private:
    ExitCode code_;
    std::string stage_;
    std::string detail_;
    bool launcher_started_ = false;
};

} // namespace steamfix
