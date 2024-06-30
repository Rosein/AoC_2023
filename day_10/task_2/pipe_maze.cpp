#include "pipe_maze.hpp"
#include <cassert>
#include <string>

const MazePoint invalidMazeEntryPoint{-1, -1};

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
    return invalidMazeEntryPoint;
}

bool is_connected_to_north(const char candi_south_pipe)
{
    static const std::string pipes_to_north{"|LJS"};
    return pipes_to_north.contains(candi_south_pipe);
}

bool is_connected_to_south(const char candi_north_pipe)
{
    static const std::string pipes_to_south{"|F7S"};
    return pipes_to_south.contains(candi_north_pipe);
}

bool is_connected_to_west(const char candi_east_pipe)
{
    static const std::string pipes_to_west{"-7JS"};
    return pipes_to_west.contains(candi_east_pipe);
}

bool is_connected_to_east(const char candi_west_pipe)
{
    static const std::string pipes_to_east{"-FLS"};
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
    const MazePoint current_position(maze_point);
    std::vector<MazePoint> neighbors;

    if(is_connected_to_north(pipe_maze[current_position.first][current_position.second]) &&
       is_connected_to_south(
           pipe_maze[to_north(current_position).first][current_position.second]))
    {
        neighbors.push_back(MazePoint(to_north(current_position)));
    }

    if(is_connected_to_south(pipe_maze[current_position.first][current_position.second]) &&
       is_connected_to_north(
           pipe_maze[to_south(current_position).first][current_position.second]))
    {
        neighbors.push_back(MazePoint(to_south(current_position)));
    }

    if(is_connected_to_east(pipe_maze[current_position.first][current_position.second]) &&
       is_connected_to_west(
           pipe_maze[current_position.first][to_east(current_position).second]))
    {
        neighbors.push_back(MazePoint(to_east(current_position)));
    }

    if(is_connected_to_west(pipe_maze[current_position.first][current_position.second]) &&
       is_connected_to_east(
           pipe_maze[current_position.first][to_west(current_position).second]))
    {
        neighbors.push_back(MazePoint(to_west(current_position)));
    }

    assert((neighbors.size() == 2) &&
           "Pipe at current_position must have exactly two neighbors");

    return {neighbors.back(), neighbors.front()};
}

MazePoint go_forward(const PipeMaze& pipe_maze,
                     const MazePoint& current_point,
                     const MazePoint& previous_point)
{
    const auto foundNeighbors = find_next_neighbors(pipe_maze, current_point);

    if(foundNeighbors.first != previous_point)
    {
        return foundNeighbors.first;
    }
    if(foundNeighbors.second != previous_point)
    {
        return foundNeighbors.second;
    }

    return invalidMazeEntryPoint;
}

int count_steps_to_farthest_point(const PipeMaze& pipe_maze)
{
    const MazePoint starting_point{find_starting_point(pipe_maze)};
    MazePoint prev, current;
    prev = starting_point;
    current = find_next_neighbors(pipe_maze, starting_point).first;
    int step_counter{1};

    while(current != starting_point)
    {
        auto temp = go_forward(pipe_maze, current, prev);
        prev = current;
        current = temp;
        ++step_counter;
    }

    return step_counter / 2;
}

AttributedMaze transform_to_attributed_maze(const PipeMaze& pipe_maze)
{
    AttributedMaze attributed_maze;
    [[maybe_unused]] AttributedMazePoint attributed_point{};

    for(auto i = 0U; i < pipe_maze.size(); ++i)
    {
        std::vector<AttributedMazePoint> points{};
        for(auto j = 0U; j < pipe_maze[i].size(); ++j)
        {
            attributed_point.state = State::Undefined;
            attributed_point.point = MazePoint(i, j);
            attributed_point.value = pipe_maze[i][j];
            points.push_back(attributed_point);
        }
        attributed_maze.maze.push_back(points);
    }
    return attributed_maze;
}

State AttributedMaze::check_state_at(int first, int second) const
{
    for(auto i = 0U; i < maze.size(); ++i)
    {
        for(auto j = 0U; j < maze[i].size(); ++j)
        {
            if(maze[i][j].point == MazePoint(first, second))
            {
                return maze[i][j].state;
            }
        }
    }
    return State::Undefined;
}

char AttributedMaze::check_pipe_at(int first, int second) const
{
    for(auto i = 0U; i < maze.size(); ++i)
    {
        for(auto j = 0U; j < maze[i].size(); ++j)
        {
            if(maze[i][j].point == MazePoint(first, second))
            {
                return maze[i][j].value;
            }
        }
    }
    return '?';
}