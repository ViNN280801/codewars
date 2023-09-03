#include <iostream>
#include <vector>

void print_table(std::vector<std::vector<int>> const &table)
{
    for (size_t row{}; row < table.size(); row++)
    {
        for (size_t col{}; col < table.size(); col++)
            std::cout << table.at(row).at(col) << ' ';
        std::endl(std::cout);
    }
}

/**
 * @brief Creates multiplication table of n x n size
 * @param n size of table (it's square)
 * @return Multiplication table n x n size
 */
std::vector<std::vector<int>> multiplication_table(int n)
{
    std::vector<std::vector<int>> table(n, std::vector<int>(n));

    // Filling first horizontal and vertical values of a multiplication table
    for (int i{}; i < n; i++)
        table.at(i).at(0) = table.at(0).at(i) = i + 1;

    // Filling remain elements
    for (int i{1}; i < n; i++)
        for (int j{1}; j < n; j++)
            table.at(i).at(j) = table.at(0).at(j) * table.at(i).at(0);

    return table;
}

int main()
{
    multiplication_table(10);

    return EXIT_SUCCESS;
}
