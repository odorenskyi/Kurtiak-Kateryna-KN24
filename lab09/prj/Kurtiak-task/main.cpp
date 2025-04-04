#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include "modulesK.h"
int main() {
    char input;
    while (true) {
        std::cout << "Введіть символ (q, e, r, t): ";
        std::cin >> input;

        switch (input) {
            case 'q': {
                double x, y, z;
                std::cout << "Введіть значення x, y, z: ";
                std::cin >> x >> y >> z;
                std::cout << "Результат s_calculation: " << s_calculation(x, y, z) << std::endl;
                break;
            }
            case 'e': {
                double speed;
                std::cout << "Введіть швидкість вітру (м/с): ";
                std::cin >> speed;
                std::cout << task_9_1(speed) << std::endl;
                break;
            }
            case 'r': {
                double celsius;
                std::cout << "Введіть температуру в градусах Цельсія: ";
                std::cin >> celsius;
                std::cout << "Температура у Фаренгейтах: " << celsiusToFahrenheit(celsius) << "°F" << std::endl;
                break;
            }
            case 't': {
                int N;
                std::cout << "Введіть ціле число: ";
                std::cin >> N;
                std::cout << "Результат countBits: " << countBits(N) << std::endl;
                break;
            }
            default:
                std::cout << "\aПомилкове введення! Будь ласка, введіть допустимий символ.\n";
                continue;
        }

        char exit_choice;
        std::cout << "Бажаєте вийти? (Y/У/Н - вихід, інше - продовжити): ";
        std::cin >> exit_choice;

        if (exit_choice == 'Y' || exit_choice == 'У' || exit_choice == 'Н') {
            std::cout << "Програма завершена." << std::endl;
            break;
        }
    }

    return 0;
}
