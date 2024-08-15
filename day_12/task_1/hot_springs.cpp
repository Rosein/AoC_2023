#include "hot_springs.hpp"
#include <sstream>
#include <algorithm>

std::vector<int> extract_groups(std::string spring_condition_data)
{
    std::replace(spring_condition_data.begin(), spring_condition_data.end(),',', ' ');
    std::stringstream ss{spring_condition_data};
    std::string conditions;
    std::vector<int> groups(3);
    ss >> conditions >> groups[0] >> groups[1] >> groups[2];
    return groups;
}


std::string extract_conditions(std::string spring_condition_data)
{
    std::stringstream ss{spring_condition_data};
    std::string conditions;
    ss >> conditions;
    return conditions;
}

std::string arrange_spring(std::string extracted_condition, std::vector<int> extracted_spring_groups)
{
    std::size_t current_group = 0U;
    for(std::size_t i = 0U; i < extracted_condition.size(); ++i)
    {
        while(extracted_condition[i] == '?')
        {
            if(extracted_spring_groups[current_group] > 0)
            {
                extracted_condition[i] = '#';
                --(extracted_spring_groups[current_group]);
                ++i;

                if(extracted_spring_groups[current_group] == 0 && extracted_condition[i] == '?')
                {
                    extracted_condition[i] = '.';
                    ++current_group;
                    ++i;
                }
            }
        }
    }
    return extracted_condition;
}
