#pragma once

#include "../../debug_features.hpp"
constexpr int number_of_cards = 5;

using HandOfCards = std::array<char, number_of_cards>;
using BeforeTransformToKey = HandOfCards;
using Key = int;

bool hasFiveOfAKind(const HandOfCards& hand);
bool hasFourOfAKind(const HandOfCards& hand);

// int transform_to_key(HandOfCards hand);


