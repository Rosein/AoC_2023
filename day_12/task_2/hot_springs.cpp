#include "hot_springs.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <map>


std::map<std::pair<std::string, std::vector<int>>, long long unsigned> MEMO;

std::vector<int> extract_groups(std::string spring_condition_data)
{
    std::replace(spring_condition_data.begin(), spring_condition_data.end(),',', ' ');
    std::stringstream ss{spring_condition_data};
    std::string conditions;
    ss >> conditions;

    int broker{};
    std::vector<int> groups{};
    while(ss >> broker)
    {
        groups.push_back(broker);
    }

    return groups;
}

std::string extract_conditions(std::string spring_condition_data)
{
    std::stringstream ss{spring_condition_data};
    std::string conditions;
    ss >> conditions;
    return conditions;
}

int check_last_condition(std::string extracted_condition)
{
    if(extracted_condition.contains('#'))
    {
        return 0;
    }
    return 1;
}


long long unsigned arrange_spring(std::string extracted_condition, std::vector<int> groups)
{
    auto key = std::make_pair(extracted_condition, groups);
    if (MEMO.find(key) != MEMO.end())
    {
       return MEMO[key];
    }

    if(groups.empty())
    {
        return check_last_condition(extracted_condition);
    }

    long long unsigned size = groups[0];
    groups.erase(groups.begin());

    long long unsigned count = 0;

    for (int end = 0; end < extracted_condition.length(); ++end)
    {
        long long unsigned start = end - (size - 1);

        if (fits(extracted_condition, start, end)) {
            count += arrange_spring(extracted_condition.substr(end + 1), groups);
        }
    }
    MEMO[key] = count;
    return count;
}

bool fits(std::string extracted_condition, int start, int end)
{
    if(start - 1 < 0 or end + 1 >= extracted_condition.length())
    {
        return false;
    }
    if(extracted_condition[start - 1] == '#' or extracted_condition[end + 1] == '#')
    {
        return false;
    }
    if (extracted_condition.substr(0, start).contains('#'))
    {
        return false;
    }
    for (int i = start; i <= end; ++i)
    {
        if (extracted_condition[i] == '.') {
            return false;
        }
    }
    return true;
}

void unfold_data(std::string& extracted_condition, std::vector<int>& groups)
{
    auto extracted_condition_temp = extracted_condition;
    for(int i = 0; i < 4; ++i)
    {
        extracted_condition += "?" +extracted_condition_temp;
    }

    std::vector<int> temp = groups;
    for (int i = 0; i < 4; ++i)
    {
        groups.insert(groups.end(), temp.begin(), temp.end());
    }
}