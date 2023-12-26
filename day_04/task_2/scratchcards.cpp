#include "scratchcards.hpp"
#include <cmath>
#include <iostream>

int count_guessed_numbers(const std::set<int>& winning_numbers, std::list<int> scratched_numbers)
{
    return scratched_numbers.remove_if(
                   [&winning_numbers](int number)
                   {
                        bool result_predicate = winning_numbers.contains(number);
                        
                        if(result_predicate)
                        {
                            std::cout << number << " " <<std::endl;
                        }

                        return result_predicate;
                   });
}

CardScratcher::CardScratcher(const std::map<CardNumber, Amount>& card_amounts) : card_amounts_(card_amounts)
{

}

std::map<CardNumber, Amount>& CardScratcher::get_card_amounts()
{
    return card_amounts_;
}

void CardScratcher::execute_step_nr(CardNumber card_number, const std::set<int>& winning_numbers, std::list<int> scratched_numbers)
{
    auto guessed_no = count_guessed_numbers(winning_numbers,scratched_numbers);

    if(card_amounts_.contains(card_number))
    {
        card_amounts_[card_number] += 1;
    }
    else
    {
        card_amounts_[card_number] = 1;
    }

    for(int i = 1; i <= guessed_no; i++)
    {
        if(card_amounts_.contains(card_number + i))
        {
            card_amounts_[card_number + i] += card_amounts_[card_number];
        }
        else
        {
            card_amounts_[card_number + i] = card_amounts_[card_number];
        }
    }
}

int extract_card_number(std::string input_data)
{
    std::stringstream ss{input_data};
    int card_number{};
    std::string to_ignore;
    ss >> to_ignore >> card_number;
    
    return card_number;
}

std::set<int> extract_winning_numbers(std::string input_data)
{

    std::stringstream ss{input_data};
    std::set<int> winning_numbers{};

    std::string to_ignore;
    ss >> to_ignore >> to_ignore;

    int winning_number{};
    while(ss >> winning_number)
    {
        winning_numbers.insert(winning_number);
    }

    return winning_numbers;
}

std::list<int> extract_scratched_numbers(std::string input_data)
{
    std::stringstream ss{input_data};
    std::list<int> scratched_numbers{};

    std::string to_ignore;
    do
    {
        ss >> to_ignore;
    } while(to_ignore != "|");

    int scratched_number{};
    while(ss >> scratched_number)
    {
        scratched_numbers.push_back(scratched_number);
    }

    return scratched_numbers;

}

