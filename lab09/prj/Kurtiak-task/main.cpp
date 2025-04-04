#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include "modulesK.h"
int main() {
    char input;
    while (true) {
        std::cout << "������ ������ (q, e, r, t): ";
        std::cin >> input;

        switch (input) {
            case 'q': {
                double x, y, z;
                std::cout << "������ �������� x, y, z: ";
                std::cin >> x >> y >> z;
                std::cout << "��������� s_calculation: " << s_calculation(x, y, z) << std::endl;
                break;
            }
            case 'e': {
                double speed;
                std::cout << "������ �������� ���� (�/�): ";
                std::cin >> speed;
                std::cout << task_9_1(speed) << std::endl;
                break;
            }
            case 'r': {
                double celsius;
                std::cout << "������ ����������� � �������� ������: ";
                std::cin >> celsius;
                std::cout << "����������� � �����������: " << celsiusToFahrenheit(celsius) << "�F" << std::endl;
                break;
            }
            case 't': {
                int N;
                std::cout << "������ ���� �����: ";
                std::cin >> N;
                std::cout << "��������� countBits: " << countBits(N) << std::endl;
                break;
            }
            default:
                std::cout << "\a��������� ��������! ���� �����, ������ ���������� ������.\n";
                continue;
        }

        char exit_choice;
        std::cout << "������ �����? (Y/�/� - �����, ���� - ����������): ";
        std::cin >> exit_choice;

        if (exit_choice == 'Y' || exit_choice == '�' || exit_choice == '�') {
            std::cout << "�������� ���������." << std::endl;
            break;
        }
    }

    return 0;
}
