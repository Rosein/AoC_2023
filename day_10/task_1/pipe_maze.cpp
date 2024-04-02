#include "pipe_maze.hpp"
#include <algorithm>
#include <cassert>


std::pair<int, int> find_starting_point(const PipeMaze& pipe_maze)
{
    for(int i = 0; i < pipe_maze.size(); i++)
    {
        for(int j = 0; j < pipe_maze[i].size(); j++)
        {
            if(pipe_maze[i][j] == 'S')
            {
                return std::make_pair(i, j);
            }
        }
    }
    return std::make_pair(-1, -1);
}