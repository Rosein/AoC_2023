#pragma once

#include <vector>
#include <string>
#include <optional>

using Coordinates = std::pair<int,int>;
using EngineSchematic = std::vector<std::string>;

bool is_number_adjacent_to_symbol(EngineSchematic engine_schematic, Coordinates begin_index, Coordinates end_index);

int extract_number(std::string engine_schematic_one_line);

int extract_number_when_symbol_is_adjacent(std::string engine_schematic_one_line);

std::optional<std::pair<Coordinates, Coordinates>> extract_next_number_indexes(EngineSchematic engine_schematic);
