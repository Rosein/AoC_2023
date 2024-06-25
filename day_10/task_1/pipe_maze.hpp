#pragma once
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
