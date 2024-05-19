#include "pipe_maze.hpp"

MazePoint find_starting_point(const PipeMaze& pipe_maze)
{
    for(auto i = 0U; i < pipe_maze.size(); i++)
    {
        for(auto j = 0U; j < pipe_maze[i].size(); j++)
        {
            if(pipe_maze[i][j] == 'S')
            {
                return MazePoint(i, j);
            }
        }
    }
    return MazePoint(-1, -1);
}
