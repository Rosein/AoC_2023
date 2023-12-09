#include "gear_ratios.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

std::ostream& operator<<(std::ostream& os, Coordinates coordinates)
{
    os << "{" << coordinates.first << ", " << coordinates.second << "}";
    return os;
}

bool is_symbol(const char character)
{
    return !(character == '.' || std::isdigit(character));
}

bool are_indexes_in_scope(const EngineSchematic& engine_schematic, int first, int second)
{
    return 0 <= first && first < engine_schematic.size() &&
           0 <= second && second < engine_schematic[0].size();
}

bool is_number_adjacent_to_symbol(EngineSchematic engine_schematic, Coordinates begin_index, Coordinates end_index)
{

    if(begin_index.first < engine_schematic.size() -1)
    {
        for(int i = begin_index.second - 1; i <= end_index.second + 1; i++)
        {
            if(are_indexes_in_scope(engine_schematic, begin_index.first + 1, i) && 
               is_symbol(engine_schematic[begin_index.first + 1][i]))
            {
                return true;
            }
        }
    }

    if(are_indexes_in_scope(engine_schematic, end_index.first, end_index.second + 1) && 
       is_symbol(engine_schematic[end_index.first][end_index.second + 1]))
    {
        return true;
    }

    if(are_indexes_in_scope(engine_schematic, begin_index.first, begin_index.second - 1) && 
       is_symbol(engine_schematic[begin_index.first][begin_index.second - 1]))
    {
        return true;
    }

    for(int i = begin_index.second - 1; i <= end_index.second + 1; i++)
    {
        if(begin_index.first > 0){
            if(are_indexes_in_scope(engine_schematic, begin_index.first - 1, i) && 
               is_symbol(engine_schematic[begin_index.first - 1][i]))
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

std::optional<int> ExtractorOfNumberAdjacetToSymbol::extract_next_part_number(EngineSchematic engine_schematic)
{
    while(true)
    {
        auto number_to_check_indexes =  extractor_.extract(engine_schematic);
        if(!number_to_check_indexes.has_value())
        {
            DEBUG_PRINT("Didn't find any number");
            return std::nullopt;
        }

        if(is_number_adjacent_to_symbol(engine_schematic, number_to_check_indexes.value().first, number_to_check_indexes.value().second))
        {
            DEBUG_PRINT("")
            const std::string& row_with_number = engine_schematic[number_to_check_indexes.value().first.first];

            const int& index_of_first_digit_of_number = number_to_check_indexes.value().first.second;
            const int& index_of_first_last_of_number = number_to_check_indexes.value().second.second;
            const int part_number{std::stoi(row_with_number.substr(index_of_first_digit_of_number, index_of_first_last_of_number))};
            DEBUG_PRINT("Founded part number: " << part_number);
            return std::make_optional<int>(part_number);
        }
    }
}

int ExtractorOfNumberAdjacetToSymbol::sum_part_numbers(EngineSchematic engine_schematic)
{
    int total_sum_of_part_numbers{0};
    while(true)
    {
        auto candi_part_number = extract_next_part_number(engine_schematic);

        if(candi_part_number.has_value())
        {
            DEBUG_PRINT("candi_part_number: " << candi_part_number.value());
            total_sum_of_part_numbers += candi_part_number.value();
            DEBUG_PRINT("total_sum_of_part_numbers: " << total_sum_of_part_numbers);
        }
        else
        {
            DEBUG_PRINT("total_sum_of_part_numbers: " << total_sum_of_part_numbers);
            return total_sum_of_part_numbers;
        }

    }
}
