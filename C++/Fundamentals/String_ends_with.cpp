// Task: Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).

#include <iostream>
#include <string>

// Returns true if the first argument(string) passed in ends with the 2nd argument (also a string). 
bool solution(std::string const &str, std::string const &ending)
{
    return std::equal(ending.rbegin(), ending.rend(), str.rbegin());
}

int main(int argc, char *argv[])
{
    // Showing result of 'solution' function
    std::cout << solution("abc", "bc") << std::endl;
    std::cout << solution("abc", "d") << std::endl;

    return EXIT_SUCCESS;
}