#include <iostream>

// Clock shows 'h' hours, 'm' minutes and 's' seconds after midnight.
// Returns the time since midnight in milliseconds.
int past(int h, int m, int s)
{
    return ((s * 1000) + ((m * 60) * 1000) + (((h * 60) * 60) * 1000));
}

int main(int argc, char *argv[])
{
    // Initializing variables for store hours, minutes and seconds for calculate milliseconds
    int hours{}, minutes{}, seconds{};

    // User input hours, minutes and seconds
    std::cout << "Enter hours: ";
    std::cin >> hours;
    std::cout << "Enter minutes: ";
    std::cin >> minutes;
    std::cout << "Enter seconds: ";
    std::cin >> seconds;

    // Printing result
    std::cout << past(hours, minutesm seconds) << std::endl;

    return EXIT_SUCCESS;
}