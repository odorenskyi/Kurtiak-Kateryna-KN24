#include <iomanip>
#include <locale>
#include <windows.h>
#include <iostream>
#include <stdexcept>
#include "C:\Users\stasj\Desktop\BMTP_LAB8_Kurtiak\prj\ModulesKurtiak\ModulesK.h"

using namespace std;

// ������� ��������� ���� ����������
void printDeveloperInfo() {
    cout << "� �������� ������" << endl;
}

// ������� �������� �������� ������ a + 1 = b + 2
bool checkLogicalExpression(int a, int b) {
    return (a + 1) == (b + 2);
}

int main() {

    setlocale(LC_ALL, "Ukrainian");

 // ��������� ����������
    printDeveloperInfo();

    int a, b;
    double x, y, z;

    // �������� �����
    cout << "������ �������� x, y, z: ";
    cin >> x >> y >> z;
    cout << "������ �������� a, b: ";
    cin >> a >> b;

 // ���������� �������� ������
    cout << "��������� �������� ������: "
         << (checkLogicalExpression(a, b) ? "1 (true)" : "0 (false)") << endl;

    // ��������� ���������� � ����� �������� ��������
    cout << "x = " << dec << x << " (dec), " << hex << x << " (hex)" << endl;
    cout << "y = " << dec << y << " (dec), " << hex << y << " (hex)" << endl;
    cout << "z = " << dec << z << " (dec), " << hex << z << " (hex)" << endl;

    // ���������� �������� S
    double S = s_calculation(x, y, z);
    cout << fixed << setprecision(3) << "S = " << S << endl;


    return 0;
}
