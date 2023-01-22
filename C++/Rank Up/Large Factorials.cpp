// Task: In mathematics, the factorial of integer n is written as n!. It is equal to
// the product of n and every integer preceding it. For example: 5! = 1 x 2 x 3 x 4 x 5 = 120

// Your mission is simple: write a function that takes an integer n and returns the value of n!.
// You are guaranteed an integer argument. For any values outside the non-negative range,
// return null, nil or None (return an empty string "" in C and C++).
// For non-negative numbers a full length number is expected for
// example, return 25! =  "15511210043330985984000000" as a string.

// For more on factorials, see http://en.wikipedia.org/wiki/Factorial

// NOTES:
// The use of BigInteger or BigNumber functions has been disabled, this requires a complex solution
// I have removed the use of require in the javascript language.

#include <iostream>
#include <string>
#include <array>
#include <sstream>

constexpr size_t karrMaxSize{1000UL};

constexpr int multNextNum(const int &prevNumber, std::array<int, karrMaxSize> &digitsArr, int &newSize)
{
    int num{0}, digit{0};
    while (digit < newSize)
    {
        int product{digitsArr.at(digit) * prevNumber + num};
        digitsArr.at(digit) = product % 10;
        num = product / 10;
        digit++;
    }

    while (num)
    {
        digitsArr.at(newSize) = num % 10;
        num /= 10;
        newSize++;
    }
    return newSize;
}

std::string factorial(const int &number) noexcept
{
    std::array<int, karrMaxSize> digitsArr;
    digitsArr.at(0UL) = 1;
    int size{1};

    for (int prevNumber{2}; prevNumber <= number; prevNumber++)
    {
        size = multNextNum(prevNumber, digitsArr, size);
    }

    std::stringstream ss;
    for (int digit{size - 1}; digit >= 0; digit--)
    {
        ss << digitsArr.at(digit);
    }
    return ss.str();
}

#include <vector>
#include <iterator>
std::string factorialSmart(int factorial)
{
    std::vector<int> vec{1};
    int c{0};
    for (int i{1}; i <= factorial; i++)
    {
        for (auto &d : vec)
        {
            int v = d * i + c;
            d = v % 10;
            c = v / 10;
        }
        for (; c > 0; c /= 10)
            vec.push_back(c % 10);
    }

    std::stringstream ss;
    std::copy(std::rbegin(vec), std::rend(vec), std::ostream_iterator<int>(ss));
    return ss.str();
}

int main(void)
{
    std::cout << factorial(0) << std::endl;
    std::cout << factorial(1) << std::endl;
    std::cout << factorial(5) << std::endl;
    std::cout << factorial(9) << std::endl;
    std::cout << factorial(15) << std::endl;
    std::cout << factorial(35) << std::endl;
    std::cout << factorial(50) << std::endl;
    std::cout << factorial(70) << std::endl;
    std::cout << factorial(100) << std::endl;

    return EXIT_SUCCESS;
}
