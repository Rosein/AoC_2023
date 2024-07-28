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
    LeftColor,
    RightColor
};

struct AttributedMazePoint
{
    State state;
    Tile tile;
};

struct AttributedMaze
{
    State check_state_at(const MazePoint& point) const;
    Tile check_tile_at(const MazePoint& point) const;
    void set_state_at(const MazePoint& point, const State& state);
    void set_tile_at(const MazePoint& point, const Tile& state);
    int count_steps_to_farthest_point() const;
    MazePoint find_starting_point() const;
    std::pair<MazePoint, MazePoint> find_next_neighbors(const MazePoint& maze_point) const;
    MazePoint go_forward(const MazePoint& current_point, const MazePoint& previous_point) const;
    void mark_loop_tiles_in_attributed_maze();
    bool is_in_maze(const MazePoint& point) const;
    void color_neighbor(const MazePoint& loop_point, const MazePoint& next_loop_point);
    int count_enclosed_tiles();
    void color_neighbors();
    State find_which_color_is_closed();
    std::vector<MazePoint> generate_all_surroudning_tiles_starting_from_left_top_clock_wise(const MazePoint& mid_loop_point);
    void remove_invalid_maze_points(std::vector<MazePoint>& tiles);
    void print_states();
    State find_the_edge_color_from(const MazePoint& point);
    void fill_all_surrounding_undefined_with_state(const MazePoint& undefined_point, const State& color);

    std::vector<std::vector<AttributedMazePoint>> maze_{};

private:
    void fill_with_color_untouched_non_loop_tiles();
};

AttributedMaze transform_to_attributed_maze(const PipeMaze& pipe_maze);
