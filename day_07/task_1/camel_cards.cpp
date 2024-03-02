#include "camel_cards.hpp"

#include <algorithm>
#include <map>

bool has_five_of_a_kind(const HandOfCards& hand)
{
    return std::all_of(std::begin(hand), std::end(hand),
                       [first_value = hand.front()](const auto& el){
                        return first_value == el;
                      });
}

CountedCards count_cards(const HandOfCards& hand)
{
    CountedCards counters{};
    const int four_of_a_kind{4};

    for(auto const& card : hand)
    {
        if(counters.contains(card))
        {
            counters[card]++;
        } else
        {
            counters[card] = 1;
        }
    }

    return counters;
}

bool has_four_of_a_kind(const HandOfCards& hand)
{
    auto counters = count_cards(hand);
    const int four_of_a_kind{4};

    for(auto const& [card_type, amount] : counters)
    {
        if(amount == four_of_a_kind)
        {
            return true;
        }
    }

    return false;
}

bool has_full_house(const HandOfCards& hand)
{
    auto counters = count_cards(hand);

    auto is_full = [](const int& two_cards, const int& three_cards){
        return two_cards == 2 && three_cards == 3;
    };

    return counters.size() == 2 &&
           (is_full(counters.begin()->second, std::next(counters.begin())->second) ||
            is_full(std::next(counters.begin())->second, counters.begin()->second));
}

bool has_one_pair(const HandOfCards& hand)
{
    auto counters = count_cards(hand);
    const int one_pair{4};

    return counters.size() == one_pair;
}

auto is_two_pairs = [](const int& first_type_of_card, const int& second_type_of_card, const int& third_type_of_card){
        return first_type_of_card == 2 && second_type_of_card == 2 && third_type_of_card == 1 ||
               first_type_of_card == 2 && second_type_of_card == 1 && third_type_of_card == 2 ||
               first_type_of_card == 1 && second_type_of_card == 2 && third_type_of_card == 2;
    };


bool has_three_of_a_kind(const HandOfCards& hand)
{
    auto counters = count_cards(hand);
    const int three_of_a_kind{3};

    return counters.size() == three_of_a_kind && !is_two_pairs(counters.begin()->second, std::next(counters.begin())->second, std::next(counters.begin(), 2)->second);
}

bool has_two_pairs(const HandOfCards& hand)
{
    auto counters = count_cards(hand);

    return counters.size() == 3 &&
        is_two_pairs(counters.begin()->second, std::next(counters.begin())->second, std::next(counters.begin(), 2)->second);
}

bool has_high_card(const HandOfCards& hand)
{
    auto counters = count_cards(hand);
    return counters.size() == 5; 
}
// std::array<char, number_of_cards>;

// int transform_to_key(HandOfCards hand)
// {

// }
