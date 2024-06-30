#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using PipeMaze = std::vector<std::string>;
using MazePoint = std::pair<int, int>;
using Tile = char;

enum class State
{
    Undefined,
    Loop,
};

struct AttributedMazePoint
{
    State state;
    Tile tile;
};

struct AttributedMaze
{
    State check_state_at(const MazePoint& point) const;
    Tile check_pipe_at(const MazePoint& point) const;
    void set_state_at(const MazePoint& point, const State& state);
    void set_tile_at(const MazePoint& point, const Tile& state);
    int count_steps_to_farthest_point() const;
    MazePoint find_starting_point() const;
    std::pair<MazePoint, MazePoint> find_next_neighbors(const MazePoint& maze_point) const;
    MazePoint go_forward(const MazePoint& current_point, const MazePoint& previous_point) const;
    void mark_loop_tiles_in_attributed_maze();
    bool is_in_maze(const MazePoint& point) const;

    std::vector<std::vector<AttributedMazePoint>> maze_{};
};

AttributedMaze transform_to_attributed_maze(const PipeMaze& pipe_maze);