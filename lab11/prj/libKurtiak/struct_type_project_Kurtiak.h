#ifndef STRUCT_TYPE_PROJECT_Kurtiak_H_INCLUDED
#define STRUCT_TYPE_PROJECT_Kurtiak_H_INCLUDED

#pragma once
#include "struct_type_project_8.h"
#include <vector>

namespace Kurtiak {
    // ������������ ����� � ����� � �������� ���������
    bool loadData(const std::string& filename, PostalRecord*& head);
    // ����� ��� ������ �� ������� ��������
    std::vector<PostalRecord*> searchByIndex(PostalRecord* head, int index);
}

#endif // STRUCT_TYPE_PROJECT_Kurtiak_H_INCLUDED
