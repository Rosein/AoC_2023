#pragma once

#include "../../debug_features.hpp"

#include <array>
#include <atomic>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <mutex>
#include <optional>

using DesertPlan = std::map<std::string,std::pair<std::string, std::string>>;
using StartPositions = std::vector<std::string>;
using RecordedCounters = std::vector<int>;

std::string go_to_next_place(const DesertPlan& plan, const std::string& current_position, const char direction);
int count_steps_to_ZZZ(const DesertPlan& desert_plan, const std::string& begin_place, const std::string& directions);
StartPositions found_starting_positions(const DesertPlan& desert_plan);

int count_steps_to_XXZ(const DesertPlan& desert_plan, const StartPositions& start_positions, const std::string& directions);
void go_through_desert_to_the_end(
    std::string start_position,
    std::string directions,
    const DesertPlan& desert_plan,
    const std::atomic_bool& is_end_condition_reached,
    std::mutex& m,
    RecordedCounters& recorded_steps_after_meeting_XXZ);

void check_every_second_end_condition_is_reached_for_all_starting_positions(
        const std::vector<RecordedCounters>& container_of_recorded_counters,
        std::vector<std::mutex>& mutexes,
        std::atomic_bool& is_end_condition_reached,
        int& common_result_counter);

std::optional<int> find_common_result_counter(const std::vector<RecordedCounters>& container_of_recorded_counters,
                                              std::vector<std::mutex>& mutexes);
