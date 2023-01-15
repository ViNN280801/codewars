// Task: There was a test in your class and you passed it. Congratulations!
// But you're an ambitious person. You want to know if you're better than the average student in your class.

// You receive an array with your peers' test scores. Now
// calculate the average and compare your score!

// Return True if you're better, else False!

// Note:
// Your points are not included in the array of your class's points.
// For calculating the average point you may add your point to the given array!

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

// Returns "true" if 'yourPoints' is greater than average of 'classPoints'
// Otherwise returns "false"
bool betterThanAverage(std::vector<int> classPoints, int yourPoints)
{
    return yourPoints >= std::accumulate(std::cbegin(classPoints), std::cend(classPoints), yourPoints) /
                            static_cast<int>(classPoints.size());
}

int main()
{
    std::cout << betterThanAverage(std::vector<int>{2, 3}, 5) << std::endl;
    std::cout << betterThanAverage(std::vector<int>{100, 40, 34, 57, 29, 72, 57, 88}, 75) << std::endl;
    std::cout << betterThanAverage({12, 23, 34, 45, 56, 67, 78, 89, 90}, 69) << std::endl;
    std::cout << betterThanAverage(std::vector<int>{41, 75, 72, 56, 80, 82, 81, 33}, 50) << std::endl;
    std::cout << betterThanAverage(std::vector<int>{29, 55, 74, 60, 11, 90, 67, 28}, 21) << std::endl;

    return EXIT_SUCCESS;
}
