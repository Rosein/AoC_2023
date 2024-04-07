#include "boat_race.hpp"

bool is_loading_time_enough_to_win(long long int time, long long int distance, long long int loading_time)
{
    const long long int travelled_distance{(time - loading_time) * loading_time};
    return (travelled_distance > distance);
}

constexpr long long int kNoWinningLoadingTimeAtAll{-1};

long long int find_the_shortest_loading_time_to_win(long long int time, long long int distance)
{
    for(int candi_loading_time = 0; candi_loading_time < time; ++candi_loading_time)
    {
        if(is_loading_time_enough_to_win(time, distance, candi_loading_time))
        {
            return candi_loading_time;
        }
    }

    return kNoWinningLoadingTimeAtAll;
}

long long int find_the_longest_loading_time_to_win(long long int time, long long int distance)
{

    for(int candi_loading_time = time; candi_loading_time >= 0; --candi_loading_time)
    {
        if(is_loading_time_enough_to_win(time, distance, candi_loading_time))
        {
            return candi_loading_time;
        }
    }

    return kNoWinningLoadingTimeAtAll;
}

long long int count_winning_strategies(long long int time, long long int distance)
{
    return find_the_longest_loading_time_to_win(time, distance) -
        find_the_shortest_loading_time_to_win(time, distance) + 1;
}