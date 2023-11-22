#include <iostream>

class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window)
    {
        if (h <= 0 || h <= window || (bounce <= 0 || 1.0 <= bounce))
            return -1;

        int count{1};
        double next_pos{h * bounce};
        while (next_pos > window)
        {
            next_pos *= bounce;
            count += 2;
        }
        return count;
    }
};

int main()
{
    std::cout << Bouncingball::bouncingBall(3.0, 0.66, 1.5) << '\n';
    std::cout << Bouncingball::bouncingBall(3.0, 1.0, 1.5) << '\n';
    std::cout.flush();

    return EXIT_SUCCESS;
}
