#include "day_10/task_1/pipe_maze.hpp"
#include "gtest/gtest.h"


struct PipeMazeTests : public ::testing::Test
{
    const PipeMaze pipe_maze = {"-L|F7", "7S-7|", "L|7||", "-L-J|", "L|-JF"};
};

TEST_F(PipeMazeTests, GivenMazeWithPipeLoop_WhenFindTheStartingPoint_ExpectCoordinatesFromFieldWhereS)
{
    ASSERT_EQ(find_starting_point(pipe_maze), MazePoint(1, 1));
}

TEST_F(PipeMazeTests, GivenStartingPipe_WhenFindNextNeighbors_ExpectTwoMazePointsOfConnectedPipes)
{
    const MazePoint starting_pipe(find_starting_point(pipe_maze));

    const auto foundNeighbors = find_next_neighbors(pipe_maze, starting_pipe);

    ASSERT_EQ(foundNeighbors.first, MazePoint(1, 2));
    ASSERT_EQ(foundNeighbors.second, MazePoint(2, 1));
}
