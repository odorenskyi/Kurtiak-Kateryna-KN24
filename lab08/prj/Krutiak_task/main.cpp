#include <iomanip>
#include <locale>
#include <windows.h>
#include <iostream>
#include <stdexcept>
#include "C:\Users\stasj\Desktop\BMTP_LAB8_Kurtiak\prj\ModulesKurtiak\ModulesK.h"

using namespace std;

// Функція виведення імені розробника
void printDeveloperInfo() {
    cout << "© Катерина Крутяк" << endl;
}

// Функція перевірки логічного виразу a + 1 = b + 2
bool checkLogicalExpression(int a, int b) {
    return (a + 1) == (b + 2);
}

int main() {

    setlocale(LC_ALL, "Ukrainian");

 // Виведення інформації
    printDeveloperInfo();

    int a, b;
    double x, y, z;

    // Введення даних
    cout << "Введіть значення x, y, z: ";
    cin >> x >> y >> z;
    cout << "Введіть значення a, b: ";
    cin >> a >> b;

 // Обчислення логічного виразу
    cout << "Результат логічного виразу: "
         << (checkLogicalExpression(a, b) ? "1 (true)" : "0 (false)") << endl;

    // Виведення результатів у різних системах числення
    cout << "x = " << dec << x << " (dec), " << hex << x << " (hex)" << endl;
    cout << "y = " << dec << y << " (dec), " << hex << y << " (hex)" << endl;
    cout << "z = " << dec << z << " (dec), " << hex << z << " (hex)" << endl;

    // Обчислення значення S
    double S = s_calculation(x, y, z);
    cout << fixed << setprecision(3) << "S = " << S << endl;


    return 0;
}
