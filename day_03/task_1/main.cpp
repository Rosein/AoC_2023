#include "gear_ratios.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

void run_app()
{
    std::string filename{"/home/rkumanek/Repos/AoC_2023/day_03/task_1/input"};
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;
    EngineSchematic engine_schematic{};

    while(std::getline(fs, line))
    {
        engine_schematic.push_back(line);
    }

    std::cout << ExtractorOfNumberAdjacetToSymbol{}.sum_part_numbers(engine_schematic)
              << std::endl;

    fs.close();
}

int main()
{
    run_app();
    return 0;
}
