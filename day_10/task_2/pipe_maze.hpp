#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using PipeMaze = std::vector<std::string>;
using MazePoint = std::pair<int, int>;
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
    MazePoint point;
    State state;
    char value;
};

struct AttributedMaze
{
    State check_state_at(int first, int second) const;
    char check_pipe_at(int first, int second) const;

    std::vector<std::vector<AttributedMazePoint>> maze{};
};

AttributedMaze transform_to_attributed_maze(const PipeMaze& pipe_maze);