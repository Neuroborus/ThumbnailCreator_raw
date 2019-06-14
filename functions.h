#pragma once
#include "headers.h"

#include <fstream>
#include <cstdint>
#include <filesystem>
namespace fs = std::experimental::filesystem;

bool IsPathExist(const fs::path& p, fs::file_status s = fs::file_status{});