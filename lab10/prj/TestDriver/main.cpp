#include "ModulesK.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice;
    std::cout << "Виберіть завдання:\n";
    std::cout << "1. Завдання 10.1\n";
    std::cout << "2. Завдання 10.2\n";
    std::cout << "3. Завдання 10.3\n";
    std::cout << "Ваш вибір: ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::string inputFile = "input.txt";
            std::string outputFile = "output.txt";
            processTask10_1(inputFile, outputFile);
            std::cout << "Завдання 10.1 виконано. Результати записано у файл " << outputFile << ".\n";
            break;
        }
        case 2: {
            std::string filename = "output.txt";
            appendFileSizeAndTimestamp(filename);
            std::cout << "Завдання 10.2 виконано. Інформацію дописано у файл " << filename << ".\n";
            break;
        }
        case 3: {
            std::ofstream outFile("output.txt", std::ios::app);
            if (!outFile.is_open()) {
                std::cerr << "Помилка відкриття файлу для запису!\n";
                break;
            }

            int x, y, z, b;
            std::cout << "Введіть значення x, y, z, b: ";
            std::cin >> x >> y >> z >> b;

            writeTask10_3Data(outFile, x, y, z, b);
            outFile.close();
            std::cout << "Завдання 10.3 виконано. Результати записано у файл output.txt.\n";
            break;
        }
        default:
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
    }

    return 0;
}
