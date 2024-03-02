#pragma once

#include "../../debug_features.hpp"
#include <map>
constexpr int number_of_cards = 5;

using HandOfCards = std::array<char, number_of_cards>;
using BeforeTransformToKey = HandOfCards;
using Key = int;
using CountedCards = std::map<char,int>;

CountedCards count_cards(const HandOfCards& hand);

bool hasFiveOfAKind(const HandOfCards& hand);
bool hasFourOfAKind(const HandOfCards& hand);
bool hasFullHouse(const HandOfCards& hand);
bool hasThreeOfAKind(const HandOfCards& hand);
bool hasTwoPairs(const HandOfCards& hand);

// int transform_to_key(HandOfCards hand);


