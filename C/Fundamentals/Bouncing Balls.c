#include <stdio.h>

/**
 * @param h Height of the building [meters].
 * @param bounce Initial bounce [relative units].
 * @param window Distance between ground and the window [meters].
 * @return Count of the ball bounces that will be passed in front of the window.
 * `-1` if smth goes wrong.
 */
int bouncingBall(double h, double bounce, double window)
{
    if (h <= 0.0 || (bounce <= 0.0 || 1.0 <= bounce) || h <= window)
        return -1;

    int counter = 1;              // Mother can see the ball minimum at once
    double next_pos = bounce * h; // `h` is the current pos
    while (next_pos > window)
    {
        next_pos *= bounce;
        counter += 2;
    }

    return counter;
}

int main()
{
    printf("%d\n", bouncingBall(3.0, 0.66, 1.5));
    printf("%d\n", bouncingBall(3.0, 1.0, 1.5));

    return 0;
}
