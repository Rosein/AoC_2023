#pragma once

#include "../../debug_features.hpp"
#include <tuple>
#include <vector>

using MapRange = long int;
using DestinationRangeStart = MapRange;
using SourceRangeStart = MapRange;
using RangeLenght = MapRange;


constexpr int kDestinationStart = 0;
constexpr int kSourceStart = 1;
constexpr int kRangeLenght = 2;

using MapSubcharacterisctic = std::tuple<DestinationRangeStart, SourceRangeStart, RangeLenght>;
using Map = std::vector<MapSubcharacterisctic>;

MapRange evaluate_value_of_mapping(MapRange seed, std::vector<MapSubcharacterisctic> seed_to_soil_map);
std::vector<MapSubcharacterisctic> prepare_map_subcharacteristic(std::string raw_map);
