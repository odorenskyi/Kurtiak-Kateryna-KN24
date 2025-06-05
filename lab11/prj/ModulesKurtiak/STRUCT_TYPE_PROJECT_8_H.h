#ifndef STRUCT_TYPE_PROJECT_8_H_H_INCLUDED
#define STRUCT_TYPE_PROJECT_8_H_H_INCLUDED


#include <string>
#include <iostream>
#include <fstream>

// ��������� ��� ��������� ���������� ��� ������� ��������
struct PostalRecord {
    int index;                  // �'���������� ������
    std::string region;         // �������
    std::string district;       // �����
    std::string city;           // ��������� �����
    std::string postal_office;  // ���, �� ���������

    // ����������� �� �������������
    PostalRecord() : index(0) {}

    // ����������� � �����������
    PostalRecord(int idx, const std::string& reg, const std::string& dist,
                 const std::string& c, const std::string& office)
    : index(idx), region(reg), district(dist), city(c), postal_office(office) {}

    // �������� ��������� ��� �������� �����������
    friend std::ostream& operator<<(std::ostream& os, const PostalRecord& record) {
        os << "������: " << record.index
        << ", �������: " << record.region
        << ", �����: " << record.district
        << ", ̳���: " << record.city
        << ", ���: " << record.postal_office;
        return os;
    }

    // �������� ��������� ��� ������
    bool operator==(const PostalRecord& other) const {
        return index == other.index;
    }
};

// ����� �����'������ ������
struct ListNode {
    PostalRecord data;     // ��� ������
    ListNode* next;        // �������� �� ��������� �������
    ListNode* prev;        // �������� �� ��������� �������

    // ����������� �� �������������
    ListNode() : next(nullptr), prev(nullptr) {}

    // ����������� � ������
    ListNode(const PostalRecord& record)
    : data(record), next(nullptr), prev(nullptr) {}

    // ����������
    ~ListNode() {
        // ����������� �������� ���'�� ��� �����
    }
};

// ���� ��� ��������� �����'����� ������� �������� ������
class PostalDatabase {
private:
    ListNode* head;        // �������� �� ������� ������
    ListNode* tail;        // �������� �� ����� ������
    int size;              // ʳ������ �������� � ������

    // ��������� ����� ��� �������� ������ ������
    void clearList();

public:
    PostalDatabase();

    ~PostalDatabase();

    // �������� ��������� (��� ������� ���'��)
    PostalDatabase(const PostalDatabase&) = delete;
    PostalDatabase& operator=(const PostalDatabase&) = delete;

    // ������ �������� ��� �������

    // �������, �� �������������� ������:
    bool loadFromFile(const std::string& filename);        // ������������ � �������� �����
    bool saveToFile(const std::string& filename);          // ���������� � ������� ����
    void exportToFile(const std::string& filename) const;  // ������� � ��������� ����

    // �������, �� �������������� ��������:
    ListNode* searchByIndex(int index);                    // ����� �� ��������
    ListNode* searchByCity(const std::string& city);       // ����� �� �����
    void displayAll() const;                               // ��������� ��� ������ �� �����

    // �������, �� �������������� ������:
    void addRecord(const PostalRecord& record);            // ��������� ������
    bool deleteRecord(int index);                          // ��������� ������ �� ��������

    // ������� ������� (�����)
    int getSize() const;                                   // ��������� ������ ������
    bool isEmpty() const;                                  // �������� �� ������ �������
    void clear();                                          // �������� ������ ������

    // ������� ��� ������ � ����������� (��� ��������)
    ListNode* getFirst() const { return head; }
    ListNode* getLast() const { return tail; }

    // ������� ��� �������� �������
    static bool isValidIndex(int index) {
        return index >= 10000 && index <= 99999;
    }

    // ������� ��� ��������� ����������
    void printStatistics() const;
};


// ������� ������� ��� ������ � ������� �� ��������
namespace PostalUtils {
    // ������� ��� �������� ����� ������
    bool validateRecord(const PostalRecord& record);

    // ������� ��� ������������ ���������
    std::string formatRecord(const PostalRecord& record);

    // ������� ��� �������� ����� � �����
    PostalRecord parseRecord(const std::string& line);

    // ������� ��� ��������� �������� ��ﳿ
    bool createBackup(const std::string& filename);
}

// ��������� ��� ������ ��������
namespace PostalConstants {
    const std::string DEFAULT_FILENAME = "postal_database.dat";
    const std::string BACKUP_EXTENSION = ".backup";
    const std::string EXPORT_EXTENSION = ".txt";
    const int MAX_RECORDS = 100000;  // ����������� ������� ������
    const int MIN_INDEX = 10000;     // ̳�������� ������
    const int MAX_INDEX = 99999;     // ������������ ������
}




#endif // STRUCT_TYPE_PROJECT_8_H_H_INCLUDED
