#pragma once

#include <filesystem>
#include <optional>

namespace steamfix::overlay {
std::optional<std::filesystem::path> loaded_renderer();
}
