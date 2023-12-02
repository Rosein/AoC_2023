#include "scan_edge_digits.hpp"
#include <cctype>
#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>

const std::vector<std::string> wordy_digits {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

namespace v1
{
int merge_edge_digits(const std::string& input)
{
    int first_digit{0};
    int last_digit{0};
    int counter{0};

    for(const auto& el : input)
    {
        if(std::isdigit(el) && counter == 0)
        {
            first_digit = el - '0';
            counter++;
        } 
        else if(std::isdigit(el) && counter != 0)
        {
            last_digit = el - '0';
            counter++;
        }
    }

    return (counter == 1 ? first_digit : last_digit) +
           first_digit * 10;
}
}

namespace v2
{

int convert_verbal_digit_to_int(std::string verbal_digit)
{
    bool founded = false;
    int counter{1};
    for(auto& wordy_digit : wordy_digits)
    {
        if(verbal_digit == wordy_digit)
        {
            founded = true;
            break;
        }
        ++counter;
    }

    if(!founded)
    {
        throw std::runtime_error{"Wrong input in convert_verbal_digit_to_int()"};
    }

    return counter;
}

std::map<int, std::string> make_positions_wordy(const std::string& input)
{
    std::map<int, std::string> positions_wordy;
    for(auto& digit : wordy_digits)
    {
        auto founded_position = input.find(digit);
        if(founded_position != input.npos)
        {
            positions_wordy[founded_position] =  digit;
        }
    }

    for(auto& digit : wordy_digits)
    {
        auto founded_position = input.rfind(digit);
        if(founded_position != input.npos)
        {
            positions_wordy[founded_position] =  digit;
        }
    }

    return positions_wordy;
}

int merge_edge_digits(const std::string& input)
{
    int first_digit{0};
    int position_of_first_digit{0};
    int position_of_last_digit{0};
    int last_digit{0};
    int counter{0};

    for(auto it = input.begin(); it != input.end(); ++it)
    {
        if(std::isdigit(*it) && counter == 0)
        {
            first_digit = *it - '0';
            position_of_first_digit = std::distance(input.begin(), it);
            counter++;
        } 
        else if(std::isdigit(*it) && counter != 0)
        {
            last_digit = *it - '0';
            position_of_last_digit = std::distance(input.begin(), it);
            counter++;
        }
    }

    std::map<int, std::string> positions_wordy = make_positions_wordy(input);

    int first_word_digit{0};
    int position_of_first_word_digit{0};
    int last_word_digit{0};
    int position_of_last_word_digit{0};

    if(positions_wordy.empty())
    {
        return (counter == 1 ? first_digit : last_digit) +
                first_digit * 10;
    } 
    else if (positions_wordy.size() == 1)
    {
        first_word_digit = convert_verbal_digit_to_int(positions_wordy.begin()->second);
        position_of_first_word_digit = positions_wordy.begin()->first;
        last_word_digit = first_word_digit;
        position_of_last_word_digit = position_of_first_word_digit;
    } 
    else
    {
        first_word_digit = convert_verbal_digit_to_int(positions_wordy.begin()->second);
        position_of_first_word_digit = positions_wordy.begin()->first;
        last_word_digit = convert_verbal_digit_to_int(positions_wordy.rbegin()->second);;
        position_of_last_word_digit = positions_wordy.rbegin()->first;
    }

    int final_first_digit{0};
    int final_last_digit{0};

    if(counter == 0)
    {
        final_first_digit = first_word_digit;
        final_last_digit = last_word_digit;
    } 
    else if(counter == 1)
    {
        if(position_of_first_digit < position_of_first_word_digit)
        {
            final_first_digit = first_digit;
        }
        else
        {
            final_first_digit = first_word_digit;
        }


        if(position_of_first_digit < position_of_last_word_digit)
        {
            final_last_digit = last_word_digit;
        }
        else
        {
            final_last_digit = first_digit;
        }
    }
    else if(counter > 1)
    {
        if(position_of_first_digit < position_of_first_word_digit)
        {
            final_first_digit = first_digit;
        }
        else
        {
            final_first_digit = first_word_digit;
        }

        if(position_of_last_digit < position_of_last_word_digit)
        {
            final_last_digit = last_word_digit;
        }
        else
        {
            final_last_digit = last_digit;
        }
    }


    return final_first_digit * 10 + final_last_digit;
}
}
