#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <functional>
#include <algorithm>

class StockList
{
protected:
    static bool isValInBounds(int const &val) { return val >= 0; }
    static bool isVecOfValsInBounds(std::vector<std::pair<char, int>> const &v)
    {
        for (auto const &el : v)
        {
            if (!isValInBounds(el.second))
                return false;
        }
        return true;
    }

    // Return vector of pairs that will store the only unique keys as a first value of pair
    // and sum of values of repeating keys as a second value of pair
    static std::vector<std::pair<char, int>> compressTheVectorOfPairs(std::vector<std::string> const &lstOfArt)
    {
        // Getting vector of all categories of books and it's count
        std::vector<std::pair<char, int>> vec{{'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0}, {'K', 0}, {'L', 0}, {'M', 0}, {'N', 0}, {'O', 0}, {'P', 0}, {'Q', 0}, {'R', 0}, {'S', 0}, {'T', 0}, {'U', 0}, {'V', 0}, {'W', 0}, {'X', 0}, {'Y', 0}, {'Z', 0}};
        for (auto const &art : lstOfArt)
            vec.push_back(std::make_pair(*std::cbegin(art), std::stoi(art.substr(art.find(' ')))));

        // If count of books are negative numbers -> return empty vector of pairs
        if (!isVecOfValsInBounds(vec))
            return std::vector<std::pair<char, int>>{{}};

        // Sorting this vector in ascending order
        std::sort(std::begin(vec), std::end(vec));

        // Creating map, that's counts the repeats of categories in 'vec' vector
        std::map<char, int> m;
        for (auto const &el : vec)
        {
            m[el.first]++;
        }

        // Creating new vector to return it as a result
        // This vector wouldn't store the repeats, only unique keys (pair.first = key)
        std::vector<std::pair<char, int>> newVec;

        // Iterating over the map
        for (auto const &el : m)
        {
            int sum{};
            // Iterating over the vector 'vec'
            for (size_t i{}; i < vec.size(); i++)
            {
                // If first letter of category of map is the same with
                // first letter of category of vector -> get previous and next indeces
                if (el.first == vec.at(i).first)
                {
                    size_t prevIdx{i}, nextIdx{prevIdx + static_cast<size_t>(m.at(vec.at(i).first))};
                    // Iterating in vector where keys are non-unique and sum their values
                    for (size_t j{prevIdx}; j < nextIdx; j++)
                        sum += vec.at(j).second;
                    // Then break the loop to avoid repeating
                    break;
                }
            }
            // Filling up the new vector 'newVec' with the only unique keys and sum
            // of their values
            newVec.push_back(std::make_pair<char, int>(std::forward<char>(const_cast<char &>(el.first)),
                                                       std::forward<int>(sum)));
        }
        return newVec;
    }

public:
    static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
    {
        std::vector<std::pair<char, int>> v{compressTheVectorOfPairs(lstOfArt)};

        // If the vector of pairs is empty -> return empty string
        if (v.empty() || lstOfArt.empty())
            return "";

        std::string str{};
        // Iterating over the specified categories of books
        for (size_t i{}; i < categories.size(); i++)
        {
            // Iterating over the vector that contains only unique keys with sum of values
            // with repeating keys (in past)
            for (auto const &el : v)
            {
                // Initializing 'el.first' char type as a string
                // and certain category that we don't have in a book store
                // (count of books of this category is null)
                std::string tmpCh{el.first}, tmp = "(" + categories.at(i) + " : 0) - ";

                // If categories are the same -> concatenating data in specified format of the task
                if (el.first == *std::cbegin(categories.at(i)))
                    str += "(" + tmpCh + " : " + std::to_string(el.second) + ") - ";

                // If there is no such category and 'str' not contains null category
                // (count of books of this category is null) -> add this category to 'str'
                if (std::find_if(std::begin(v), std::end(v), [&](auto const &el)
                                 { return el.first == *std::cbegin(categories.at(i)); }) == std::cend(v) &&
                    str.find(tmp) == std::string::npos)
                    str += "(" + categories.at(i) + " : 0) - ";
            }
        }

        // Truncating last ' ' and '-' symbols from string, then return it
        return str.substr(0UL, str.find_last_of('-') - 1UL);
    }

    static std::string stockSummaryClever(std::vector<std::string> &books, std::vector<std::string> &categories)
    {
        if (books.empty() || categories.empty())
            return "";

        int stocks['Z' + 1] = {0};
        for (const std::string &book : books)
        {
            std::size_t position = book.find_first_of(" ", 2, 1);
            stocks[book[0]] += std::atoi(book.data() + position);
        }

        std::string result = "";
        for (const std::string &category : categories)
        {
            result = result + (result.empty() ? "" : " - ") + "(" + category[0] + " : " +
                     std::to_string(stocks[category[0]]) + ")";
        }

        return result;
    }
};

int main()
{
    std::vector<std::string> art{"ABAR 200", "CDXE 500", "BKA 1021", "BT 100", "BKWR 250", "BTSQ 890", "DRTY 600", "DRBA 1000"};
    std::vector<std::string> cd{"A", "B"};

    std::cout << StockList::stockSummary(art, cd) << std::endl;
    std::cout << StockList::stockSummaryClever(art, cd) << std::endl;

    art = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    std::cout << StockList::stockSummary(art, cd) << std::endl;
    std::cout << StockList::stockSummaryClever(art, cd) << std::endl;

    art = {"BBAR 150", "CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600"};
    cd = {"A", "B", "C", "D"};
    std::cout << StockList::stockSummary(art, cd) << std::endl;
    std::cout << StockList::stockSummaryClever(art, cd) << std::endl;

    art = {"ROXANNE 102", "RHODODE 123", "BKWRKAA 125", "BTSQZFG 239", "DRTYMKH 060"};
    cd = {"B", "R", "D", "X"};
    std::cout << StockList::stockSummary(art, cd) << std::endl;
    std::cout << StockList::stockSummaryClever(art, cd) << std::endl;

    art = {};
    cd = {"B", "R", "D", "X"};
    std::cout << StockList::stockSummary(art, cd) << std::endl;
    std::cout << StockList::stockSummaryClever(art, cd) << std::endl;

    return EXIT_SUCCESS;
}