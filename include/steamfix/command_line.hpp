#pragma once

#include <string>
#include <string_view>

namespace steamfix::command_line {

void append_quoted(std::wstring& line, std::wstring_view argument);

} // namespace steamfix::command_line
