#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "pipe_maze.hpp"
#include "../../debug_features.hpp"

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

    while(std::getline(fs, line))
    {
        std::cout << line << std::endl;
    }

    fs.close();
}


int main()
{
    // run_app();
    run_tests();
    return 0;
}

void run_tests()
{
    const PipeMaze pipe_maze =
    {
        "-L|F7",
        "7S-7|",
        "L|7||",
        "-L-J|",
        "L|-JF"
    };

    {
        DEBUG_PRINT_TESTNAME("Test find_starting_point() #1:");
        assert(find_starting_point(pipe_maze) == std::make_pair<int,int>(1,1));
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}
