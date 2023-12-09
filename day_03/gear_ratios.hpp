#pragma once

#include <vector>
#include <string>
#include <optional>
#include <iomanip>

const bool kIsDebugOn = false;
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define DEBUG_PRINT(MSG) if(kIsDebugOn){ std::cout << "[" << std::right << std::setw(16) << __FILE__ << ":" << std::left << std::setw(4) << __LINE__ << "] " << BOLDWHITE << MSG << RESET << std::endl;}
#define DEBUG_PRINT_TESTNAME(MSG) DEBUG_PRINT(RESET << YELLOW << MSG)

using Coordinates = std::pair<int,int>;
using EngineSchematic = std::vector<std::string>;

bool is_number_adjacent_to_symbol(EngineSchematic engine_schematic, Coordinates begin_index, Coordinates end_index);

int extract_number(std::string engine_schematic_one_line);

int extract_number_when_symbol_is_adjacent(std::string engine_schematic_one_line);

class ExtractorOfNextNumberIndexes
{
public:
    std::optional<std::pair<Coordinates, Coordinates>> extract(EngineSchematic engine_schematic);
private:
    std::pair<Coordinates, Coordinates> next_indexes_{{0, 0}, {0, 0}};
};

class ExtractorOfNumberAdjacetToSymbol
{
public:
    int sum_part_numbers(EngineSchematic engine_schematic);
    std::optional<int> extract_next_part_number(EngineSchematic engine_schematic);
private:
    ExtractorOfNextNumberIndexes extractor_;
};
