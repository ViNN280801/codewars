#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <iterator>

/**
 * @brief Filters out all odd numebrs from the array
 * @tparam arr array to filter
 * @return New array with no odd elems
 */
template <typename T>
std::vector<T> get_even_numbers(const std::vector<T> &arr)
{
    // Checking that the type 'T' is integral
    if constexpr (std::is_integral_v<T>)
    {
        // Creating new array and copying all elems from orig array into it
        std::vector<T> result(std::cbegin(arr), std::cend(arr));

        // Erasing all odd elems from the copy
        result.erase(std::remove_if(std::begin(result), std::end(result), [result](auto const &el)
                                    { return el % 2; }),
                     std::cend(result));

        return result;
    }
}

int main()
{
    std::vector<int> v(get_even_numbers<int>({2, 4, 5, 6, 7, 8}));
    for (auto const &el : v)
        std::cout << el << ' ';
    std::endl(std::cout);

    return EXIT_SUCCESS;
}
