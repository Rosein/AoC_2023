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

int count_steps_to_XXZ(const DesertPlan& desert_plan, const StartPositions& start_positions, const std::string& directions)
{
    int counter_of_steps{0};
    std::vector<std::string> current_places{start_positions};
    auto it_dir = directions.begin();
    auto is_third_Z = [](const auto& str){return str.at(2) == 'Z';};
    do {
        for(int i = 0; i < start_positions.size(); i++)
        {
            current_places[i] = go_to_next_place(desert_plan, current_places[i], *it_dir);
        }

        counter_of_steps++;
        it_dir = std::next(it_dir) == directions.end() ? directions.begin() : std::next(it_dir);
    } while(not std::all_of(current_places.begin(), current_places.end(), is_third_Z));


    return counter_of_steps;
}


StartPositions found_starting_positions(const DesertPlan& desert_plan)
{
    StartPositions start_positions;
    for(auto [key, value] : desert_plan)
    {
        if(key[2] == 'A')
        {
            start_positions.push_back(key);
        }
    }
    return start_positions;
}
