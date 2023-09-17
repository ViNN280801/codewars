namespace Triangle
{
    // Guarantees to be checked in compile time if 'a', 'b' and 'c' are constant expressions
    // Since C++20 can use "consteval" keyword
    constexpr bool isTriangle(int a, int b, int c) { return (a + b) > c && (b + c) > a && (a + c) > b; }
};