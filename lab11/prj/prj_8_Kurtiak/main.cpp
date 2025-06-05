#include <iostream>
#include "STRUCT_TYPE_PROJECT_8_H.h"
#include "ModulesKurtiak.h"

int main() {
    PostalDatabase db;

    // Завантаження з файлу при запуску
    if (db.loadFromFile(PostalConstants::DEFAULT_FILENAME)) {
        std::cout << "Дані завантажено успішно.\n";
    } else {
        std::cout << "Файл не знайдено або порожній.\n";
    }

    // Додавання нового запису
    PostalRecord rec1(25006, "Кіровоградська", "Кропивницький", "Кропивницький", "ВПЗ 6");
    db.addRecord(rec1);
    std::cout << "Запис додано.\n";

    // Видалення запису за індексом
    if (db.deleteRecord(25006)) {
        std::cout << "Запис успішно видалено.\n";
    } else {
        std::cout << "Запис з таким індексом не знайдено.\n";
    }

    return 0;
}
