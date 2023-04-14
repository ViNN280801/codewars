#include <iostream>
#include <string>

static const std::string alphabet{"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"};

std::string rot13(const std::string &str)
{
    std::string rottedStr;
    for (size_t i{}; i < str.length(); i++)
    {
        size_t pos{alphabet.find(str.at(i))};
        if (pos != std::string::npos)
        {
            pos = (pos >= alphabet.size() / 2) ? pos - 26 : pos + 26;
            rottedStr.push_back(alphabet.at(pos));
        }
        else
            rottedStr.push_back(str.at(i));
    }
    return rottedStr;
}

int main()
{
    //std::cout << rot13("EBG13 rknzcyr.") << std::endl;
    std::cout << rot13("This is my first ROT13 excercise!") << std::endl;

    return EXIT_SUCCESS;
}
