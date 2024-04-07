#include "pipe_maze.hpp"
#include <fstream>
#include <iostream>
#include <string>

void run_tests();

void run_app()
{
    std::string filename{"/home/rkumanek/Repos/AoC_2023/day_10/task_1/input"};
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;

    while(std::getline(fs, line))
    {
        std::cout << line << std::endl;
    }

    fs.close();
}


int main()
{
    run_app();
    return 0;
}
