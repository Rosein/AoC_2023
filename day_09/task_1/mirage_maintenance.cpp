#include "mirage_maintenance.hpp"
#include <cassert>
#include <algorithm>

void calcucale_one_step_difference(Report& report, const int depth)
{
    assert(report.size() > 0U);
    assert(report.size() > depth);

    auto value_to_save = report.front();
    for(std::size_t i = 0; i < report.size() - depth; ++i)
    {
        report[i] = report[i + 1] - report[i];
    }
    report[report.size() - depth] = value_to_save;
}

void calcucale_final_values(Report& report)
{
    bool are_zeroes_reached{false};
    for(int i = 1; i < report.size() && !are_zeroes_reached; ++i)
    {
        calcucale_one_step_difference(report, i);
        are_zeroes_reached = std::all_of(std::begin(report), std::prev(std::end(report), i), [](int value){return value == 0;});
    }
}

void calculate_extrapolated_values(Report& report)
{
    calcucale_final_values(report);

    for(int i = 1; i < report.size(); i++)
    {
        report[i] = report[i] - report[i - 1];
    }
}
