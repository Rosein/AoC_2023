#include "pipe_maze.hpp"
#include <cassert>
#include <string>

const MazePoint invalidMazeEntryPoint{-1, -1};

MazePoint AttributedMaze::find_starting_point() const
{
    for(auto i = 0U; i < maze_.size(); i++)
    {
        for(auto j = 0U; j < maze_[i].size(); j++)
        {
            if(maze_[i][j].tile == 'S')
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

std::pair<MazePoint, MazePoint> AttributedMaze::find_next_neighbors(const MazePoint& maze_point) const
{
    const MazePoint current_position(maze_point);
    std::vector<MazePoint> neighbors;

    if(is_connected_to_north(
           maze_[current_position.first][current_position.second].tile) &&
       is_connected_to_south(
           maze_[to_north(current_position).first][current_position.second].tile))
    {
        neighbors.push_back(MazePoint(to_north(current_position)));
    }

    if(is_connected_to_south(
           maze_[current_position.first][current_position.second].tile) &&
       is_connected_to_north(
           maze_[to_south(current_position).first][current_position.second].tile))
    {
        neighbors.push_back(MazePoint(to_south(current_position)));
    }

    if(is_connected_to_east(
           maze_[current_position.first][current_position.second].tile) &&
       is_connected_to_west(
           maze_[current_position.first][to_east(current_position).second].tile))
    {
        neighbors.push_back(MazePoint(to_east(current_position)));
    }

    if(is_connected_to_west(
           maze_[current_position.first][current_position.second].tile) &&
       is_connected_to_east(
           maze_[current_position.first][to_west(current_position).second].tile))
    {
        neighbors.push_back(MazePoint(to_west(current_position)));
    }

    assert((neighbors.size() == 2) &&
           "Pipe at current_position must have exactly two neighbors");

    return {neighbors.back(), neighbors.front()};
}

MazePoint AttributedMaze::go_forward(const MazePoint& current_point,
                                     const MazePoint& previous_point) const
{
    const auto foundNeighbors = find_next_neighbors(current_point);

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

int AttributedMaze::count_steps_to_farthest_point() const
{
    const MazePoint starting_point{find_starting_point()};
    MazePoint prev, current;
    prev = starting_point;
    current = find_next_neighbors(starting_point).first;
    int step_counter{1};

    while(current != starting_point)
    {
        auto temp = go_forward(current, prev);
        prev = current;
        current = temp;
        ++step_counter;
    }

    return step_counter / 2;
}

void AttributedMaze::mark_loop_tiles_in_attributed_maze()
{
    const MazePoint starting_point{find_starting_point()};
    set_state_at(starting_point, State::Loop);
    MazePoint prev, current;
    prev = starting_point;

    current = find_next_neighbors(starting_point).first;
    set_state_at(current, State::Loop);

    int step_counter{1};

    while(current != starting_point)
    {
        auto temp = go_forward(current, prev);
        prev = current;
        current = temp;
        set_state_at(current, State::Loop);
        ++step_counter;
    }
}

AttributedMaze transform_to_attributed_maze(const PipeMaze& pipe_maze)
{
    AttributedMaze attributed_maze;
    AttributedMazePoint attributed_point{};

    for(auto i = 0U; i < pipe_maze.size(); ++i)
    {
        std::vector<AttributedMazePoint> points{};
        for(auto j = 0U; j < pipe_maze[i].size(); ++j)
        {
            attributed_point.state = State::Undefined;
            attributed_point.tile = pipe_maze[i][j];
            points.push_back(attributed_point);
        }
        attributed_maze.maze_.push_back(points);
    }

    return attributed_maze;
}

State AttributedMaze::check_state_at(const MazePoint& point) const
{
    return maze_[point.first][point.second].state;
}

Tile AttributedMaze::check_pipe_at(const MazePoint& point) const
{
    return maze_[point.first][point.second].tile;
}

void AttributedMaze::set_state_at(const MazePoint& point, const State& state)
{
    maze_[point.first][point.second].state = state;
}

void AttributedMaze::set_tile_at(const MazePoint& point, const Tile& tile)
{
    maze_[point.first][point.second].tile = tile;
}

bool AttributedMaze::is_in_maze(const MazePoint& point) const
{
    return point.first >= 0 and point.first < static_cast<int>(maze_[0].size()) and
        point.second >= 0 and point.second < static_cast<int>(maze_.size());
}