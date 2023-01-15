// Task: Description:

// Make a simple function called greet that returns the most-famous "hello world!".
// Style Points

// Sure, this is about as easy as it gets. But how clever can you be to
// create the most creative hello world you can think of? What is a
// hello world" solution you would want to show your friends?

#include <iostream>

static const std::string greet_str("hello world!");
const auto greet_lambda{[]
                            { return greet_str; }};
const std::string greet()
{
    return greet_lambda();
}

int main()
{
    std::cout << greet() << std::endl;

    return EXIT_SUCCESS;
}
