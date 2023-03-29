// Task: Some numbers have funny properties. For example:

// 89 --> 8¹ + 9² = 89 * 1
// 695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2
// 46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51

// Given a positive integer n written as abcd... (a, b, c, d... being digits) and a positive integer p
// we want to find a positive integer k, if it exists, such that the sum of the digits
// of n taken to the successive powers of p is equal to k * n.

// In other words:
// Is there an integer k such as: (a^p + b^(p+1) + c^(p+2) + d^(p+3) + ...) = n * k

// If it is the case we will return k, if not return -1.

// Note: n and p will always be given as strictly positive integers.

// digPow(89, 1) should return 1 since 8¹ + 9² = 89 = 89 * 1
// digPow(92, 1) should return -1 since there is no k such as 9¹ + 2² equals 92 * k
// digPow(695, 2) should return 2 since 6² + 9³ + 5⁴= 1390 = 695 * 2
// digPow(46288, 3) should return 51 since 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class DigPow
{
public:
    static constexpr int myPow(int const &a, int const &b)
    {
        int result{a};
        for (int i{1}; i < b; i++)
            result *= a;
        return result;
    }

    static std::vector<int> splitNumberOnDigits(int const &number)
    {
        std::vector<int> digits;
        int numberCopy{number};

        while (true)
        {
            digits.push_back(numberCopy % 10);
            numberCopy /= 10;

            if (numberCopy == 0)
                return digits;
        }
    }

    static int digPow(int n, int p)
    {
        std::vector<int> digits(splitNumberOnDigits(n));
        std::reverse(std::begin(digits), std::end(digits));

        int result{};
        for (size_t i{}; i < digits.size(); i++)
        {
            result += myPow(digits.at(i), i + p);
        }

        return result % n == 0 ? result / n : -1;
    }

    static int digPowClever(int n, int p)
    {
        long long sum = 0;
        for (char digit : std::to_string(n))
        {
            sum += myPow(digit - '0', p++);
        }
        return (sum / n) * n == sum ? sum / n : -1;
    }
};

int main()
{
    std::cout << DigPow::digPow(89, 1) << std::endl;
    std::cout << DigPow::digPow(92, 1) << std::endl;
    std::cout << DigPow::digPow(695, 2) << std::endl;
    std::cout << DigPow::digPow(46288, 3) << std::endl;
    std::cout << DigPow::digPow(46288, 5) << std::endl;

    std::endl(std::cout);
    std::cout << DigPow::digPowClever(89, 1) << std::endl;
    std::cout << DigPow::digPowClever(92, 1) << std::endl;
    std::cout << DigPow::digPowClever(695, 2) << std::endl;
    std::cout << DigPow::digPowClever(46288, 3) << std::endl;
    std::cout << DigPow::digPowClever(46288, 5) << std::endl;

    return EXIT_SUCCESS;
}
