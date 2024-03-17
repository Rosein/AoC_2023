#include "haunted_wasteland.hpp"
#include <cassert>
#include <chrono>
#include <thread>
#include <iostream>

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

void go_through_desert_to_the_end(
    std::string start_position,
    std::string directions,
    const DesertPlan& desert_plan,
    const std::atomic_bool& is_end_condition_reached,
    std::mutex& mut,
    RecordedCounters& recorded_steps_after_meeting_XXZ)
{
    int step_counter{0};
    std::string current_place{start_position};
    auto it_dir = directions.begin();

    while(not is_end_condition_reached)
    {
        current_place = go_to_next_place(desert_plan, current_place, *it_dir);
        it_dir = std::next(it_dir) == directions.end() ? directions.begin() : std::next(it_dir);
        ++step_counter;

        if(current_place[2] == 'Z')
        {
            const std::lock_guard<std::mutex> lock(mut);
            recorded_steps_after_meeting_XXZ.push_back(step_counter);
        }
    }
}

std::optional<int> find_common_result_counter(const std::vector<RecordedCounters>& container_of_recorded_counters,
                                              std::vector<std::mutex>& mutexes)
{
    using Sizes = std::vector<int>;
    Sizes sizes{};
       using namespace std::chrono_literals;


     std::this_thread::sleep_for(1s);

    int r = 0;
    DEBUG_PRINT("Liczba wszystkich wektorow z counterami " <<  container_of_recorded_counters.size());
    for(const auto& recorded_counters : container_of_recorded_counters)
    {
        const std::lock_guard<std::mutex> lock(mutexes[r]);
        sizes.push_back(recorded_counters.size());
        ++r;
        DEBUG_PRINT("Wielkosc recorded counters nr " << r << " to " << sizes.back());
    }

    DEBUG_PRINT("Tworzymy mape zliczajaca");
    using CounterId = int;
    using NumberOfOccurances = int;
    std::map<CounterId, NumberOfOccurances> counters_occurances;

    for(int i = 0; i < sizes.size(); ++i)
    {
        const RecordedCounters& recorded_counters = container_of_recorded_counters.at(i);
        for(int j = 0; j < sizes[i]; ++j)
        {
            const CounterId& current_counter = recorded_counters.at(j);
            if(counters_occurances.contains(current_counter))
            {
                ++(counters_occurances[current_counter]);
            }
            else
            {
                counters_occurances[current_counter] = 1;
            }
        }
    }

    DEBUG_PRINT("Mapa zliczajaca stworzona");
    for(const auto& [counter, number_of_occurance] : counters_occurances)
    {
        if(number_of_occurance == container_of_recorded_counters.size())
        {
            return {counter};
        }
    }

    return std::nullopt;
}

void check_every_second_end_condition_is_reached_for_all_starting_positions(
        const std::vector<RecordedCounters>& container_of_recorded_counters,
        std::vector<std::mutex>& mutexes,
        std::atomic_bool& is_end_condition_reached,
        int& common_result_counter)
{
    using namespace std::chrono_literals;
    while(not is_end_condition_reached)
    {
        DEBUG_PRINT("Szukamy kandydata na wspolny counter");
        auto common_counter = find_common_result_counter(container_of_recorded_counters, mutexes);

        DEBUG_PRINT("Sprawdzamy czy mamy kandydata na wspolny counter");
        if(common_counter.has_value())
        {
            DEBUG_PRINT("Znaleźliśmy common counter");
            is_end_condition_reached = true;
            common_result_counter = common_counter.value();
        }
        else
        {
            DEBUG_PRINT("Nie znaleźliśmy i czekamy sekunde");
            std::this_thread::sleep_for(1ms);;
        }
    }
}