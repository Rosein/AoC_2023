#include "day_12/task_1/hot_springs.hpp"
#include "gtest/gtest.h"

struct HotSpringTest : ::testing::Test
{
    std::string spring_condition_data{"???.### 1,1,3"};
};

TEST_F(HotSpringTest, givenSpringConditionDataWhenExtractGroupsThenOnlyGroupsShouldBeSaved)
{
    //Given

    //When
    std::vector<int> extracted_spring_groups = extract_groups(spring_condition_data);

    //Then
    std::vector<int> expected_extracted_condition{1,1,3};
    ASSERT_EQ(extracted_spring_groups, expected_extracted_condition);
}

TEST_F(HotSpringTest, givenSpringConditionDataWhenExtractConditionThenOnlySpringDataShouldBeSaved)
{
    //Given

    //When
    std::string extracted_condition = extract_conditions(spring_condition_data);

    //Then
    std::string expected_extracted_condition{"???.###"};
    ASSERT_EQ(extracted_condition, expected_extracted_condition);
}

TEST_F(HotSpringTest, whenSpringHasObviousUnknownSpringCondidtionsThenShouldArrangeItWithProperValue)
{
    //Given
    std::string extracted_condition = extract_conditions(spring_condition_data);
    std::vector<int> extracted_spring_groups = extract_groups(spring_condition_data);

    //When
    std::string arranged_spring = arrange_spring(extracted_condition, extracted_spring_groups);

    //Then
    std::string expected_spring_arragement{"#.#.###"};
    ASSERT_EQ(expected_spring_arragement, arranged_spring);
}
