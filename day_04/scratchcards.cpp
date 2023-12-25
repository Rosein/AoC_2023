#include "scratchcards.hpp"

int count_guessed_numbers(const std::set<int>& winning_numbers, std::list<int> scratched_numbers)
{
    return scratched_numbers.remove_if(
                   [&winning_numbers](int number)
                   {
                        return winning_numbers.contains(number);
                   });
}