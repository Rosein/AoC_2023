#include "point_of_incidence.hpp"
#include <iostream>


bool reflects(Grid grid, int start_index)
{
    if(grid.size() < 2)
    {
        std::cout << "Can't reflect, becuase size is lower than 2";
        return 0;
    }

    int lower{start_index};
    int upper{start_index + 1};
    bool fixed_one{false};

    while(lower >= 0 and upper < grid.size())
    {
        if(grid[lower] != grid[upper])
        {
            // return false;
            if(fixed_one)
            {
                return false;
            }
            else if (isFixable(grid[lower], grid[upper]))
            {
                fixed_one = true;
            }
            else
            {
                return false;
            }
        }
        lower -= 1;
        upper += 1;
    }

    return fixed_one;
}

int findSplit(Grid grid)
{
    for(int i = 0; i < grid.size() - 1; ++i)
    {
        if(reflects(grid, i))
        {
            return i + 1;
        }
    }
    return 0;
}

Grid transpose(Grid grid)
{
    if(grid.empty())
    {
        return {};
    }

    Grid transposed_grid{};
    for (size_t j = 0; j < grid[0].size(); ++j)
    {
        std::string new_row;
        for (size_t i = 0; i < grid.size(); ++i)
        {
            new_row.push_back(grid[i][j]);
        }
        transposed_grid.push_back(new_row);
    }

    return transposed_grid;
}

int countReflection(std::vector<Grid> grids)
{
    int total{0};
    for(auto grid : grids)
    {
        auto horizontal = findSplit(grid);
        Grid transposed = transpose(grid);
        auto vertical = findSplit(transposed);
        transposed.clear();

        total += 100 *  horizontal;
        total +=   vertical;
    }
    return total;
}


bool isFixable(const std::string& row1, const std::string& row2)
{
    int differences = 0;

    for (size_t i = 0; i < row1.length() and i < row2.length(); ++i)
    {
        if (row1[i] != row2[i])
        {
            differences++;
        }
    }

    return differences == 1;
}