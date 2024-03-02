#pragma once

#include "../../debug_features.hpp"
#include <map>
constexpr int number_of_cards = 5;

using HandOfCards = std::array<char, number_of_cards>;
using BeforeTransformToKey = HandOfCards;
using Key = int;
using CountedCards = std::map<char,int>;

CountedCards count_cards(const HandOfCards& hand);

bool has_five_of_a_kind(const HandOfCards& hand);
bool has_four_of_a_kind(const HandOfCards& hand);
bool has_full_house(const HandOfCards& hand);
bool has_three_of_a_kind(const HandOfCards& hand);
bool has_two_pairs(const HandOfCards& hand);
bool has_one_pair(const HandOfCards& hand);

// int transform_to_key(HandOfCards hand);


