#pragma once
#include <vector>
#include <string>

std::vector<int> extract_groups(std::string spring_condition_data);
std::string extract_conditions(std::string spring_condition_data);
long long unsigned arrange_spring(std::string extracted_condition, std::vector<int> extracted_spring_groups);
int check_last_condition(std::string extracted_condition);

bool fits(std::string extracted_condition, int start, int end);
void unfold_data(std::string& extracted_condition, std::vector<int>& groups);