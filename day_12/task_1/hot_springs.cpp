#include "hot_springs.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>

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
    conditions = "." + conditions + ".";
    return conditions;
}

int check_last_condition(std::string extracted_condition)
{
    if(extracted_condition.contains('#'))
    {
        std::cout <<  "found # in substr" << std::endl;
        return 0;
    }
    return 1;
}


int arrange_spring(std::string extracted_condition, std::vector<int> groups) {

    if(groups.empty())
    {
        std::cout <<  "empty groups" << std::endl;
        return check_last_condition(extracted_condition);
    }

    int size = groups[0];
    groups.erase(groups.begin());

    int count = 0;

    for (int end = 0; end < extracted_condition.length(); ++end) {
        int start = end - (size - 1);

        if (fits(extracted_condition, start, end)) {
            count += arrange_spring(extracted_condition.substr(end + 1), groups);
        }
    }
    return count;
}

bool fits(std::string extracted_condition, int start, int end)
{
    if(start - 1 < 0 or end + 1 >= extracted_condition.length())
    {
        std::cout << "out of bounds" << std::endl;
        return false;
    }
    if(extracted_condition[start - 1] == '#' or extracted_condition[end + 1] == '#')
    {
        std::cout << "surrounded by hash char" << std::endl;
        return false;
    }
    if (extracted_condition.substr(0, start).contains('#'))
    {
        std::cout << "skipping '#'" << std::endl;
        return false;
    }
    for (int i = start; i <= end; ++i) {
        if (extracted_condition[i] == '.') {
            std::cout << "segment is impossible" << std::endl;
            return false;
        }
    }
    std::cout << "segment is POSSIBLE" << std::endl;
    return true;
}