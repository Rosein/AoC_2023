#include "camel_cards.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>

bool has_five_of_a_kind(const HandOfCards& hand)
{
    return std::all_of(std::begin(hand), std::end(hand),
                       [first_value = hand.front()](const auto& el)
                       { return first_value == el; });
}

CountedCards count_cards(const HandOfCards& hand)
{
    CountedCards counters{};

    for(auto const& card : hand)
    {
        if(counters.contains(card))
        {
            counters[card]++;
        }
        else
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

    auto is_full = [](const int& two_cards, const int& three_cards)
    { return two_cards == 2 && three_cards == 3; };

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

auto is_two_pairs =
    [](const int& first_type_of_card, const int& second_type_of_card, const int& third_type_of_card)
{
    return (first_type_of_card == 2 && second_type_of_card == 2 && third_type_of_card == 1) ||
        (first_type_of_card == 2 && second_type_of_card == 1 && third_type_of_card == 2) ||
        (first_type_of_card == 1 && second_type_of_card == 2 && third_type_of_card == 2);
};


bool has_three_of_a_kind(const HandOfCards& hand)
{
    auto counters = count_cards(hand);
    const int three_of_a_kind{3};

    return counters.size() == three_of_a_kind &&
        !is_two_pairs(counters.begin()->second, std::next(counters.begin())->second,
                      std::next(counters.begin(), 2)->second);
}

bool has_two_pairs(const HandOfCards& hand)
{
    auto counters = count_cards(hand);

    return counters.size() == 3 &&
        is_two_pairs(counters.begin()->second, std::next(counters.begin())->second,
                     std::next(counters.begin(), 2)->second);
}

bool has_high_card(const HandOfCards& hand)
{
    auto counters = count_cards(hand);
    return counters.size() == 5;
}

int change_card_to_hex_digit(char card)
{
    if(std::isdigit(static_cast<unsigned char>(card)))
    {
        return card - '0' - 2;
    }

    switch(card)
    {
    case 'T': return 8; break;
    case 'J': return 9; break;
    case 'Q': return 0xA; break;
    case 'K': return 0xB; break;
    case 'A': return 0xC; break;
    default: return -1; break;
    }
}

/* # Description of idea of convertion to hex_representation #

Cards mapping to hex digits
23456789TJQKA ← CARD
↓↓↓↓↓↓↓↓↓↓↓↓↓
0123456789ABC ← HEX

Example convertion of card hand into hex representation of card

       A23A4 ← HAND OF CARD
       ↓↓↓↓↓
0x10000C01C2 ← HEX representation of card */
int convert_to_hex_representation(const HandOfCards& hand)
{
    int sum{0};
    int exponent{4};
    for(const auto& card : hand)
    {
        sum += change_card_to_hex_digit(card) * std::pow(0x10, exponent);
        exponent--;
    }
    assert(exponent == -1);
    return sum;
}

int transform_to_key(const HandOfCards& hand)
{
    if(has_five_of_a_kind(hand))
    {
        return convert_to_hex_representation(hand) + 0x700000;
    }
    if(has_four_of_a_kind(hand))
    {
        return convert_to_hex_representation(hand) + 0x600000;
    }
    if(has_full_house(hand))
    {
        return convert_to_hex_representation(hand) + 0x500000;
    }
    if(has_three_of_a_kind(hand))
    {
        return convert_to_hex_representation(hand) + 0x400000;
    }
    if(has_two_pairs(hand))
    {
        return convert_to_hex_representation(hand) + 0x300000;
    }
    if(has_one_pair(hand))
    {
        return convert_to_hex_representation(hand) + 0x200000;
    }
    if(has_high_card(hand))
    {
        return convert_to_hex_representation(hand) + 0x100000;
    }


    return 0;
}

HandOfCards convert_string_hand_to_hand_type(std::string hand)
{
    HandOfCards converted_hand{};
    int card_no{0};
    for(const auto& card : hand)
    {
        converted_hand[card_no] = card;
        card_no++;
    }
    assert(card_no == 5);
    return converted_hand;
}

std::string convert_type_hand_to_string_hand(HandOfCards hand)
{
    std::string result;

    for(auto& el : hand)
    {
        result += el;
    }

    return result;
}