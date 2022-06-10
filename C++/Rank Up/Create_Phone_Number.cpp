// Task: Write a function that accepts an array of 10 integers (between 0 and 9), that returns a string of those numbers in the form of a phone number.
// Example:
// createPhoneNumber(int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}) // => returns "(123) 456-7890"
// The returned format must be correct in order to complete this challenge.
// Don't forget the space after the closing parentheses!

#include <iostream>
#include <string>

// Accepts an array of 10 integers (between 0 and 9)
// Returns a string of those numbers in the form of a phone number.
std::string createPhoneNumber(const int arr[10])
{
    std::string phoneNumber{};
    phoneNumber.push_back('(');

    for (int iter = 0; iter < 10; iter++)
    {
        if (iter == 3)
        {
            phoneNumber.append(") ");
        }
        else if (iter == 6)
        {
            phoneNumber.append("-");
        }
        phoneNumber.push_back('0' + arr[iter]);
    }

    return phoneNumber;
}

int main(int argc, char *argv[])
{
    // Initializing arrays for create phone numbers
    int arr1[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int arr2[10]{2, 2, 3, 4, 1, 6, 7, 7, 1, 1};

    // Showing result of work function 'createPhoneNumber'
    std::cout << createPhoneNumber(arr1) << std::endl;
    std::cout << createPhoneNumber(arr2) << std::endl;

    return EXIT_SUCCESS;
}