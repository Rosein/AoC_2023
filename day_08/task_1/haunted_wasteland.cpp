#include "haunted_wasteland.hpp"
#include <cassert>

std::string go_to_next_place(const DesertPlan& plan, const std::string& current_position, const char direction)
{
    assert(plan.contains(current_position));
    const auto& next_step_options = plan.at(current_position);

    return direction == 'L' ? next_step_options.first : next_step_options.second;
}


int count_steps_to_ZZZ(const DesertPlan& desert_plan, const std::string& begin_place, const std::string& directions)
{
    int counter_of_steps{0};
    std::string current_place{begin_place};
    auto it_dir = directions.begin();

    do {
        current_place = go_to_next_place(desert_plan, current_place, *it_dir);

        counter_of_steps++;
        it_dir = std::next(it_dir) == directions.end() ? directions.begin() : std::next(it_dir);
    } while(current_place != "ZZZ");



    return counter_of_steps;
}