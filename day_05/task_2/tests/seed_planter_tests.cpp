#include "day_05/task_2/seed_planter.hpp"
#include "gtest/gtest.h"


class MappingEvaluationParameterizedFixture
: public ::testing::TestWithParam<std::tuple<std::vector<MapSubcharacterisctic>, int, int>>
{
};

TEST_P(MappingEvaluationParameterizedFixture, ReturnExpectedValue)
{
    auto [one_type_to_second_type_map, one_type, expected_result] = GetParam();

    EXPECT_EQ(evaluate_value_of_mapping(one_type, one_type_to_second_type_map), expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    CalculatedEvaluationOfMap,
    MappingEvaluationParameterizedFixture,
    testing::Values(
        std::make_tuple(
            std::vector<MapSubcharacterisctic>{
                {50, 98, 2},
                {52, 50, 48},
            },
            79,
            81),
        std::make_tuple(std::vector<MapSubcharacterisctic>{{0, 15, 37}, {37, 52, 2}, {39, 0, 15}}, 81, 81),
        std::make_tuple(
            std::vector<MapSubcharacterisctic>{{49, 53, 8}, {0, 11, 42}, {42, 0, 7}, {57, 7, 4}},
            81,
            81),
        std::make_tuple(std::vector<MapSubcharacterisctic>{{88, 18, 7}, {18, 25, 70}}, 81, 74),
        std::make_tuple(std::vector<MapSubcharacterisctic>{{45, 77, 23}, {81, 45, 19}, {68, 64, 13}}, 74, 78),
        std::make_tuple(std::vector<MapSubcharacterisctic>{{45, 77, 23}, {81, 45, 19}, {68, 64, 13}},
                        74,
                        78)));


TEST(PreparationMapSubcharacteristicTest, ShouldCreateMapSubcharacteristicFromRawData)
{
    std::string raw_data = {
        "2122609492 2788703865 117293332 "
        "751770532 1940296486 410787026"};

    std::vector<MapSubcharacterisctic> expected_prepared_data = {
        {2122609492, 2788703865, 117293332}, {751770532, 1940296486, 410787026}};

    EXPECT_EQ(prepare_map_subcharacteristic(raw_data), expected_prepared_data);
}
