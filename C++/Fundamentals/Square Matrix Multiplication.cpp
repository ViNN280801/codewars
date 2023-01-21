// Task: Write a function that accepts two square (NxN) matrices (two dimensional arrays),
// and returns the product of the two. Only square matrices will be given.

// How to multiply two square matrices:
// We are given two matrices, A and B, of size 2x2 (note: tests are not limited to 2x2).
// Matrix C, the solution, will be equal to the product of A and B. To fill in cell [0][0]
// of matrix C, you need to compute: A[0][0] * B[0][0] + A[0][1] * B[1][0].

// More general: To fill in cell [n][m] of matrix C, you need to first multiply
// the elements in the nth row of matrix A by the elements in the mth column of matrix
// B, then take the sum of all those products. This will give you the value for cell [m][n] in matrix C.

// Example:
//   A         B          C
// |1 2|  x  |3 2|  =  | 5 4|
// |3 2|     |1 1|     |11 8|

// Detailed calculation:
// C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] = 1*3 + 2*1 =  5
// C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] = 1*2 + 2*1 =  4
// C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] = 3*3 + 2*1 = 11
// C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] = 3*2 + 2*1 =  8

// Link to Wikipedia explaining matrix multiplication (look at the square matrix example):
// http://en.wikipedia.org/wiki/Matrix_multiplication

// A more visual explanation of matrix multiplication: http://matrixmultiplication.xyz

#include <iostream>
#include <vector>

template <typename T = int>
void printMatrix(const std::vector<std::vector<T>> &vec)
{
    for (size_t row{0UL}; row < vec.size(); row++)
    {
        for (size_t col{0UL}; col < vec.at(row).size(); col++)
        {
            std::cout << vec.at(row).at(col) << ' ';
        }
        std::cout << '\n';
    }
}

template <typename T = int>
std::vector<std::vector<T>> matrix_multiplication(std::vector<std::vector<T>> &a,
                                                  std::vector<std::vector<T>> &b, size_t n)
{
    std::vector<std::vector<T>> res{a};

    for (size_t row{0UL}; row < n; row++)
    {
        for (size_t col{0UL}; col < n; col++)
        {
            res.at(row).at(col) -= a.at(row).at(col);
            for (size_t k{0UL}; k < n; k++)
            {
                res.at(row).at(col) += a.at(row).at(k) * b.at(k).at(col);
            }
        }
    }

    return res;
}

int main()
{
    std::vector<std::vector<int>> a{{1, 2}, {3, 2}}, b{{3, 2}, {1, 1}};
    printMatrix(matrix_multiplication(a, b, 2UL));

    return EXIT_SUCCESS;
}
