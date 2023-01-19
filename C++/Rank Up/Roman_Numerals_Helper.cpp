// Task: Create a RomanNumerals class that can convert a roman numeral to and
// from an integer value. It should follow the API demonstrated in the examples
// below. Multiple roman numeral values will be tested for each helper method.

// Modern Roman numerals are written by expressing each digit separately starting with
// the left most digit and skipping any digit with a value of zero. In Roman numerals 1990
// is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as
// 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.

// Input range : 1 <= n < 4000
// In this kata 4 should be represented as IV, NOT as IIII (the "watchmaker's four")

// Examples:
// RomanNumerals.toRoman(1000); // should return 'M'
// RomanNumerals.fromRoman('M'); // should return 1000

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <array>
#include <map>

class RomanHelper
{
private:
    const unsigned int kMinRomanValue{1U};
    const unsigned int kMaxRomanValue{4000U};

    static constexpr size_t karrSize{13UL};
    const std::array<std::string, karrSize> m_strRomans{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    std::array<int, karrSize> m_valuesRomans{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    const std::map<char, int> m_romanNumerals{{'I', 1},
                                              {'V', 5},
                                              {'X', 10},
                                              {'L', 50},
                                              {'C', 100},
                                              {'D', 500},
                                              {'M', 1000}};

protected:
    constexpr bool isValueInBounds(const unsigned int &val) const
    {
        return ((val >= kMinRomanValue) and (val <= kMaxRomanValue));
    }

public:
    constexpr std::string to_roman(int n) const
    {
        if (not isValueInBounds(n))
            return "";

        std::string res{""};
        for (size_t i{0UL}; i < karrSize; i++)
        {
            while (n - m_valuesRomans.at(i) >= 0)
            {
                res += m_strRomans.at(i);
                n -= m_valuesRomans.at(i);
            }
        }

        return res;
    }

    constexpr int from_roman(const std::string &rn) const
    {
        int res{0};

        for (size_t i{0UL}; i < rn.length(); i++)
        {
            if (((i + 1) < rn.length()) and (m_romanNumerals.at(rn.at(i)) < m_romanNumerals.at(rn.at(i + 1))))
            {
                res += m_romanNumerals.at(rn.at(i + 1)) - m_romanNumerals.at(rn.at(i));
                i++;
                continue;
            }
            res += m_romanNumerals.at(rn.at(i));
        }

        return res;
    }

} RomanNumerals;

int main()
{
    std::cout << RomanNumerals.to_roman(3999) << std::endl;
    std::cout << RomanNumerals.to_roman(567) << std::endl;
    std::cout << RomanNumerals.to_roman(23) << std::endl;
    std::cout << RomanNumerals.to_roman(9) << std::endl;
    std::cout << RomanNumerals.to_roman(1000) << std::endl;
    std::cout << RomanNumerals.from_roman("M") << std::endl;
    std::cout << RomanNumerals.from_roman("IX") << std::endl;
    std::cout << RomanNumerals.from_roman("XXIII") << std::endl;
    std::cout << RomanNumerals.from_roman("DLXVII") << std::endl;
    std::cout << RomanNumerals.from_roman("MMMCMXCIX") << std::endl;

    return EXIT_SUCCESS;
}
