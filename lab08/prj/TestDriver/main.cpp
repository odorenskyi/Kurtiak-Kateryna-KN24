#include <iomanip>
#include <locale>
#include <windows.h>
#include <iostream>
#include "C:\Users\Asus\Desktop\BMTP_LAB8_Kurtiak\prj\ModulesKurtiak\ModulesK.h"
using namespace std;

int main() {


    setlocale(LC_ALL, "Ukrainian");

    double x, y, z;

    cout << "Введіть x, y, z: ";
    cin >> x >> y >> z;

    double result = s_calculation(x, y, z);
    cout << "S = " << result << endl;

    return 0;
}
