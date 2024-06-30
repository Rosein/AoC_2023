#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using PipeMaze = std::vector<std::string>;
using MazePoint = std::pair<int, int>;
using MazeTile = char;

MazePoint find_starting_point(const PipeMaze& pipe_maze);
std::pair<MazePoint, MazePoint> find_next_neighbors(const PipeMaze& pipe_maze,
                                                    const MazePoint& maze_point);
MazePoint go_forward(const PipeMaze& pipe_maze,
                     const MazePoint& current_point,
                     const MazePoint& previous_point);

int count_steps_to_farthest_point(const PipeMaze& pipe_maze);

/// @task2
enum class State
{
    Undefined
};

struct AttributedMazePoint
{
    State state;
    MazeTile tile;
};

struct AttributedMaze
{
    State check_state_at(const MazePoint& point) const;
    MazeTile check_pipe_at(const MazePoint& point) const;

    std::vector<std::vector<AttributedMazePoint>> maze_{};
};

AttributedMaze transform_to_attributed_maze(const PipeMaze& pipe_maze);