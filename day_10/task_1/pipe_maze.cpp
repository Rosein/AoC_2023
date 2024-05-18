#include "pipe_maze.hpp"
#include <cassert>
#include <string>
#include <vector>

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

bool is_connected_to_north(const char candi_south_pipe)
{
    static const std::string pipes_to_north{"|LJ"};
    return pipes_to_north.contains(candi_south_pipe);
}

bool is_connected_to_south(const char candi_north_pipe)
{
    static const std::string pipes_to_south{"|F7"};
    return pipes_to_south.contains(candi_north_pipe);
}

bool is_connected_to_west(const char candi_east_pipe)
{
    static const std::string pipes_to_west{"-7J"};
    return pipes_to_west.contains(candi_east_pipe);
}

bool is_connected_to_east(const char candi_west_pipe)
{
    static const std::string pipes_to_east{"-FL"};
    return pipes_to_east.contains(candi_west_pipe);
}

MazePoint to_south(MazePoint position)
{
    position.first++;
    return position;
}

MazePoint to_north(MazePoint position)
{
    position.first--;
    return position;
}

MazePoint to_east(MazePoint position)
{
    position.second++;
    return position;
}

MazePoint to_west(MazePoint position)
{
    position.second--;
    return position;
}

std::pair<MazePoint, MazePoint> find_next_neighbors(const PipeMaze& pipe_maze,
                                                    const MazePoint& maze_point)
{
    const MazePoint current_position(find_starting_point(pipe_maze));
    std::vector<MazePoint> neighbors;

    if(is_connected_to_south(
           pipe_maze[to_north(current_position).first][current_position.second]))
    {
        neighbors.push_back(MazePoint(to_north(current_position)));
    }

    if(is_connected_to_north(
           pipe_maze[to_south(current_position).first][current_position.second]))
    {
        neighbors.push_back(MazePoint(to_south(current_position)));
    }

    if(is_connected_to_west(
           pipe_maze[current_position.first][to_east(current_position).second]))
    {
        neighbors.push_back(MazePoint(to_east(current_position)));
    }

    if(is_connected_to_east(
           pipe_maze[current_position.first][to_west(current_position).second]))
    {
        neighbors.push_back(MazePoint(to_west(current_position)));
    }

    assert((neighbors.size() == 2) &&
           "Pipe at current_position must have exactly two neighbors");

    return {neighbors.back(), neighbors.front()};
}
