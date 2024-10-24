#pragma once

#include <vector>

using Grid = std::vector<std::string>;

bool reflects(Grid grid, int start_index);
int findSplit(Grid grid);
Grid transpose(Grid vector);