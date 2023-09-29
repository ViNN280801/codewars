#include <iostream>
#include <span>
#include <vector>
#include <numeric>

std::vector<int> xbonacci(std::vector<int> signature, int n)
{
    if (signature.empty() && n == 0)
        return {};

    if (static_cast<size_t>(n) < signature.size())
        return std::vector<int>(std::cbegin(signature), std::cbegin(signature) + n);

    if (n > 0 && signature.empty())
        return std::vector<int>(n, 0);

    size_t idx{};
    while (signature.size() < static_cast<size_t>(n))
    {
        int next{};

        for (size_t i{idx}; i < signature.size(); i++)
            next += signature[i];
        idx++;

        signature.emplace_back(next);
    }

    return signature;
}

std::vector<int> xbonacci_2nd_version(std::vector<int> signature, int n)
{
    signature.reserve(n);
    auto it{signature.begin()};
    while (signature.size() < n)
        signature.emplace_back(std::accumulate(it++, signature.end(), 0));
    signature.resize(n);
    return signature;
}

template <typename T>
void printRange(std::span<T const> range)
{
    for (auto const &el : range)
        std::cout << el << ' ';
    std::endl(std::cout);
}

int main()
{
    printRange<int>(xbonacci({5, 2, 4, 7}, 2));
    printRange<int>(xbonacci({1, 1, 1, 1}, 10));
    printRange<int>(xbonacci({0, 0, 0, 0, 1}, 10));
    printRange<int>(xbonacci({1, 0, 0, 0, 0, 0, 1}, 10));
    printRange<int>(xbonacci({}, 15));

    return EXIT_SUCCESS;
}
