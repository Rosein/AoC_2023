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
    AttributedMaze maze{transform_to_attributed_maze(pipe)};
    maze.mark_loop_tiles_in_attributed_maze();

    int number_of_inner_tiles = maze.count_enclosed_tiles();
    std::cout << "number_of_inner_tiles: " << number_of_inner_tiles << std::endl;
    fs.close();
}


int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_10/task_2/input"};
    run_app(filename);
    return 0;
}
