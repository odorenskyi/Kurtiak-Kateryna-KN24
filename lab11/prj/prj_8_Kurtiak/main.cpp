#include <iostream>
#include "STRUCT_TYPE_PROJECT_8_H.h"
#include "ModulesKurtiak.h"

int main() {
    PostalDatabase db;

    // ������������ � ����� ��� �������
    if (db.loadFromFile(PostalConstants::DEFAULT_FILENAME)) {
        std::cout << "��� ����������� ������.\n";
    } else {
        std::cout << "���� �� �������� ��� �������.\n";
    }

    // ��������� ������ ������
    PostalRecord rec1(25006, "ʳ������������", "�������������", "�������������", "��� 6");
    db.addRecord(rec1);
    std::cout << "����� ������.\n";

    // ��������� ������ �� ��������
    if (db.deleteRecord(25006)) {
        std::cout << "����� ������ ��������.\n";
    } else {
        std::cout << "����� � ����� �������� �� ��������.\n";
    }

    return 0;
}
