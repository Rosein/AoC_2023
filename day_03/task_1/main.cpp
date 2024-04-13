#include "gear_ratios.hpp"
#include "path_helper/path_helper.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

void run_app(std::string filename)
{
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

int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_03/task_1/input"};
    run_app(filename);
    return 0;
}
