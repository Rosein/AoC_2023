#include "mirage_maintenance.hpp"
#include <cassert>

void calcucale_one_step_difference(Report& report)
{
    assert(report.size() > 0U);

    for(std::size_t i = 0; i < report.size() - 1U; ++i)
    {
        report[i] = report[i + 1] - report[i];
    }
}