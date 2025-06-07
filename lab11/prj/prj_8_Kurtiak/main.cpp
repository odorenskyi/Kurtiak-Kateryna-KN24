#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "struct_type_project_8.h"         // ���� PostalRecord
#include "struct_type_project_Kurtiak.h"   // loadData, searchByIndex
#include "struct_type_project_Ivanov.h"    // addRecord, deleteRecord
#include "struct_type_project_Marchenko.h" // printAll, saveAndExit

void printMenu() {
    std::cout << "\n===== ����������� ������� �������� =====\n";
    std::cout << "1. ����������� ��� � �����" << std::endl;
    std::cout << "2. ����� �� ��������" << std::endl;
    std::cout << "3. ����� �� ������ ���������� ������" << std::endl;
    std::cout << "4. ������� ���� �������" << std::endl;
    std::cout << "5. ������ ����� �����" << std::endl;
    std::cout << "6. �������� �����" << std::endl;
    std::cout << "7. ��������� ������ (����������)" << std::endl;
    std::cout << "��� ����: ";
}

int main() {
    system("chcp 1251 && cls");
    PostalRecord* head = nullptr;
    bool dataLoaded = false;
    int choice;
    std::string filename = "data.txt"; // ���� �� �������������

    while (true) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::cout << "������ ��'� ����� ��� ������������: ";
                std::getline(std::cin, filename);
                if (Kurtiak::loadData(filename, head)) {
                    std::cout << "��� ������ ���������� � '" << filename << "'\n";
                    dataLoaded = true;
                } else {
                    std::cout << "������� ������������ ����� '" << filename << "'\n";
                }
                break;
            }

            case 2: {
                if (!dataLoaded) { std::cout << "�������� ���������� ���.\n"; break; }
                int idx;
                std::cout << "������ ������ (�'����������): ";
                std::cin >> idx;
                auto results = Kurtiak::searchByIndex(head, idx);
                if (results.empty()) {
                    std::cout << "������ � �������� " << idx << " �� ��������.\n";
                } else {
                    std::cout << "�������� " << results.size() << " �����(��):\n";
                    for (auto* rec : results) {
                        std::cout << rec->index << " "
                                  << rec->region << " "
                                  << rec->district << " "
                                  << rec->city << " "
                                  << rec->postOffice << "\n";
                    }
                }
                break;
            }

            case 3: {
                if (!dataLoaded) { std::cout << "�������� ���������� ���.\n"; break; }
                std::string city;
                std::cout << "������ ����� ���������� ������: ";
                std::getline(std::cin, city);
                std::vector<PostalRecord*> found;
                for (PostalRecord* cur = head; cur; cur = cur->next) {
                    if (cur->city == city) found.push_back(cur);
                }
                if (found.empty()) {
                    std::cout << "������ ��� ���� '" << city << "' �� ��������.\n";
                } else {
                    std::cout << "�������� " << found.size() << " �����(��) ��� '" << city << "':\n";
                    for (auto* rec : found) {
                        std::cout << rec->index << " "
                                  << rec->region << " "
                                  << rec->district << " "
                                  << rec->city << " "
                                  << rec->postOffice << "\n";
                    }
                }
                break;
            }

            case 4: {
                if (!dataLoaded) { std::cout << "�������� ���������� ���.\n"; break; }
                Marchenko::printAll(head);
                break;
            }


            case 5: {
                if (!dataLoaded) { std::cout << "�������� ���������� ���.\n"; break; }
                PostalRecord temp{};
                std::cout << "������ ���� Index: "; std::cin >> temp.index; std::cin.ignore();
                std::cout << "Region: "; std::getline(std::cin, temp.region);
                std::cout << "District: "; std::getline(std::cin, temp.district);
                std::cout << "City: "; std::getline(std::cin, temp.city);
                std::cout << "PostOffice: "; std::getline(std::cin, temp.postOffice);
                if (Ivanov::addRecord(head, temp))
                    std::cout << "����� ������ ������.\n";
                else
                    std::cout << "������� ��� �������� ������.\n";
                break;
            }

            case 6: {
                if (!dataLoaded) { std::cout << "�������� ���������� ���.\n"; break; }
                int delIdx; std::string delCity;
                std::cout << "������ ������ ��� ���������: "; std::cin >> delIdx; std::cin.ignore();
                std::cout << "������ ���� ��� ���������: "; std::getline(std::cin, delCity);
                if (Ivanov::deleteRecord(head, delIdx, delCity))
                    std::cout << "����� ��������.\n";
                else
                    std::cout << "�� ������� �������� �����.\n";
                break;
            }

            case 7: {
                if (Marchenko::saveAndExit(head, filename))
                    std::cout << "��� ��������� � '" << filename << "'. �� ���������!\n";
                else
                    std::cout << "������� ���������� ����� '" << filename << "'.\n";
                // ��������� ���'��
                while (head) {
                    PostalRecord* tmp = head;
                    head = head->next;
                    delete tmp;
                }
                return 0;
            }

            default:
                std::cout << "������� ����. ��������� �� ���.\n";
        }
    }

    return 0;
}
