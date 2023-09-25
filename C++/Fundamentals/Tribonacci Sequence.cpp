#include <iostream>
#include <vector>

/**
 * @brief Calculates 'n' elements from Tribonacci sequence by passes sequence
 * @param signature sequence of integer elements
 * @param n count of elements in the result sequence
 * @return Tribonacci sequence of 'n' size started with 'signature' elements
 */
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    // Checking bounds
    if (signature.empty() || signature.size() < 3ul)
        return {};

    // Checking if 'n' is less ore equals than size of the passed sequence -> resizing initial sequence
    if (static_cast<size_t>(n) <= signature.size())
        signature.resize(n);

    // Getting new values from Tribonacci sequence
    for (int i{3ul}; i < n; i++)
        signature.emplace_back(signature.at(i - 1) + signature.at(i - 2) + signature.at(i - 3));

    return signature;
}

void printIntVec(std::vector<int> const &vec)
{
    for (auto const &el : vec)
        std::cout << el << ' ';
    std::endl(std::cout);
}

int main()
{
    printIntVec(tribonacci({1, 2, 3}, 10));
    printIntVec(tribonacci({1, 2, 3}, 2));
    printIntVec(tribonacci({1, 0, 0}, 10));
    printIntVec(tribonacci({0, 1, 1}, 10));

    return EXIT_SUCCESS;
}
