// Task: Create a function that gives a personalized greeting.
// This function takes two parameters: name and owner.

// Use conditionals to return the proper message:
// case 	return
// name equals owner 	'Hello boss'
// otherwise 	'Hello guest'

#include <iostream>
#include <string>

// Returns "Hello boss" if '__name' and '__owner' are equals
// Otherwise, returns "Hello guest"
std::string greet(const std::string &__name, const std::string &__owner)
{
    return (__name == __owner) ? "Hello boss" : "Hello guest";
}

int main()
{
    std::cout << greet("Daniel", "Daniel") << std::endl;
    std::cout << greet("Greg", "Daniel") << std::endl;

    return EXIT_SUCCESS;
}
