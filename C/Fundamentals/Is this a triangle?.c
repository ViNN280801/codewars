#include <stdbool.h>

bool is_triangle(int a, int b, int c)
{
    return (a + b) > c && (b + c) > a && (a + c) > b;
}
