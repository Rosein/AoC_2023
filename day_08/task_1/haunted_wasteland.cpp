#include "haunted_wasteland.hpp"
#include <cassert>

std::string go_to_next_place(const DesertPlan& plan, const std::string& current_position, const char direction)
{
    assert(plan.contains(current_position));
    const auto& next_step_options = plan.at(current_position);

    return direction == 'L' ? next_step_options.first : next_step_options.second;
}


