/* Task: Create a function with two arguments that will return an array of the first n multiples of x.
Assume both the given number and the number of times to count will be positive numbers greater than 0.
Return the results as an array or list (depending on language)

Examples
countBy(1,10)  should return  {1,2,3,4,5,6,7,8,9,10}
countBy(2,5)  should return {2,4,6,8,10} */

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> countBy(int x, int n)
{
    std::vector<int> v(n);
    int val{};
    std::generate(v.begin(), v.end(), [&x, &val]()
                  { return val += x; });
    return v;
}

std::vector<int> countBy_moreClever(int x, int n)
{
    std::vector<int> v(n);
    std::generate(v.begin(), v.end(), [k = 0, x]() mutable
                  { return k += x; });
    return v;
}

template <typename T>
void printVec(std::vector<T> const &r)
{
    for (T const &el : r)
        std::cout << el << '\t';
    std::endl(std::cout);
}

int main()
{
    printVec<int>(countBy(1, 10));
    printVec<int>(countBy(2, 5));
    printVec<int>(countBy(1, 1));
    printVec<int>(countBy(7, 9));
    printVec<int>(countBy(1, 0));
    printVec<int>(countBy(100, 5));

    printVec<int>(countBy_moreClever(1, 10));
    printVec<int>(countBy_moreClever(2, 5));
    printVec<int>(countBy_moreClever(1, 1));
    printVec<int>(countBy_moreClever(7, 9));
    printVec<int>(countBy_moreClever(1, 0));
    printVec<int>(countBy_moreClever(100, 5));

    return EXIT_SUCCESS;
}
