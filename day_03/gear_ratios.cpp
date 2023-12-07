#include "gear_ratios.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

std::ostream& operator<<(std::ostream& os, Coordinates coordinates)
{
    os << "{" << coordinates.first << ", " << coordinates.second << "}";
    return os;
}

bool is_number_adjacent_to_symbol(EngineSchematic engine_schematic, Coordinates begin_index, Coordinates end_index)
{

    // std::cout << "Begin idnex: {,} : "  <<  begin_index.first << " " << begin_index.second <<std::endl;
    // std::cout << "End idnex: {,} : "  <<  end_index.first << " " << end_index.second <<std::endl;
    const char kCheckedSymbol{'&'};

    if(begin_index.first < engine_schematic.size() -1 )
    {
        for(int i = begin_index.second - 1; i <= end_index.second + 1; i++)
        {
            if(engine_schematic[begin_index.first + 1][i] == kCheckedSymbol)
            {
                return true;
            }
        }
    }

    if(engine_schematic[end_index.first][end_index.second + 1] == kCheckedSymbol)
    {
        return true;
    }

    if(engine_schematic[begin_index.first][begin_index.second - 1] == kCheckedSymbol)
    {
        return true;
    }

    for(int i = begin_index.second - 1; i <= end_index.second + 1; i++)
    {
        if(begin_index.first > 0){
            if(engine_schematic[begin_index.first - 1][i] == kCheckedSymbol)
            {
                return true;
            }
        }
    }
    return false;
}

int find_nr_of_column_of_last_digit_in_sequence(const std::string& row, int begin_index_of_number)
{
    bool is_continous_digit_sequence = true;

    int i = begin_index_of_number;
    for(; i < row.size(); ++i)
    {
        if(!std::isdigit(row[i]))
        {
            is_continous_digit_sequence = false;
            break;
        }
    }

    return i - 1;
}

std::optional<std::pair<Coordinates, Coordinates>> ExtractorOfNextNumberIndexes::extract(EngineSchematic engine_schematic)
{

    for(auto row = next_indexes_.first.first; row < engine_schematic.size(); ++row )
    {
        for(auto character = next_indexes_.first.second; character < engine_schematic[row].size(); ++character)
        {
            if(std::isdigit(engine_schematic[row][character]))
            {
                next_indexes_.second.first = next_indexes_.first.first;
                next_indexes_.second.second = find_nr_of_column_of_last_digit_in_sequence(engine_schematic[row], next_indexes_.first.second);

                DEBUG_PRINT(next_indexes_.first << " " << next_indexes_.second);
                auto return_indexes = next_indexes_;

                next_indexes_.first = next_indexes_.second;
                if(next_indexes_.first.second + 1 != engine_schematic[row].size())
                {
                    next_indexes_.first.second++;
                }
                else
                {
                    next_indexes_.first.first++;
                    next_indexes_.first.second = 0;
                }

                return return_indexes;
            }

            next_indexes_.first.second++;
        }
        next_indexes_.first.first++;
        next_indexes_.first.second = 0;
    }

    return std::nullopt;
}

int ExtractorOfNumberAdjacetToSymbol::extract_next_part_number(EngineSchematic engine_schematic)
{
    bool is_symbol_founded = false;

    while(!is_symbol_founded)
    {
        auto number_to_check_indexes =  extractor_.extract(engine_schematic);

        if(!number_to_check_indexes.has_value())
        {
            return 0;
        }

        is_symbol_founded = is_number_adjacent_to_symbol(engine_schematic, number_to_check_indexes.value().first, number_to_check_indexes.value().second);
        if(is_symbol_founded)
        {
            std::string row_with_number = engine_schematic[number_to_check_indexes.value().first.first];

            return std::stoi(row_with_number.substr(number_to_check_indexes.value().first.second, number_to_check_indexes.value().second.second));
        }
    }

    return 0;
}
