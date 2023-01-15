// Task: Write function bmi that calculates
// body mass index (bmi = weight / height^2).

// if bmi <= 18.5 return "Underweight"
// if bmi <= 25.0 return "Normal"
// if bmi <= 30.0 return "Overweight"
// if bmi > 30 return "Obese"

#include <iostream>
#include <string>

std::string bmi(double w, double h)
{
    if (h == 0.0)
        return "";

    double body_mass_index{w / h / h};

    if (body_mass_index <= 18.5)
        return "Underweight";
    else if (body_mass_index <= 25.0)
        return "Normal";
    else if (body_mass_index <= 30.0)
        return "Overweight";

    return "Obese";
}

int main()
{
    std::cout << bmi(81.585, 2.1) << std::endl;
    std::cout << bmi(90.25, 1.9) << std::endl;
    std::cout << bmi(86.7, 1.7) << std::endl;
    std::cout << bmi(200, 1.6) << std::endl;
    std::cout << bmi(65, 0) << std::endl;

    return EXIT_SUCCESS;
}
