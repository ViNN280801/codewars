#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int count_sheep(std::vector<bool> arr)
{
    return std::count_if(std::cbegin(arr), std::cend(arr), [](bool const &a)
                         { return a; });
}

int count_sheep_smarter(std::vector<bool> arr)
{
    return std::count(std::cbegin(arr), std::cend(arr), true);
}

int main()
{
    std::cout << count_sheep(std::vector<bool>({true, true, true, false,
                                                true, true, true, true,
                                                true, false, true, false,
                                                true, false, false, true,
                                                true, true, true, true,
                                                false, false, true, true}))
              << std::endl;

    std::cout << count_sheep_smarter(std::vector<bool>({true, true, true, false,
                                                        true, true, true, true,
                                                        true, false, true, false,
                                                        true, false, false, true,
                                                        true, true, true, true,
                                                        false, false, true, true}))
              << std::endl;

    return EXIT_SUCCESS;
}
