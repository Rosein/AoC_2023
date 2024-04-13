#include "camel_cards.hpp"
#include "debug_features/debug_features.hpp"
#include "path_helper/path_helper.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

void run_app(std::string filename)
{
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string hand;
    int bid;

    std::map<int, int> hand_of_cards{};

    while(fs >> hand >> bid)
    {
        HandOfCards cards = convert_string_hand_to_hand_type(hand);
        int key = transform_to_key(cards);
        hand_of_cards[key] = bid;
    }

    int sum{0};
    int rank{1};

    for(const auto& [key, value] : hand_of_cards)
    {
        sum += (value * rank);
        rank++;
    }
    std::cout << sum << std::endl;

    fs.close();
}


int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_07/task_1/input"};
    run_app(filename);
    return 0;
}
