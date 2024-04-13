#include "path_helper/path_helper.hpp"
#include "scratchcards.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

void run_app(std::string filename)
{
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;
    long long total_sum{0};
    CardScratcher card_scratcher;
    while(std::getline(fs, line))
    {
        card_scratcher.execute_step_nr(extract_card_number(line),
                                       extract_winning_numbers(line),
                                       extract_scratched_numbers(line));
    }

    const auto total_cards = card_scratcher.get_card_amounts();

    for(const auto [key, value] : total_cards)
    {
        total_sum += value;
    }

    std::cout << total_sum << std::endl;

    fs.close();
}

int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_04/task_1/input"};
    run_app(filename);
    return 0;
}
