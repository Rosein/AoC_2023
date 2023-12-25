#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "scratchcards.hpp"


void run_tests();

void run_app()
{
    std::string filename{"input"};
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

    std::cout << ExtractorOfNumberAdjacentToSymbol{engine_schematic}.sum_gear_ratios() << std::endl;

    fs.close();
}

int main()
{
    run_app();
    // run_tests();
    return 0;
}

void run_tests()
{
    {
        
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}

