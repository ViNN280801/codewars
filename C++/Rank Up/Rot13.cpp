// Task: ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet.
// ROT13 is an example of the Caesar cipher.
// Create a function that takes a string and returns the string ciphered with Rot13.
// If there are numbers or special characters included in the string, they should be returned as they are.
// Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".

#include <iostream>
#include <string>

using namespace std;

// Realizing Caesar cipher
string rot13(string msg)
{
    string encrypted;

    for (size_t i = 0; i < msg.size(); i++)
    {
        if (isalpha(msg[i]))
        {
            if ((tolower(msg[i]) - 'a') <= 13)
                encrypted.append(1, msg[i] + 13);
            else
                encrypted.append(1, msg[i] - 13);
        }
        else
        {
            encrypted.append(1, msg[i]);
        }

        if (encrypted[i] == '[')
            encrypted[i] = 'A';
        else if (encrypted[i] == '{')
            encrypted[i] = 'a';
    }

    return encrypted;
}

int main(int argc, char *argv[])
{
    // Showing result of work function 'rot13'
    std::cout << rot13("Encrypted message") << std::endl;
    std::cout << rot13("Rapelcgrq zrffntr") << std::endl;

    return EXIT_SUCCESS;
}