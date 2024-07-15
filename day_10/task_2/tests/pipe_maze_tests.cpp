#include "day_10/task_2/pipe_maze.hpp"
#include "gtest/gtest.h"
#include <tuple>
#include <utility>
#include <vector>

struct PipeMazeTests : public ::testing::Test
{
    const PipeMaze pipe_maze = {"-L|F7", "7S-7|", "L|7||", "-L-J|", "L|-JF"};
    const AttributedMaze maze{transform_to_attributed_maze(pipe_maze)};
};

struct PipeMazeExtendedTests : public ::testing::Test
{
    const PipeMaze pipe_maze_extended = {"..F7.", ".FJ|.", "SJ.L7", "|F--J",
                                         "LJ-.."};
    const AttributedMaze maze_extended{transform_to_attributed_maze(pipe_maze_extended)};
};

TEST_F(PipeMazeTests, GivenMazeWithPipeLoop_WhenFindTheStartingPoint_ExpectCoordinatesFromFieldWhereS)
{
    ASSERT_EQ(maze.find_starting_point(), MazePoint(1, 1));
}

TEST_F(PipeMazeTests, GivenStartingPipe_WhenFindNextNeighbors_ExpectTwoMazePointsOfConnectedPipes)
{
    const MazePoint starting_pipe(maze.find_starting_point());

    const auto foundNeighbors = maze.find_next_neighbors(starting_pipe);

    ASSERT_EQ(foundNeighbors.first, MazePoint(1, 2));
    ASSERT_EQ(foundNeighbors.second, MazePoint(2, 1));
}

TEST_F(PipeMazeTests, GivenStartingPipe_WhenFindNeighborsForNextPoint_ExpectTwoMazePointsOfConnectedPipes)
{
    const MazePoint pipe_which_is_neigbour_of_starting_pipe(MazePoint(1, 2));

    const auto foundNeighborsForSecondPoint =
        maze.find_next_neighbors(pipe_which_is_neigbour_of_starting_pipe);

    const MazePoint starting_pipe{MazePoint(1, 1)};
    ASSERT_EQ(foundNeighborsForSecondPoint.first, starting_pipe);
    ASSERT_EQ(foundNeighborsForSecondPoint.second, MazePoint(1, 3));
}

TEST_F(PipeMazeTests, GivenStartingPoint_WhenGoForwardTwoTimesInFirstDirection_ExpectReturnNextTwoCoordinatesFromExpectedDirection)
{
    const MazePoint starting_pipe(maze.find_starting_point());
    const auto foundNeighbors = maze.find_next_neighbors(starting_pipe);

    auto current_point_in_first_direction =
        maze.go_forward(foundNeighbors.first, starting_pipe);
    ASSERT_EQ(current_point_in_first_direction, MazePoint(1, 3));
    current_point_in_first_direction =
        maze.go_forward(current_point_in_first_direction, foundNeighbors.first);
    ASSERT_EQ(current_point_in_first_direction, MazePoint(2, 3));
}

TEST_F(PipeMazeTests, GivenStartingPoint_WhenGoForwardTwoTimesInSecondDirection_ExpectReturnNextTwoCoordinatesFromExpectedDirection)
{
    const MazePoint starting_pipe(maze.find_starting_point());
    const auto foundNeighbors = maze.find_next_neighbors(starting_pipe);

    auto current_point_in_second_direction =
        maze.go_forward(foundNeighbors.second, starting_pipe);
    ASSERT_EQ(current_point_in_second_direction, MazePoint(3, 1));
    current_point_in_second_direction =
        maze.go_forward(current_point_in_second_direction, foundNeighbors.second);
    ASSERT_EQ(current_point_in_second_direction, MazePoint(3, 2));
}

TEST_F(PipeMazeTests, GivenBasicPipeMaze_WhenCountStepsToFarthestPoint_ShouldReturnNumberOfStepsEqualFour)
{
    auto steps_number = maze.count_steps_to_farthest_point();
    ASSERT_EQ(steps_number, 4);
}

TEST_F(PipeMazeExtendedTests, GivenExtendedPipeMaze_WhenCountStepsToFarthestPointFrom_ShouldReturnNumberOfStepsEqualEight)
{
    auto steps_number = maze_extended.count_steps_to_farthest_point();
    ASSERT_EQ(steps_number, 8);
}

TEST_F(PipeMazeExtendedTests, GivenMazeWithPipeLoop_WhenTransformToAttributedMaze_ExpectAdditionalAttributeToAccess)
{
    for(auto i = 0U; i < pipe_maze_extended.size(); ++i)
        for(auto j = 0U; j < pipe_maze_extended[i].size(); ++j)
        {
            constexpr auto expected_state = State::Undefined;
            const auto expected_pipe = pipe_maze_extended[i][j];

            ASSERT_EQ(maze_extended.check_state_at(MazePoint(i, j)), expected_state);
            ASSERT_EQ(maze_extended.check_pipe_at(MazePoint(i, j)), expected_pipe);
        }
}

TEST_F(PipeMazeExtendedTests, GivenMazeWithPipeLoop_WheMarkLoopTilesInAttributedMaze_ExpectTileWhichIsPartOfTheLoopHasStateSetToLoop)
{
    auto maze = maze_extended;
    maze.mark_loop_tiles_in_attributed_maze();

    ASSERT_EQ(maze.check_state_at(MazePoint(0, 3)), State::Loop);
    ASSERT_EQ(maze.check_state_at(MazePoint(0, 4)), State::Undefined);
    ASSERT_EQ(maze.check_state_at(MazePoint(4, 2)), State::Undefined);
}

using MazeScopeParams = std::tuple<MazePoint, bool>;

struct MazeScopeTests : public ::testing::TestWithParam<MazeScopeParams>
{
    const PipeMaze pipe_maze = {"-L|F7", "7S-7|", "L|7||", "-L-J|", "L|-JF"};
    const AttributedMaze maze{transform_to_attributed_maze(pipe_maze)};
};

TEST_P(MazeScopeTests, GivenMazeWithPipeLoop_WhenCheckIfMazePointIsInMaze_ExpectReturnTrueOrFalse)
{
    auto [maze_point, expected_result] = GetParam();
    ASSERT_EQ(maze.is_in_maze(maze_point), expected_result);
}

std::vector<MazeScopeParams> GenerateMazeScopeParams()
{
    return std::vector<MazeScopeParams>{{MazePoint{-1, 0}, false},
                                        {MazePoint{0, 0}, true},
                                        {MazePoint{2, 2}, true},
                                        {MazePoint{6, 0}, false}

    };
}

INSTANTIATE_TEST_SUITE_P(IsInMazeScope,
                         MazeScopeTests,
                         testing::ValuesIn(GenerateMazeScopeParams()));


TEST_P(MazeScopeTests, GivenMazePoint_WhenColorNeighborForPoint_ExpectColorEightPoint)
{
    // "- L | F 7",
    // "7 S - 7 |",
    // "L | 7 | |",
    //  "- L - J |",
    //  "L | -J F"};

    auto [color_top_left, color_top, color_top_right, color_right,
          color_down_right, color_down, color_down_left, color_left] = GetParam();

    const MazePoint starting_pipe(find_starting_point(pipe_maze));
    const auto foundNeighbors = find_next_neighbors(pipe_maze, starting_pipe);

    maze.color_neighbor(MazePoint{1, 1}, foundNeighbors.first);

    ASSERT_EQ(check_state_at(MazePoint{0, 0}), color_top_left);
    ASSERT_EQ(check_state_at(MazePoint{0, 1}), color_top);
    ASSERT_EQ(check_state_at(MazePoint{0, 2}), color_top_right);
    ASSERT_EQ(check_state_at(MazePoint{1, 2}), color_right);
    ASSERT_EQ(check_state_at(MazePoint{2, 2}), color_down_right);
    ASSERT_EQ(check_state_at(MazePoint{2, 1}), color_down);
    ASSERT_EQ(check_state_at(MazePoint{2, 0}), color_down_left);
    ASSERT_EQ(check_state_at(MazePoint{1, 0}), color_left);
}

using ColorTopLeft = MazePoint;
using ColorTop = MazePoint;
using ColorTopRight = MazePoint;
using ColorRight = MazePoint;
using ColorLeft = MazePoint;
using ColorDownRight = MazePoint;
using ColorDown = MazePoint;
using ColorDownLeft = MazePoint;
using MazeNeighborColorParams =
    std::tuple<ColorTopLeft, ColorTop, ColorTopRight, ColorRight, ColorDownRight, ColorDown, ColorDownLeft, ColorLeft>;

std::vector<MazeNeighborColorParams> GenerateMazeScopeParams()
{
    return std::vector<MazeNeighborColorParams>{
        {State::Red, State::Red, State::Red, State::Loop, State::Green,
         State::Loop, State::Red, State::Red},
    };
}

INSTANTIATE_TEST_SUITE_P(IsInMazeScope,
                         MazeScopeTests,
                         testing::ValuesIn(MazeNeighborColorParams()));
