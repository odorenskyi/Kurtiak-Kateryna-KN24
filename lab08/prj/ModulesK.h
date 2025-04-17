#ifndef MODULESKURTIAK_H_INCLUDED
#define MODULESKURTIAK_H_INCLUDED

#include <string>

double s_calculation(double x, double y, double z);
std::string task_9_1(double s_v);

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius);

// Function to count bits based on D7 bit value
int countBits(int N);

void processTask10_1(const std::string& inputFile, const std::string& outputFile);

void appendFileSizeAndTimestamp(const std::string& filename);

// === ЗАДАЧА 10.3 ===
int s_calculation(int x, int y, int z); // умовна функція з Modules/Прізвище.h
std::string toBinary(int number);
void writeTask10_3Data(std::ofstream& outFile, int x, int y, int z, int b);


#endif // MODULESKURTIAK_H_INCLUDED
