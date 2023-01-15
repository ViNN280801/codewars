// Task: Given the triangle of consecutive odd numbers:
//              1
//           3     5
//        7     9    11
//    13    15    17    19
// 21    23    25    27    29
// ...

// Calculate the sum of the numbers in the nth row of this triangle (starting at index 1) e.g.: (Input --> Output)
// 1 -->  1
// 2 --> 3 + 5 = 8

#include <iostream>

// Returns first element of '__row' row in triangle of consecutive odd numbers
long long first_element_of_n_row(const unsigned &__row)
{
    long long first_elem{0LL};

    for (unsigned incr{1U}; incr <= (__row - 1U); incr++)
    {
        first_elem += incr;
    }

    return 1LL + 2 * first_elem;
}

// Returns sum of odd numbers in '__row' row in triangle of consecutive odd numbers
long long rowSumOddNumbers(const unsigned &__row)
{
    long long elem{first_element_of_n_row(__row)}, sum{0LL};

    for (unsigned iteration{0U}; iteration < __row; iteration++)
    {
        sum += elem;
        elem += 2LL;
    }

    return sum;
}

// Smart solution
// Returns sum of odd numbers in '__row' row in triangle of consecutive odd numbers
long long rowSumOddNumbers(const unsigned &__row)
{
    // n - elements at level n
    // 1+2+3+4+5+...+ n= (n+1)n/2 - elements in a pyramid of n levels
    // 0+1+2+3+4+...+( n-1) = (n-1)n/2 - so many times 2 is added to the previous number
    // 1+(n-1)n - level n begins with this element
    //[1+(n-1)n]+[1+(n-1)n+2]+[1+(n-1)n+4]+...+[1+(n-1)n+2(n-1)] - elements of the last level
    //([1+(n-1)n] + [1+(n-1)n+2(n-1)])n/2 = n^3

    return __row * __row * __row;
}

int main()
{
    std::cout << rowSumOddNumbers(1U) << std::endl;
    std::cout << rowSumOddNumbers(7U) << std::endl;
    std::cout << rowSumOddNumbers(42U) << std::endl;
    std::cout << rowSumOddNumbers(53U) << std::endl;

    return EXIT_SUCCESS;
}
