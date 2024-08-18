#pragma once
#include <vector>
#include <string>

std::vector<int> extract_groups(std::string spring_condition_data);
std::string extract_conditions(std::string spring_condition_data);
std::string arrange_spring(std::string extracted_condition, std::vector<int> extracted_spring_groups);
