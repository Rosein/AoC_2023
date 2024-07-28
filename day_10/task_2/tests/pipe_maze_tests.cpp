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
            const auto expected_tile = pipe_maze_extended[i][j];

            ASSERT_EQ(maze_extended.check_state_at(MazePoint(i, j)), expected_state);
            ASSERT_EQ(maze_extended.check_tile_at(MazePoint(i, j)), expected_tile);
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

using ColorTopLeft = State;
using ColorTop = State;
using ColorTopRight = State;
using ColorRight = State;
using ColorLeft = State;
using ColorDownRight = State;
using ColorDown = State;
using ColorDownLeft = State;
using MazeNeighborColorParams =
    std::tuple<ColorTopLeft, ColorTop, ColorTopRight, ColorRight, ColorDownRight, ColorDown, ColorDownLeft, ColorLeft>;

std::vector<MazeNeighborColorParams> GenerateMazeColoredScopeParams()
{
    return std::vector<MazeNeighborColorParams>{
        {State::LeftColor, State::LeftColor, State::LeftColor, State::Loop,
         State::RightColor, State::Loop, State::LeftColor, State::LeftColor}};
}

struct MazeColorTests : public ::testing::TestWithParam<MazeNeighborColorParams>
{
    const PipeMaze pipe_maze = {"-L|F7", "7S-7|", "L|7||", "-L-J|", "L|-JF"};
    AttributedMaze maze{transform_to_attributed_maze(pipe_maze)};
};

TEST_P(MazeColorTests, GivenMazePoint_WhenColorNeighborForPoint_ExpectColorEightPoint)
{
    // "- L | F 7",
    // "7 S - 7 |",
    // "L | 7 | |",
    //  "- L - J |",
    //  "L | -J F"};

    auto params = GetParam();

    auto color_top_left = std::get<0>(params);
    auto color_top = std::get<1>(params);
    auto color_top_right = std::get<2>(params);
    auto color_right = std::get<3>(params);
    auto color_down_right = std::get<4>(params);
    auto color_down = std::get<5>(params);
    auto color_down_left = std::get<6>(params);
    auto color_left = std::get<7>(params);

    MazePoint starting_pipe(maze.find_starting_point());
    maze.mark_loop_tiles_in_attributed_maze();
    const auto foundNeighbors = maze.find_next_neighbors(starting_pipe);
    maze.color_neighbor(MazePoint{1, 1}, foundNeighbors.first);
    ASSERT_EQ(maze.check_state_at(MazePoint{0, 0}), color_top_left);
    ASSERT_EQ(maze.check_state_at(MazePoint{0, 1}), color_top);
    ASSERT_EQ(maze.check_state_at(MazePoint{0, 2}), color_top_right);
    ASSERT_EQ(maze.check_state_at(MazePoint{1, 2}), color_right);
    ASSERT_EQ(maze.check_state_at(MazePoint{2, 2}), color_down_right);
    ASSERT_EQ(maze.check_state_at(MazePoint{2, 1}), color_down);
    ASSERT_EQ(maze.check_state_at(MazePoint{2, 0}), color_down_left);
    ASSERT_EQ(maze.check_state_at(MazePoint{1, 0}), color_left);
}

INSTANTIATE_TEST_SUITE_P(IsColoredWell,
                         MazeColorTests,
                         testing::ValuesIn(GenerateMazeColoredScopeParams()));


// @test to verify differentiating between enclosed and open tiles
//
// Used pipe maze:
// ...........
// .S-------7.
// .|F-----7|.
// .||.....||.
// .||.....||.
// .|L-7.F-J|.
// .|..|.|..|.
// .L--J.L--J.
// ...........
//
TEST(AttributedMazeTest, GivenAttributedMazeWithMarkedLoop_WhenCalculateEnclosedTiles_ThenReturnFour)
{
    // Given
    PipeMaze pipe_maze = {
        "...........",
        ".S-------7.",
        ".|F-----7|.",
        ".||.....||.",
        ".||.....||.",
        ".|L-7.F-J|.",
        ".|..|.|..|.",
        ".L--J.L--J.",
        "...........",
    };
    AttributedMaze maze(transform_to_attributed_maze(pipe_maze));
    maze.mark_loop_tiles_in_attributed_maze();

    // When
    const auto result = maze.count_enclosed_tiles();

    // Then
    EXPECT_EQ(result, 4);
}

TEST(AttributedMazeTest, GivenAttributedMazeWithMarkedLoopButLoopIsCloseToBoundaries_WhenCalculateEnclosedTiles_ThenReturnFour)
{
    // Given
    PipeMaze pipe_maze = {
        ".F--7F--7",
        ".|..||..|",
        ".|F-JL-7|",
        ".||....||",
        ".||....||",
        ".|L----J|",
        ".S------J",
    };
    
    AttributedMaze maze(transform_to_attributed_maze(pipe_maze));
    maze.mark_loop_tiles_in_attributed_maze();

    // When
    const auto result = maze.count_enclosed_tiles();

    // Then
    EXPECT_EQ(result, 4);
}



