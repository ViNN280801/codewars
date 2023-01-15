// Task: Given an array (arr) as an argument complete the function
// countSmileys that should return the total number of smiling faces.

// Rules for a smiling face:
// Each smiley face must contain a valid pair of eyes. Eyes can be marked as : or ;
// A smiley face can have a nose but it does not have to. Valid characters for a nose are - or ~
// Every smiling face must have a smiling mouth that should be marked with either ) or D

// No additional characters are allowed except for those mentioned.

// Valid smiley face examples: :) :D ;-D :~)
// Invalid smiley faces: ;( :> :} :]

// Example
// countSmileys([':)', ';(', ';}', ':-D']);       // should return 2;
// countSmileys([';D', ':-(', ':-)', ';~)']);     // should return 3;
// countSmileys([';]', ':[', ';*', ':$', ';-D']); // should return 1;

// Note
// In case of an empty array return 0. You will not be tested with
// invalid input (input will always be an array). Order of the face
// (eyes, nose, mouth) elements will always be the same.

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <span> // Since C++20

static const std::regex smile_face_pattern("[:;][-~]?[)D]");

// Since C++20
// Returns count of smile faces
int countSmileys(std::span<const std::string> __arr)
{
    int count{0};
    for (auto it{std::cbegin(__arr)}; it != std::cend(__arr); ++it)
    {
        if (std::regex_match(*it, smile_face_pattern))
            count++;
    }
    return count;
}

// Returns count of smile faces
int countSmileys(const std::vector<std::string> &__arr)
{
    int count{0};
    for (size_t arr_index{0UL}; arr_index < __arr.size(); arr_index++)
    {
        if (std::regex_match(__arr.at(arr_index), smile_face_pattern))
            count++;
    }
    return count;
}

int main()
{
    std::vector<std::string> vec{":D", ":~)", ";~)", ":)"};
    std::cout << countSmileys(vec) << std::endl;

    vec = {":)", ":(", ":D", ":O", ":;"};
    std::cout << countSmileys(vec) << std::endl;

    vec = {";]", ":[", ";*", ":$", ";-D"};
    std::cout << countSmileys(vec) << std::endl;

    return EXIT_SUCCESS;
}
