#pragma once

#include <iomanip>
#include <list>
#include <map>
#include <set>
#include <sstream>

using CardNumber = int;
using Amount = long long int;

int count_guessed_numbers(const std::set<int>& winning_numbers, std::list<int> scratched_numbers);
std::set<int> extract_winning_numbers(std::string input);
std::list<int> extract_scratched_numbers(std::string input);
int extract_card_number(std::string input);

class CardScratcher
{
public:
    CardScratcher() = default;
    CardScratcher(const std::map<CardNumber, Amount>&);
    void execute_step_nr(CardNumber card_number,
                         const std::set<int>& winning_numbers,
                         std::list<int> scratched_numbers);
    std::map<CardNumber, Amount>& get_card_amounts();

private:
    std::map<CardNumber, Amount> card_amounts_;
};
