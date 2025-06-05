#ifndef MODULESKURTIAK_H_INCLUDED
#define MODULESKURTIAK_H_INCLUDED
#include "STRUCT_TYPE_PROJECT_8_H.h"
#include <fstream>

PostalDatabase::~PostalDatabase();
void PostalDatabase::clearList();
void PostalDatabase::addRecord(const PostalRecord& record);
bool PostalDatabase::deleteRecord(int index);
bool PostalDatabase::loadFromFile(const std::string& filename);
bool PostalDatabase::saveToFile(const std::string& filename);
bool PostalDatabase::isEmpty()  const;
void PostalDatabase::clear();

#endif // MODULESKURTIAK_H_INCLUDED
