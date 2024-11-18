#include "point_of_incidence.hpp"
#include "path_helper/path_helper.hpp"
#include <fstream>
#include <iostream>
#include <string>

void run_tests();

void run_app(std::string filename)
{
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::vector<Grid> grids;
    Grid currentGrid;
    std::string line;

    while(std::getline(fs, line))
    {
        if (line.empty())
        {
            if (!currentGrid.empty())
            {
                grids.push_back(currentGrid);
                currentGrid.clear();
            }
        } else {
            currentGrid.push_back(line);
        }
    }

    if (!currentGrid.empty()) {
        grids.push_back(currentGrid);
    }

    long long unsigned int total{0};
    total += countReflection(grids);
    std::cout << "Total distance: " << total << std::endl;
    fs.close();
}

int main(int argc, char** argv)
{
    std::string filename = std::string{"/Users/dariakumanek/Desktop/workspace/projects/AoC_2023/day_13/task_1/input"};
    run_app(filename);
    return 0;
}
