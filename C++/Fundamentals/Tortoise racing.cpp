#include <iostream>
#include <vector>

class Tortoise
{
public:
    /**
     * @brief Calculates time on which B racer catch up the A. By default A has less speed.
     * @param a_speed speed of the 1st member (feet/hour).
     * @param b_speed speed of the 2nd member (feet/hour).
     * @param lead_of_a lead of the 1st member (feet).
     * @return Time in hours, minutes and seconds.
     */
    static std::vector<int> race(int a_speed, int b_speed, int lead_of_a)
    {
        // Checking boundary conditions
        if ((a_speed >= b_speed) || a_speed < 0 || b_speed < 0 || lead_of_a < 0)
            return {-1, -1, -1};

        int seconds{3600 * lead_of_a / (b_speed - a_speed)}, hours{seconds / 3600}, minutes{seconds / 60};
        if (hours != 0)
        {
            seconds -= hours * 3600;
            minutes -= hours * 60;
        }
        if (minutes != 0)
            seconds -= minutes * 60;

        return {hours, minutes, seconds};
    }

    static std::vector<int> race_smart(int v1, int v2, int g)
    {
        if (v1 >= v2)
            return {-1, -1, -1};

        int t{g * 3600 / (v2 - v1)};
        return {t / 3600, t / 60 % 60, t % 60};
    }
};

void printVector(std::vector<int> const &v)
{
    for (int el : v)
        std::cout << el << ' ';
    std::endl(std::cout);
}

int main()
{
    printVector(Tortoise::race(720, 850, 70));
    printVector(Tortoise::race(80, 91, 37));

    printVector(Tortoise::race_smart(720, 850, 70));
    printVector(Tortoise::race_smart(80, 91, 37));

    return EXIT_SUCCESS;
}
