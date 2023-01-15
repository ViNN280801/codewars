// Task: Complete the solution so that it splits the string into pairs of two characters.
// If the string contains an odd number of characters then it should
// Replace the missing second character of the final pair with an underscore ('_').
// Examples:
// * 'abc' =>  ['ab', 'c_']
// * 'abcdef' => ['ab', 'cd', 'ef']

#include <iostream>
#include <string>
#include <vector>

// Splits the stsring into pairs of two characters
std::vector<std::string> solution(const std::string &s)
{
    std::string lowerRegister("_");
    std::string sCopy(s);

    if (sCopy.size() % 2 != 0)
    {
        sCopy += lowerRegister;
    }
    std::vector<std::string> splittedString{};

    std::string tmp{};

    for (size_t iter = 0; iter < sCopy.size(); iter++)
    {
        tmp.push_back(sCopy[iter]);
        tmp.push_back(sCopy[iter++ + 1]);
        splittedString.push_back(tmp);
        tmp.clear();
    }

    lowerRegister.clear();
    sCopy.clear();

    return splittedString;
}

int main(int argc, char *argv[])
{
    // Showing result of work function 'solution' in for_each loops
    for(const auto &characters : solution("7182eyihfj"))
    {
        std::cout << characters << '\t';
    }
    std::cout << std::endl;

    for(const auto &characters : solution("abc"))
    {
        std::cout << characters << '\t';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}