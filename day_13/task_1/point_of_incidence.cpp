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

    while(lower >= 0 and upper < grid.size())
    {
        if(grid[lower] != grid[upper])
        {
            return false;
        }
        lower -= 1;
        upper += 1;
    }

    return true;
}