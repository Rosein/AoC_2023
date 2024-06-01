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

TEST_F(PipeMazeTests, GivenStartingPoint_WhenGoForwardTwoTimesFirstDirection_ExpectReturnAppropriateCoordinates)
{
    const MazePoint starting_pipe(find_starting_point(pipe_maze));
    const auto foundNeighbors = find_next_neighbors(pipe_maze, starting_pipe);

    auto current_point_in_first_direction = go_forward(foundNeighbors.first, starting_pipe);
    ASSERT_EQ(current_point_in_first_direction, MazePoint(1, 3));
    current_point_in_first_direction =
        go_forward(current_point_in_first_direction, foundNeighbors.first);
    ASSERT_EQ(current_point_in_first_direction, MazePoint(2, 3));
}

TEST_F(PipeMazeTests, GivenStartingPoint_WhenGoForwardTwoTimesSecondDirection_ExpectReturnAppropriateCoordinates)
{
    const MazePoint starting_pipe(find_starting_point(pipe_maze));
    const auto foundNeighbors = find_next_neighbors(pipe_maze, starting_pipe);

    auto current_point_in_second_direction =
        go_forward(foundNeighbors.second, starting_pipe);
    ASSERT_EQ(current_point_in_second_direction, MazePoint(3, 1));
    current_point_in_second_direction =
        go_forward(current_point_in_second_direction, foundNeighbors.second);
    ASSERT_EQ(current_point_in_second_direction, MazePoint(3, 2));
}
