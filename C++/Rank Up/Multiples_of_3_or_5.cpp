// Task: If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
/* Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.
Additionally, if the number is negative, return 0 (for languages that do have them).
Note: If the number is a multiple of both 3 and 5, only count it once.
Courtesy of projecteuler.net (https://projecteuler.net/problem=1) */

#include <iostream>

// Returns the sum of all the multiples of 3 or 5 below the number passed in
int solution(int number)
{
    int sum{}, infimum{number};

    if (number > 0)
    {
        while (number > 0)
        {
            if (((number % 3 == 0) || (number % 5 == 0)) && (number < infimum))
            {
                sum += number;
            }
            number--;
        }
        return sum;
    }
    else
        return 0;
}

int main(int argc, char *argv[])
{
    // Showing result of work function 'solution'
    std::cout << solution(35) << std::endl;
    std::cout << solution(13) << std::endl;

    return EXIT_SUCCESS;
}