#pragma once

#include <vector>

using Grid = std::vector<std::string>;

bool reflects(Grid grid, int start_index);
int findSplit(Grid grid);
Grid transpose(Grid vector);
int countReflection(std::vector<Grid> grids);
bool isFixable(const std::string& row1, const std::string& row2);