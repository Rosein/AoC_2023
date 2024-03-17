#pragma once

#include <vector>
#include "../../debug_features.hpp"

using Report = std::vector<int>;

void calcucale_one_step_difference(Report& report, const int depth);
void calcucale_final_values(Report& report);
void calculate_extrapolated_values(Report& report);

