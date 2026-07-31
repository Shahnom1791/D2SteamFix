#pragma once

#include "steamfix/win32.hpp"

#include <filesystem>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace steamfix {
class Logger;
}

namespace steamfix::process {

UniqueHandle open_query(DWORD pid);
std::filesystem::path image_path(HANDLE process);
std::vector<std::pair<DWORD, std::wstring>> matching_in_dir(const std::filesystem::path& directory);
void wait_for_destiny_quiescence(const Logger& log);
std::optional<int> monitor(HANDLE child, DWORD child_pid, const std::filesystem::path& game_dir,
                           const Logger& log) noexcept;
std::vector<DWORD> parent_chain();

} // namespace steamfix::process
