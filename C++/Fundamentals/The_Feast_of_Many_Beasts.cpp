// Task: All of the animals are having a feast! Each animal is bringing one dish.
// There is just one rule: the dish must start and end with the same letters as the
// animal's name. For example, the great blue heron is bringing garlic naan and the
// chickadee is bringing chocolate cake.

// Write a function feast that takes the animal's name and dish as arguments and returns true or
// false to indicate whether the beast is allowed to bring the dish to the feast.

// Assume that beast and dish are always lowercase strings, and that each has at least
// two letters. beast and dish may contain hyphens and spaces, but these will not
// appear at the beginning or end of the string. They will not contain numerals.

#include <iostream>
#include <string>
#include <iterator>

// Returns "false" if 1st symbol of '__beast' equals to 1st symbol of '__dish'
// and last symbol of '__beast' equals to last symbol of '__dish'
// Otherwise returns "false"
bool feast(std::string __beast, std::string __dish)
{
    return (*std::cbegin(__beast) == *(std::cbegin(__dish)) && (*(std::cend(__beast) - 1) == *(std::cend(__dish) - 1))) ? true : false;
}

int main()
{
    std::cout << feast("great blue heron", "garlic naan") << std::endl;
    std::cout << feast("chickadee", "chocolate cake") << std::endl;
    std::cout << feast("brown bear", "bear claw") << std::endl;
    std::cout << feast("marmot", "mulberry tart") << std::endl;
    std::cout << feast("porcupine", "pie") << std::endl;
    std::cout << feast("electric eel", "lasagna") << std::endl;
    std::cout << feast("slow loris", "salsas") << std::endl;
    std::cout << feast("ox", "orange lox") << std::endl;
    std::cout << feast("blue-footed booby", "blueberry") << std::endl;
    std::cout << feast("blue-footed booby", "binary human") << std::endl;

    return EXIT_SUCCESS;
}
