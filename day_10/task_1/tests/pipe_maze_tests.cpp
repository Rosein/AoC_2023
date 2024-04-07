#include "day_10/task_1/pipe_maze.hpp"
#include "gtest/gtest.h"

TEST(PipeMazeToolsShould, FindTheStartingPoint)
{
    const PipeMaze pipe_maze = {"-L|F7", "7S-7|", "L|7||", "-L-J|", "L|-JF"};

    ASSERT_EQ(find_starting_point(pipe_maze), (std::make_pair<int, int>(1, 1)));
}
