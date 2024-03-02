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

bool hasFourOfAKind(const HandOfCards& hand)
{
    std::map<char,int> counters{};
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

    for(auto const& [card_type, amount] : counters)
    {
        if(amount == four_of_a_kind){
            return true;
        }
    }
    return false;

}

// std::array<char, number_of_cards>;

// int transform_to_key(HandOfCards hand)
// {

// }
