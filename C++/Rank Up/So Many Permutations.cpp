#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>

/**
 * @brief Gathering all permutations to array
 * @param s string
 * @return Vector that contains all permutations of string 's'
 */
std::vector<std::string> permutations(std::string s)
{
    // Checking of string
    if (s.empty())
        return {""};

    // Initializing unordered set to avoid repeats between permutations
    std::unordered_set<std::string> perms;

    // Sorting copy of the string to create permutations
    std::sort(std::begin(s), std::end(s));

    do
    {
        // Adding next permutation
        perms.insert(s);

        // Checking condition after inserting
    } while (std::next_permutation(std::begin(s), std::end(s)));

    // Returning result as a vector from unordered set
    return std::vector<std::string>(std::cbegin(perms), std::cend(perms));
}

/**
 * @brief Gathering all permutations to array
 * @param s string
 * @return Vector that contains all permutations of string 's'
 */
std::vector<std::string> stringPermutations(std::string s)
{
    // Checking of string
    if (s.empty())
        return {""};

    std::vector<std::string> perms;

    // Sorting copy of the string to create permutations
    std::sort(std::begin(s), std::end(s));

    do
    {
        // Adding next permutation
        perms.push_back(s);

        // Checking condition after inserting
    } while (std::next_permutation(std::begin(s), std::end(s)));

    // Returning result as a vector from unordered set
    return perms;
}

void printStringVec(std::vector<std::string> const &v)
{
    for (auto const &s : v)
        std::cout << s << ' ';
    std::endl(std::cout);
}

int main()
{
    printStringVec(permutations(""));
    printStringVec(permutations("a"));
    printStringVec(permutations("ab"));
    printStringVec(permutations("abc"));
    printStringVec(permutations("aabb"));
    printStringVec(permutations("aa"));

    return EXIT_SUCCESS;
}
