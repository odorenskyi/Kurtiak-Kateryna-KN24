#include <bitset>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <vector>
#include <filesystem> // Include for std::filesystem
#include <ctime>       // Include for time functions
#include "ModulesK.h"


// Функція для обчислення S відповідно до формули варіанту 25
double s_calculation(double x, double y, double z) { // Ensure the function accepts double arguments
    return fabs(sqrt(fabs(z - 2 * x)) - x * sin(pow(x, 2 * z) * y));
}



std::string task_9_1(double s_v) {

    if (s_v < 0.3)
        return "Бал Босфорта: 0. Відсутність вітру. Дим піднімається прямовисто. Листя дерев нерухомі.";
    else if (s_v > 0.3 && s_v <= 1.5)
        return "Бал Босфорта: 1. Дим 'пливе'. Флюгер не обертається.";
    else if (s_v > 1.5 && s_v <= 3.4)
        return "Бал Босфорта: 2. Рух повітря відчувається обличчям. Шелестить листя. Флюгери обертаються.";
    else if (s_v > 3.4 && s_v <= 5.4)
        return "Бал Босфорта: 3. Тріпоче листя, хитаються дрібні гілки. Майорять прапори.";
    else if (s_v > 5.4 && s_v <= 7.9)
        return "Бал Босфорта: 4. Хитаються тонкі гілки дерев. Вітер піднімає пил та шматки паперу.";
    else if (s_v > 7.9 && s_v <= 10.7)
        return "Бал Босфорта: 5. Хитаються великі гілки. На воді з'являються хвилі.";
    else if (s_v > 10.7 && s_v <= 13.8)
        return "Бал Босфорта: 6. Хитаються великі гілки.";
    else if (s_v > 13.8 && s_v <= 17.1)
        return "Бал Босфорта: 7. Хитаються невеликі стовбури дерев. На морі здіймаються хвилі, піняться.";
    else if (s_v > 17.1 && s_v <= 20.7)
        return "Бал Босфорта: 8. Ламаються гілки дерев. Важко йти проти вітру.";
    else if (s_v > 20.7 && s_v <= 24.4)
        return "Бал Босфорта: 9. Невелике руйнування. Зриває покрівлі, руйнує димарі.";
    else if (s_v > 24.4 && s_v <= 28.4)
        return "Бал Босфорта: 10. Значні руйнування. Дерева вириваються з корінням.";
    else if (s_v > 28.4 && s_v <= 32.6)
        return "Бал Босфорта: 11. Великі руйнування.";
    else if (s_v > 32.6)
        return "Бал Босфорта: 12. Призводить до спустошень.";
    return ""; // Ensure function always returns a value
}


double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

int countBits(int N) {
    std::bitset<16> bin(N);
    bool D7 = bin[7];
    return D7 ? bin.count() : (16 - bin.count());
}

//10.1
void processTask10_1(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Помилка відкриття файлів!" << std::endl;
        return;
    }

    // Авторська інформація
    outFile << "Автор: Куртяк Катерина, ЦНТУ, Україна, 2025" << std::endl;

    // Читання всіх рядків
    std::vector<std::string> lines;
    std::string line;
    std::locale ukrainianLocale(""); // Use the system's default locale
    while (std::getline(inFile, line)) {
        lines.push_back(line);
        int uppercaseCount = 0;
        for (char ch : line) {
            if (std::isupper(ch, ukrainianLocale)) { // Use the default locale for isupper
                ++uppercaseCount;
            }
        }
        outFile << "У рядку \"" << line << "\" — " << uppercaseCount << " символ(ів) верхнього регістру." << std::endl;
    }

    // Перевірка на вірш
    std::vector<std::string> poem = {
        "Коли малим ти вперше став на ноги —",
        "Яка ж то радість матері була!",
        "Від тихої колиски до порога",
        "Вона тебе за руку провела.",
        "Вона прибігла стомлена з роботи,",
        "І, може, сон їй очі замикав,",
        "А дома - новий клопіт і турботи,",
        "І дюжа низка непочатих справ."
    };

    bool found = false;
    for (const auto& inputLine : lines) {
        for (const auto& poemLine : poem) {
            if (inputLine == poemLine) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        outFile << "У файлі знайдено рядок з вірша Василя Симоненка." << std::endl;
    } else {
        outFile << "У файлі не знайдено рядків з вірша." << std::endl;
    }

    inFile.close();
    outFile.close();
}

// === ЗАДАЧА 10.2 ===

void appendFileSizeAndTimestamp(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile.is_open()) return;

    auto size = std::filesystem::file_size(filename); // Use std::filesystem for file size
    std::time_t now = std::time(nullptr);             // Use std::time for current time
    char timeStr[100];
    std::strftime(timeStr, sizeof(timeStr), "%d.%m.%Y %H:%M:%S", std::localtime(&now)); // Format time

    outFile << "Розмір файлу: " << size << " байт." << std::endl;
    outFile << "Дата та час допису: " << timeStr << std::endl;
    outFile.close();
}

// === ЗАДАЧА 10.3 ===
std::string toBinary(int number) {
    std::string binary;
    while (number > 0) {
        binary = std::to_string(number % 2) + binary;
        number /= 2;
    }
    return binary.empty() ? "0" : binary;
}

void writeTask10_3Data(std::ofstream& outFile, int x, int y, int z, int b) {
    double result = s_calculation(static_cast<double>(x), static_cast<double>(y), static_cast<double>(z)); // Cast to double
    std::string binary = toBinary(b);

    outFile << "Результат функції s_calculation(" << x << "," << y << "," << z << ") = " << result << std::endl;
    outFile << "Число " << b << " у двійковій системі: " << binary << std::endl;
}


