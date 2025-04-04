#include <windows.h>
#include <iostream>
#include <cmath>
#include <bitset>
#include "modulesK.h"

int main() {

    std::cout << "Куртяк Катерина ©, Усі права захищені." << std::endl;
    double wind_speed;

    std::cout << "Введіть швидкість вітру (м/с): ";
    std::cin >> wind_speed;

    std::string result = task_9_1(wind_speed);
    std::cout << result << std::endl;

    // Testing celsiusToFahrenheit function
    double celsius;
    std::cout << "\nTesting celsiusToFahrenheit function:" << std::endl;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;
    std::cout << celsius << "°C = " << celsiusToFahrenheit(celsius) << "°F" << std::endl;

    // Testing countBits function
    int number;
    std::cout << "\nTesting countBits function:" << std::endl;
    std::cout << "Enter an integer (0-65535): ";
    std::cin >> number;

    std::cout << "Binary representation: " << std::bitset<16>(number) << std::endl;
    std::cout << "Result of countBits: " << countBits(number) << std::endl;

    return 0;
}
