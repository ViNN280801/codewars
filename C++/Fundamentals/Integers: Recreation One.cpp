#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

class SumSquaredDivisors
{
    static constexpr bool isPerfectSquare(long long num) { return std::sqrt(num) * std::sqrt(num) == num; }

    static std::vector<long long> getDivisors(long long num)
    {
        std::vector<long long> divisors;
        for (auto i{1ll}; i <= num; ++i)
            if (num % i == 0)
                divisors.emplace_back(i);
        return divisors;
    }

    static std::vector<long long> getSqrtedDivisors(long long num)
    {
        std::vector<long long> sqrtedDivisors(getDivisors(num));
        std::transform(std::cbegin(sqrtedDivisors), std::cend(sqrtedDivisors),
                       std::begin(sqrtedDivisors), [](long long i)
                       { return i * i; });
        return sqrtedDivisors;
    }

public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n)
    {
        // Checking boundary condition: 1 <= m <= n
        if (m < 1 || n < 1 || n < m)
            return {};

        std::vector<std::pair<long long, long long>> listSqrts;
        for (long long i = m; i <= n; ++i)
        {
            auto divs{getSqrtedDivisors(i)};
            auto sum{std::accumulate(std::cbegin(divs), std::cend(divs), 0ll)};
            if (std::pow(static_cast<long long>(std::sqrt(sum)), 2) == sum)
                listSqrts.emplace_back(std::make_pair(i, sum));
        }

        return listSqrts;
    }
};

int main()
{
    for (auto const &[m, n] : SumSquaredDivisors::listSquared(1, 250))
        std::cout << m << '\t' << n << '\n';
    for (auto const &[m, n] : SumSquaredDivisors::listSquared(42, 250))
        std::cout << m << '\t' << n << '\n';

    return EXIT_SUCCESS;
}
