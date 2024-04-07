#include "pipe_maze.hpp"

std::pair<int, int> find_starting_point(const PipeMaze& pipe_maze)
{
    for(auto i = 0U; i < pipe_maze.size(); i++)
    {
        for(auto j = 0U; j < pipe_maze[i].size(); j++)
        {
            if(pipe_maze[i][j] == 'S')
            {
                return std::make_pair(i, j);
            }
        }
    }
    return std::make_pair(-1, -1);
}