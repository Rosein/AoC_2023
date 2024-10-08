#include "day_12/task_2/hot_springs.hpp"
#include "gtest/gtest.h"
#include <tuple>

struct HotSpringTest : ::testing::Test
{
    std::string spring_condition_data{"???.### 1,1,3"};
};

// TEST_F(HotSpringTest, givenSpringConditionDataWhenExtractGroupsThenOnlyGroupsShouldBeSaved)
// {
//     //Given

//     //When
//     std::vector<int> extracted_spring_groups = extract_groups(spring_condition_data);

//     //Then
//     std::vector<int> expected_extracted_condition{1,1,3};
//     ASSERT_EQ(extracted_spring_groups, expected_extracted_condition);
// }

// TEST_F(HotSpringTest, givenSpringConditionDataWhenExtractConditionThenOnlySpringDataShouldBeSaved)
// {
//     //Given

//     //When
//     std::string extracted_condition = extract_conditions(spring_condition_data);

//     //Then
//     std::string expected_extracted_condition{".???.###."};
//     ASSERT_EQ(extracted_condition, expected_extracted_condition);
// }

// TEST_F(HotSpringTest, checkLastConditionsWhenHashIsInSubstringThenReturnZero)
// {
//     ASSERT_EQ(check_last_condition("#."), 0);
//     ASSERT_EQ(check_last_condition(".#."), 0);
// }

// TEST_F(HotSpringTest, checkLastConditionsWhenHashIsNotInSubstringThenReturnOne)
// {
//     ASSERT_EQ(check_last_condition(".."), 1);
//     ASSERT_EQ(check_last_condition(".?"), 1);
// }

// using ArrangeSpringParams = std::tuple<std::string, int>;

// struct ArrangeSpringTest : ::testing::TestWithParam<ArrangeSpringParams>
// {
// };

// std::vector<ArrangeSpringParams> GenerateArrangeSpringParams()
// {
//     return {
//         {"???.### 1,1,3", 1},
//         {"???.### ", 0},
//         {".??..??...?##. 1,1,3", 4},
//         {"????.######..#####. 1,6,5", 4},
//         {"?###???????? 3,2,1", 10},
//         {"?#?#?#?#?#?#?#? 1,3,1,6", 1}
//         };
// }

// TEST_P(ArrangeSpringTest, whenSpringHasObviousUnknownSpringCondidtionsThenShouldArrangeItWithProperValue)
// {
//     //Given
//     auto [spring_condition_data, expected_spring_arragement] = GetParam();
//     std::string extracted_condition = extract_conditions(spring_condition_data);
//     std::vector<int> extracted_spring_groups = extract_groups(spring_condition_data);

//     //When
//     int arranged_spring = arrange_spring(extracted_condition, extracted_spring_groups);

//     //Then
//     ASSERT_EQ(expected_spring_arragement, arranged_spring);
// }

// INSTANTIATE_TEST_SUITE_P(OneArragementSpringTest, ArrangeSpringTest, testing::ValuesIn(GenerateArrangeSpringParams()));


// TEST_F(HotSpringTest, fitsOutOfBoundsForStart)
// {
//     ASSERT_FALSE(fits(".????#.", -1, 2));
// }

// TEST_F(HotSpringTest, fitsOutOfBoundsForEnd)
// {
//     ASSERT_FALSE(fits(".????#.", 1, 6));
// }

// TEST_F(HotSpringTest, fitsIfSegmentIsNotSurroundedByNonHashChars)
// {
//     ASSERT_FALSE(fits(".????#.", 1,4));
// }

// TEST_F(HotSpringTest, fitsIfSegmentIsSurroundedByNonHashChars)
// {
//     ASSERT_TRUE(fits(".????..", 1,3));
// }

// TEST_F(HotSpringTest, fitsIfSegmentIsSkippingHashCharsThenReturnFalse)
// {
//     ASSERT_FALSE(fits(".#????.", 2,3));
// }

// TEST_F(HotSpringTest, fitsIfSegmentIsNotSkippingHashCharsThenReturnTrue)
// {
//     ASSERT_TRUE(fits(".?????.", 2,3));
// }

// TEST_F(HotSpringTest, fitsIfSegmentIsNotPossible)
// {
//     ASSERT_FALSE(fits(".???.?.", 3,5));
// }

// TEST_F(HotSpringTest, fitsIfSegmentIsPossible)
// {
//     ASSERT_TRUE(fits(".???##.", 3,5));
// }

TEST_F(HotSpringTest, unfoldSprings)
{
    std::string springs = ".#";
    std::vector<int> groups{1};
    std::vector<int> unfolded_groups{1,1,1,1,1};
    unfold(springs, groups);

    ASSERT_EQ(springs, ".#?.#?.#?.#?.#");
    ASSERT_EQ(groups, unfolded_groups);
}

TEST_F(HotSpringTest, unfoldSprings2)
{
    std::string springs = "???.###";
    std::vector<int> groups{1,1,3};
    std::vector<int> unfolded_groups{1,1,3,1,1,3,1,1,3,1,1,3,1,1,3};
    unfold(springs, groups);

    ASSERT_EQ(springs, "???.###????.###????.###????.###????.###");
    ASSERT_EQ(groups, unfolded_groups);
}