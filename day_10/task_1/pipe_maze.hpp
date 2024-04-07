#pragma once
#include <string>
#include <utility>
#include <vector>

using PipeMaze = std::vector<std::string>;
std::pair<int, int> find_starting_point(const PipeMaze& pipe_maze);
