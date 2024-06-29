#include "path_helper/path_helper.hpp"
#include "pipe_maze.hpp"
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

    std::string line;
    PipeMaze pipe{};

    while(std::getline(fs, line))
    {
        // std::cout << line << std::endl;
        pipe.push_back(line);
    }

    int steps = count_steps_to_farthest_point(pipe);
    std::cout << "steps: " << steps << std::endl;
    fs.close();
}


int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_10/task_1/input"};
    run_app(filename);
    return 0;
}
