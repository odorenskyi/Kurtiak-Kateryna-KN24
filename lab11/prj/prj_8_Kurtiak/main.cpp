#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "struct_type_project_8.h"         // Опис PostalRecord
#include "struct_type_project_Kurtiak.h"   // loadData, searchByIndex
#include "struct_type_project_Ivanov.h"    // addRecord, deleteRecord
#include "struct_type_project_Marchenko.h" // printAll, saveAndExit

void printMenu() {
    std::cout << "\n===== Електронний довідник Укрпошти =====\n";
    std::cout << "1. Завантажити дані з файлу" << std::endl;
    std::cout << "2. Пошук за індексом" << std::endl;
    std::cout << "3. Пошук за назвою населеного пункту" << std::endl;
    std::cout << "4. Вивести весь довідник" << std::endl;
    std::cout << "5. Додати новий запис" << std::endl;
    std::cout << "6. Видалити запис" << std::endl;
    std::cout << "7. Завершити роботу (збереження)" << std::endl;
    std::cout << "Ваш вибір: ";
}

int main() {
    system("chcp 1251 && cls");
    PostalRecord* head = nullptr;
    bool dataLoaded = false;
    int choice;
    std::string filename = "data.txt"; // Файл за замовчуванням

    while (true) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::cout << "Введіть ім'я файлу для завантаження: ";
                std::getline(std::cin, filename);
                if (Kurtiak::loadData(filename, head)) {
                    std::cout << "Дані успішно завантажені з '" << filename << "'\n";
                    dataLoaded = true;
                } else {
                    std::cout << "Помилка завантаження файлу '" << filename << "'\n";
                }
                break;
            }

            case 2: {
                if (!dataLoaded) { std::cout << "Спочатку завантажте дані.\n"; break; }
                int idx;
                std::cout << "Введіть індекс (п'ятизначний): ";
                std::cin >> idx;
                auto results = Kurtiak::searchByIndex(head, idx);
                if (results.empty()) {
                    std::cout << "Записів з індексом " << idx << " не знайдено.\n";
                } else {
                    std::cout << "Знайдено " << results.size() << " запис(ів):\n";
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
                if (!dataLoaded) { std::cout << "Спочатку завантажте дані.\n"; break; }
                std::string city;
                std::cout << "Введіть назву населеного пункту: ";
                std::getline(std::cin, city);
                std::vector<PostalRecord*> found;
                for (PostalRecord* cur = head; cur; cur = cur->next) {
                    if (cur->city == city) found.push_back(cur);
                }
                if (found.empty()) {
                    std::cout << "Записів для міста '" << city << "' не знайдено.\n";
                } else {
                    std::cout << "Знайдено " << found.size() << " запис(ів) для '" << city << "':\n";
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
                if (!dataLoaded) { std::cout << "Спочатку завантажте дані.\n"; break; }
                Marchenko::printAll(head);
                break;
            }


            case 5: {
                if (!dataLoaded) { std::cout << "Спочатку завантажте дані.\n"; break; }
                PostalRecord temp{};
                std::cout << "Введіть поле Index: "; std::cin >> temp.index; std::cin.ignore();
                std::cout << "Region: "; std::getline(std::cin, temp.region);
                std::cout << "District: "; std::getline(std::cin, temp.district);
                std::cout << "City: "; std::getline(std::cin, temp.city);
                std::cout << "PostOffice: "; std::getline(std::cin, temp.postOffice);
                if (Ivanov::addRecord(head, temp))
                    std::cout << "Запис додано успішно.\n";
                else
                    std::cout << "Помилка при додаванні запису.\n";
                break;
            }

            case 6: {
                if (!dataLoaded) { std::cout << "Спочатку завантажте дані.\n"; break; }
                int delIdx; std::string delCity;
                std::cout << "Введіть індекс для видалення: "; std::cin >> delIdx; std::cin.ignore();
                std::cout << "Введіть місто для видалення: "; std::getline(std::cin, delCity);
                if (Ivanov::deleteRecord(head, delIdx, delCity))
                    std::cout << "Запис видалено.\n";
                else
                    std::cout << "Не вдалося видалити запис.\n";
                break;
            }

            case 7: {
                if (Marchenko::saveAndExit(head, filename))
                    std::cout << "Дані збережено у '" << filename << "'. До побачення!\n";
                else
                    std::cout << "Помилка збереження файлу '" << filename << "'.\n";
                // Звільнення пам'яті
                while (head) {
                    PostalRecord* tmp = head;
                    head = head->next;
                    delete tmp;
                }
                return 0;
            }

            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }

    return 0;
}
