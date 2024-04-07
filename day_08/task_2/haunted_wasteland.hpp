#pragma once

#include <map>
#include <string>
#include <utility>
#include <vector>

using DesertPlan = std::map<std::string, std::pair<std::string, std::string>>;
using StartPositions = std::vector<std::string>;

std::string go_to_next_place(const DesertPlan& plan,
                             const std::string& current_position,
                             const char direction);
int count_steps_to_ZZZ(const DesertPlan& desert_plan,
                       const std::string& begin_place,
                       const std::string& directions);
StartPositions found_starting_positions(const DesertPlan& desert_plan);

int count_steps_to_XXZ(const DesertPlan& desert_plan,
                       const StartPositions& start_positions,
                       const std::string& directions);