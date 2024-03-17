#include "mirage_maintenance.hpp"
#include <cassert>

void calcucale_one_step_difference(Report& report, const int depth)
{
    assert(report.size() > 0U);
    assert(report.size() > depth);

    for(std::size_t i = 0; i < report.size() - depth; ++i)
    {
        report[i] = report[i + 1] - report[i];
    }
}