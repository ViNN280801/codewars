// Task: Given two arrays a and b write a function comp(a, b) (orcompSame(a, b)) that checks
// whether the two arrays have the "same" elements, with the same multiplicities (the
// multiplicity of a member is the number of times it appears). "Same" means, here, that
// the elements in b are the elements in a squared, regardless of the order.

// Examples:
// Valid arrays
// a = [121, 144, 19, 161, 19, 144, 19, 11]
// b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]

// comp(a, b) returns true because in b 121 is the square of 11,
// 14641 is the square of 121, 20736 the square of 144, 361 the square of 19,
// 25921 the square of 161, and so on. It gets obvious if we write b's elements in terms of squares:

// a = [121, 144, 19, 161, 19, 144, 19, 11]
// b = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]

// Invalid arrays
// If, for example, we change the first number to something else, comp is not returning true anymore:

// a = [121, 144, 19, 161, 19, 144, 19, 11]
// b = [132, 14641, 20736, 361, 25921, 361, 20736, 361]

// comp(a,b) returns false because in b 132 is not the square of any number of a.

// a = [121, 144, 19, 161, 19, 144, 19, 11]
// b = [121, 14641, 20736, 36100, 25921, 361, 20736, 361]

// comp(a,b) returns false because in b 36100 is not the square of any number of a.

// Remarks:
// a or b might be [] or {} (all languages except R, Shell).
// a or b might be nil or null or None or nothing (except in C++, COBOL, Crystal, D,
// Dart, Elixir, Fortran, F#, Haskell, Nim, OCaml, Pascal, Perl, PowerShell, Prolog,
// PureScript, R, Racket, Rust, Shell, Swift).

// If a or b are nil (or null or None, depending on the language),
// the problem doesn't make sense so return false.

// Note for C
// The two arrays have the same size (> 0) given as parameter in function comp.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Same
{
protected:
    static void replaceSameVecsWithNil(std::vector<int> &a, std::vector<int> &b) noexcept
    {
        for (size_t i{0UL}; i < b.size(); i++)
        {
            for (size_t j{0UL}; j < a.size(); j++)
            {
                if (a.at(j) * a.at(j) == b.at(i))
                {
                    b.at(i) = 0;
                    a.at(j) = 0;
                }
            }
        }
    }

    static void removeAllNilsFromVec(std::vector<int> &vec) noexcept
    {
        vec.erase(std::remove_if(std::begin(vec), std::end(vec), [](const auto &el)
                                 { return el == 0; }),
                  std::cend(vec));
    }

public:
    static bool comp(std::vector<int> &a, std::vector<int> &b) noexcept
    {
        // At first, we checking out if there in 'a' vector certain element, which
        // when multiplied by itself gives as a result element from 'b' vector
        for (const auto &b_el : b)
        {
            if (std::none_of(std::begin(a), std::end(a), [b_el](const auto &a_el)
                             { return a_el * a_el == b_el; }))
                return false;
        }

        // Replacing all used values with nil
        // "Used" means the values that were used when multiplying by themselves
        // and gave as a result the value from the vector 'b'
        replaceSameVecsWithNil(a, b);

        // Removing all used values
        removeAllNilsFromVec(a);
        removeAllNilsFromVec(b);

        // Requesting to remove unused capacity of vector
        a.shrink_to_fit();
        b.shrink_to_fit();

        // If in the result of manipulations above we had vectors with unequal
        // sizes of nondeleted elements in vectors are not the "same"
        // returning true
        if ((a.size() not_eq b.size()) or
            ((not a.empty() and not b.empty()) and (*(std::cbegin(a)) * (*std::cbegin(a)) not_eq *(std::cbegin(b)))))
            return false;
        return true;
    }

    static bool compSmart(std::vector<int> &a, std::vector<int> &b) noexcept
    {
        for (auto &v : a)
        {
            v = v * v;
        }

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        return a == b;
    }
};

int main()
{
    std::vector a{121, 144, 19, 161, 19, 144, 19, 11}, b{14641, 20736, 361, 25921, 361, 20736, 361, 121};
    std::cout << Same::comp(a, b) << std::endl;

    a = {121, 144, 19, 161, 19, 144, 19, 11};
    b = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
    std::cout << Same::comp(a, b) << std::endl;

    a = {};
    std::cout << Same::comp(a, b) << std::endl;

    a = {121, 144, 19, 161, 19, 144, 19, 11};
    b = {121, 14641, 20736, 36100, 25921, 361, 20736, 361};
    std::cout << Same::comp(a, b) << std::endl;

    a = {121, 144, 19, 161, 19, 144, 19};
    b = {121, 14641, 20736, 361, 25921, 361, 20736, 361};
    std::cout << Same::comp(a, b) << std::endl;

    a = {2, 2, 3};
    b = {4, 4, 9};
    std::cout << Same::comp(a, b) << std::endl;

    a = {2, 2, 3};
    b = {4, 9, 9};
    std::cout << Same::comp(a, b) << std::endl;

    a = {1440, 195, 191, 161, 144, 19, 11, -121};
    b = {2073600, 38025, 36481, 25921, 20736, 14641, 361, 121};
    std::cout << Same::comp(a, b) << std::endl;

    a = {494, 96, 694, 48, 25, 701, 704};
    b = {9216, 495616, 2304, 244036, 625, 491401, 481636};
    std::cout << Same::comp(a, b) << std::endl;

    std::cout << "\nSolution with smart func: " << std::endl;

    a = {121, 144, 19, 161, 19, 144, 19, 11};
    b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
    std::cout << Same::compSmart(a, b) << std::endl;

    a = {121, 144, 19, 161, 19, 144, 19, 11};
    b = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
    std::cout << Same::compSmart(a, b) << std::endl;

    a = {};
    std::cout << Same::compSmart(a, b) << std::endl;

    a = {121, 144, 19, 161, 19, 144, 19, 11};
    b = {121, 14641, 20736, 36100, 25921, 361, 20736, 361};
    std::cout << Same::compSmart(a, b) << std::endl;

    a = {121, 144, 19, 161, 19, 144, 19};
    b = {121, 14641, 20736, 361, 25921, 361, 20736, 361};
    std::cout << Same::compSmart(a, b) << std::endl;

    a = {2, 2, 3};
    b = {4, 4, 9};
    std::cout << Same::compSmart(a, b) << std::endl;

    a = {2, 2, 3};
    b = {4, 9, 9};
    std::cout << Same::compSmart(a, b) << std::endl;

    a = {1440, 195, 191, 161, 144, 19, 11, -121};
    b = {2073600, 38025, 36481, 25921, 20736, 14641, 361, 121};
    std::cout << Same::compSmart(a, b) << std::endl;

    a = {494, 96, 694, 48, 25, 701, 704};
    b = {9216, 495616, 2304, 244036, 625, 491401, 481636};
    std::cout << Same::compSmart(a, b) << std::endl;

    return EXIT_SUCCESS;
}
