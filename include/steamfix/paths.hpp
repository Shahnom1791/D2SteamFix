#pragma once

#include <filesystem>
#include <string_view>

namespace steamfix::paths {

bool equal_windows(const std::filesystem::path& left, const std::filesystem::path& right);
bool name_is(const std::filesystem::path& path, std::wstring_view expected);

} // namespace steamfix::paths
