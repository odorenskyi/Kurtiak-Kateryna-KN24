#include "STRUCT_TYPE_PROJECT_8_H.h"
#include <fstream>
#include "ModulesKurtiak.h"

// === ����������� �� ���������� ===

PostalDatabase::PostalDatabase() : head(nullptr), tail(nullptr), size(0) {}

PostalDatabase::~PostalDatabase() {
    clearList();
}

// === �������� ������ ===

void PostalDatabase::clearList() {
    ListNode* current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
}

// === ��������� ������ ===

void PostalDatabase::addRecord(const PostalRecord& record) {
    ListNode* newNode = new ListNode(record);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++size;
    saveToFile(PostalConstants::DEFAULT_FILENAME);
}

// === ��������� ������ ===

bool PostalDatabase::deleteRecord(int index) {
    ListNode* current = head;
    while (current) {
        if (current->data.index == index) {
            if (current == head) {
                head = current->next;
                if (head) head->prev = nullptr;
            } else {
                current->prev->next = current->next;
            }

            if (current == tail) {
                tail = current->prev;
                if (tail) tail->next = nullptr;
            } else {
                current->next->prev = current->prev;
            }

            delete current;
            --size;
            saveToFile(PostalConstants::DEFAULT_FILENAME);
            return true;
        }
        current = current->next;
    }
    return false;
}

// === ������������ � ��������� ����� ===

bool PostalDatabase::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename, std::ios::binary);
    if (!fin) return false;

    clearList();
    int count = 0;
    fin.read(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i = 0; i < count; ++i) {
        int idx;
        std::string region, district, city, office;

        fin.read(reinterpret_cast<char*>(&idx), sizeof(int));

        std::getline(fin, region, '\0');
        std::getline(fin, district, '\0');
        std::getline(fin, city, '\0');
        std::getline(fin, office, '\0');

        PostalRecord rec(idx, region, district, city, office);
        addRecord(rec);
    }

    fin.close();
    return true;
}

// === ���������� �� ��������� ����� ===

bool PostalDatabase::saveToFile(const std::string& filename) {
    std::ofstream fout(filename, std::ios::binary);
    if (!fout) return false;

    fout.write(reinterpret_cast<const char*>(&size), sizeof(int));
    ListNode* current = head;

    while (current) {
        fout.write(reinterpret_cast<const char*>(&current->data.index), sizeof(int));

        fout.write(current->data.region.c_str(), current->data.region.size() + 1);
        fout.write(current->data.district.c_str(), current->data.district.size() + 1);
        fout.write(current->data.city.c_str(), current->data.city.size() + 1);
        fout.write(current->data.postal_office.c_str(), current->data.postal_office.size() + 1);

        current = current->next;
    }

    fout.close();
    return true;
}

// === ��������� ���̲�� ===

int PostalDatabase::getSize() const {
    return size;
}

bool PostalDatabase::isEmpty() const {
    return size == 0;
}

void PostalDatabase::clear() {
    clearList();
}
