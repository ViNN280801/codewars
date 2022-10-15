// Task: Implement the function unique_in_order which takes as argument a sequence and
// returns a list of items without any elements with the same value next to
// each other and preserving the original order of elements.

// For example:
// uniqueInOrder("AAAABBBCCDAABBB") == {'A', 'B', 'C', 'D', 'A', 'B'}
// uniqueInOrder("ABBCcAD")         == {'A', 'B', 'C', 'c', 'A', 'D'}
// uniqueInOrder([1,2,2,3,3])       == {1,2,3}

#include <iostream>
#include <string>
#include <vector>
#include <span>

// Removing consecutive same characters from some range
template <typename T>
void remove_same_elems(std::vector<T> &__range)
{
    for (auto it{std::cbegin(__range)}; it != std::cend(__range); ++it)
    {
        while (((it + 1) != std::cend(__range)) && (*it == *(it + 1)))
            __range.erase(it);
    }
}

// Filling vector with string characters
std::vector<char> fill_vec_with_string_elems(const std::string &__str)
{
    std::vector<char> result;

    for (const auto &ch : __str)
    {
        result.push_back(ch);
    }

    return result;
}

// Returns a list of items without any elements with the
// same value next to each other and preserving initial order
template <typename T>
std::vector<T> uniqueInOrder(const std::vector<T> &__iterable)
{
    std::vector<T> result_vec{__iterable};
    remove_same_elems(result_vec);
    return result_vec;
}

// Returns a list of items without any elements with the
// same value next to each other and preserving initial order
std::vector<char> uniqueInOrder(const std::string &__iterable)
{
    std::vector<char> vec;

    // Copying data from '__iterable' string to vector for removing same consecutive elements
    std::copy(std::begin(__iterable), std::end(__iterable), std::back_inserter(vec));
    remove_same_elems<char>(vec);

    // Composing string from vector of chars
    std::string str(std::begin(vec), std::end(vec));
    return fill_vec_with_string_elems(str);
}

template <typename T>
void print_range(std::span<const T> __range)
{
    for (const auto &el : __range)
    {
        std::cout << el << ' ';
    }
    endl(std::cout);
}

int main()
{
    std::vector<char> vec{uniqueInOrder("")};
    print_range<char>(vec);

    vec = uniqueInOrder("AA");
    print_range<char>(vec);

    vec = uniqueInOrder("A");
    print_range<char>(vec);

    vec = uniqueInOrder("AAAABBBCCDAABBB");
    print_range<char>(vec);

    vec = uniqueInOrder("AADD");
    print_range<char>(vec);

    vec = uniqueInOrder("AAD");
    print_range<char>(vec);

    vec = uniqueInOrder("ADD");
    print_range<char>(vec);

    vec = uniqueInOrder("ABBCcAD");
    print_range<char>(vec);

    std::vector<int> vec2{uniqueInOrder(std::vector<int>{1, 2, 3, 3})};
    print_range<int>(vec2);

    std::vector vec3{uniqueInOrder(std::vector<char>{'a', 'b', 'b'})};
    print_range<char>(vec3);

    return EXIT_SUCCESS;
}
