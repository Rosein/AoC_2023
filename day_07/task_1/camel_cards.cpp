#include "camel_cards.hpp"

#include <algorithm>
#include <map>

bool hasFiveOfAKind(const HandOfCards& hand)
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

bool hasFourOfAKind(const HandOfCards& hand)
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

bool hasFullHouse(const HandOfCards& hand)
{
    auto counters = count_cards(hand);

    auto is_full = [](const int& two_cards, const int& three_cards){
        return two_cards == 2 && three_cards == 3;
    };

    return counters.size() == 2 && 
           (is_full(counters.begin()->second, std::next(counters.begin())->second) ||
            is_full(std::next(counters.begin())->second, counters.begin()->second));
}

bool hasThreeOfAKind(const HandOfCards& hand)
{
    auto counters = count_cards(hand);
    const int three_of_a_kind{3};

    return counters.size() == three_of_a_kind;
}

// std::array<char, number_of_cards>;

// int transform_to_key(HandOfCards hand)
// {

// }
