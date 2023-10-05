#include <iostream>
#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &matrix)
{
    std::vector<int> result;

    int top{}, bottom{static_cast<int>(matrix.size() - 1)},
        left{}, right{static_cast<int>(matrix[0].size() - 1)};

    while (top <= bottom && left <= right)
    {
        // Move from left to right
        for (int i{left}; i <= right; ++i)
            result.emplace_back(matrix[top][i]);
        top++;

        // Move from top to bottom
        for (int i{top}; i <= bottom; ++i)
            result.emplace_back(matrix[i][right]);
        right--;

        // Move from right to left
        if (top <= bottom)
        {
            for (int i{right}; i >= left; --i)
                result.emplace_back(matrix[bottom][i]);
            bottom--;
        }

        // Move from bottom to top
        if (left <= right)
        {
            for (int i{bottom}; i >= top; --i)
                result.emplace_back(matrix[i][left]);
            left++;
        }
    }

    return result;
}

int main()
{
    std::vector<std::vector<int>> array{
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}};

    std::vector<int> snail_result{snail(array)};

    for (int num : snail_result)
        std::cout << num << " ";

    return EXIT_SUCCESS;
}
