#include "camel_cards.hpp"

#include <algorithm>
#include <numeric>
#include <map>
#include <cmath>
#include <cassert>


CountedCards count_cards_without_jokers(const HandOfCards& hand)
{
    CountedCards counters{};
    const char joker = 'J';

    for(auto const& card : hand)
    {
        if(card != joker)
        {
            if(counters.contains(card))
            {
                counters[card]++;
            } else
            {
                counters[card] = 1;
            }
        }
    }

    return counters;
}

bool has_five_of_a_kind(const HandOfCards& hand)
{
    return count_cards_without_jokers(hand).size() == 1 or count_cards_without_jokers(hand).size() == 0;
}

bool is_expected_counter(const CountedCards& counters, const int expected_amount)
{
    for(auto const& [card_type, amount] : counters)
    {
        // DEBUG_PRINT(card_type << " " << amount)
        if(amount == expected_amount)
        {
            return true;
        }
    }

    return false;
}

bool has_four_of_a_kind(const CountedCards& counters_without_jokers)
{
    const int expected_amount{4};
    return is_expected_counter(counters_without_jokers, expected_amount);
}

int sum_counters(const CountedCards& counters)
{
    int sum_of_other_cards{};
    for(auto& counter : counters)
    {
        sum_of_other_cards += counter.second;
    }
    return sum_of_other_cards;
}

bool has_four_of_a_kind(const HandOfCards& hand)
{
    auto counters = count_cards_without_jokers(hand);
    int number_of_jokers{5 - sum_counters(counters)};
    // DEBUG_PRINT(number_of_jokers);

    return (number_of_jokers == 0 && has_four_of_a_kind(counters)) or
           (number_of_jokers == 1 && has_three_of_a_kind(counters)) or
           (number_of_jokers == 2 && has_one_pair(counters)) or
           (number_of_jokers == 3 && !has_one_pair(counters));


}

bool has_full_house(const HandOfCards& hand)
{
    auto counters = count_cards_without_jokers(hand);

    auto is_full = [](const int& first_set_of_cards, const int& second_set_of_cards){
        return (first_set_of_cards == 2 && second_set_of_cards == 3)
                or (first_set_of_cards == 2 && second_set_of_cards == 2);
    };

    return counters.size() == 2 &&
           (is_full(counters.begin()->second, std::next(counters.begin())->second) or
            is_full(std::next(counters.begin())->second, counters.begin()->second));
}

bool has_one_pair(const CountedCards& counters_without_jokers)
{
    const int one_pair{2};
    bool found_already_pair{false};

    for(const auto& counter : counters_without_jokers)
    {
        if(counter.second == one_pair)
        {
            if(found_already_pair)
            {
                return false;
            }
            else
            {
                found_already_pair = true;
            }
        }
    }

    return found_already_pair;
}

bool has_two_pairs(const CountedCards& counters_without_jokers)
{
    const int one_pair{2};
    int founded_already_pairs{0};

    for(const auto& counter : counters_without_jokers)
    {
        if(counter.second == one_pair)
        {
            founded_already_pairs++;
        }
    }

    return founded_already_pairs == 2 ? true : false;
}

bool has_one_pair(const HandOfCards& hand)
{
    const auto counters_without_jokers = count_cards_without_jokers(hand);
    int number_of_jokers{5 - sum_counters(counters_without_jokers)};

    return number_of_jokers == 0 && has_one_pair(count_cards_without_jokers(hand)) ||
           number_of_jokers == 1 && !has_one_pair(count_cards_without_jokers(hand));
}

bool has_three_of_a_kind(const CountedCards& counters_without_jokers)
{
    const int expected_amount{3};
    return is_expected_counter(counters_without_jokers, expected_amount);
}

bool has_three_of_a_kind(const HandOfCards& hand)
{
    const auto counters_without_jokers = count_cards_without_jokers(hand);
    int number_of_jokers{5 - sum_counters(counters_without_jokers)};

    const int amount_of_cards = 3;
    const int amount_of_kinds = 3;
    return counters_without_jokers.size() == amount_of_kinds &&
          ((number_of_jokers == 0 && is_expected_counter(counters_without_jokers, amount_of_cards)) or
            number_of_jokers == 1 or
            number_of_jokers == 2);
}

bool has_two_pairs(const HandOfCards& hand)
{
    auto counters_without_jokers = count_cards_without_jokers(hand);

    int number_of_jokers{5 - sum_counters(counters_without_jokers)};
    const int amount_of_different_cards = 3;

    return counters_without_jokers.size() == amount_of_different_cards && (
           (number_of_jokers == 0 && has_two_pairs(counters_without_jokers))
    );
}

bool has_high_card(const HandOfCards& hand)
{
    auto counters = count_cards_without_jokers(hand);
    return counters.size() == 5;
}

int change_card_to_hex_digit(char card)
{
    if(std::isdigit(static_cast<unsigned char>(card))){
        return card - '0' - 1;
    }

    switch (card)
    {
    case 'T':
        return 9;
        break;
    case 'J':
        return 0;
        break;
    case 'Q':
        return 0xA;
        break;
    case 'K':
        return 0xB;
        break;
    case 'A':
        return 0xC;
        break;
    default:
        return -1;
        break;
    }
}

/* # Description of idea of convertion to hex_representation #

Cards mapping to hex digits
J23456789TQKA ← CARD
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

// int transform_to_key(const HandOfCards& hand)
// {
//     if(has_five_of_a_kind(hand))
//     {
//         return convert_to_hex_representation(hand) + 0x700000;
//     }
//     if(has_four_of_a_kind(hand))
//     {
//         return convert_to_hex_representation(hand) + 0x600000;
//     }
//     if(has_full_house(hand))
//     {
//         return convert_to_hex_representation(hand) + 0x500000;
//     }
//     if(has_three_of_a_kind(hand))
//     {
//         return convert_to_hex_representation(hand) + 0x400000;
//     }
//     if(has_two_pairs(hand))
//     {
//         return convert_to_hex_representation(hand) + 0x300000;
//     }
//     if(has_one_pair(hand))
//     {
//         return convert_to_hex_representation(hand) + 0x200000;
//     }
//     if(has_high_card(hand))
//     {
//         return convert_to_hex_representation(hand) + 0x100000;
//     }


//     return 0;
// }

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


// std::array<char, number_of_cards>;

// int transform_to_key(HandOfCards hand)
// {

// }

