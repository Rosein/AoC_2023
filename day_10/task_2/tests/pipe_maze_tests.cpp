#include "day_10/task_2/pipe_maze.hpp"
#include "gtest/gtest.h"

struct PipeMazeTests : public ::testing::Test
{
    const PipeMaze pipe_maze = {"..F7.", ".FJ|.", "SJ.L7", "|F--J", "LJ..."};
};

TEST_F(PipeMazeTests, GivenMazeWithPipeLoop_WhenTransformToAttributedMaze_ExpectAdditionalAttributeToAccess)
{
    const AttributedMaze maze{transform_to_attributed_maze(pipe_maze)};

    for(auto i = 0U; i < pipe_maze.size(); ++i)
        for(auto j = 0U; j < pipe_maze[i].size(); ++j)
        {
            constexpr auto expected_state = State::Undefined;
            const auto expected_pipe = pipe_maze[i][j];

            ASSERT_EQ(maze.check_state_at(i, j), expected_state);
            ASSERT_EQ(maze.check_pipe_at(i, j), expected_pipe);
        }
}