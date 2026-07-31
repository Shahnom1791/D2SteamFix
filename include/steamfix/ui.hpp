#pragma once

#include <string_view>

namespace steamfix::ui {
void info(std::wstring_view message) noexcept;
void error(std::wstring_view message) noexcept;
}
