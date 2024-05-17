#include <iostream>
#include <Windows.h>
#include <fstream>
#include <sstream>

#include "ModulesHrebeniuk.h"

#define TEST_SUITE_FILE "..\\..\\TestSuite\\TestSuite.txt"
#define TEST_RESULTS_FILE "..\\..\\TestSuite\\TestResults.txt"

using namespace std;

int main()
{
    system("chcp 1251 & cls");

    string currentFilePath = __FILE__;
    int checkResult = currentFilePath.find("\\lab12\\prj\\");
    if (checkResult == -1) {
        for (int i = 0; i < 100; ++i) {
            Beep(500, 100);
        }

        ofstream resultFile(TEST_RESULTS_FILE);
        if (resultFile.is_open()) {
            resultFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";
            resultFile.close();
        } else {
            std::cerr << "Не вдалося відкрити файл для запису.";
            return 1;
        }
    } else {
        ifstream inputFile(TEST_SUITE_FILE);
        ofstream outputFile(TEST_RESULTS_FILE);
        string line;
        int testCase = 0;

        while (getline(inputFile, line)) {
            stringstream ss(line);
            string color;
            string pattern;
            float height;
            float radius;

            getline(ss, color, '|');
            getline(ss, pattern, '|');
            ss >> height;
            ss.ignore(1, '|');
            ss >> radius;

            ClassLab12_Hrebeniuk testCap = ClassLab12_Hrebeniuk(color, pattern, height, radius);

            testCase += 1;
            outputFile << "Тест №" << testCase << endl;
            outputFile << "Колір ковпака: " << testCap.getColor() << endl;
            outputFile << "Малюнок ковпака: " << testCap.getPattern() << endl;
            outputFile << "Висота ковпака: " << testCap.getHeight() << endl;
            outputFile << "Радіус основи ковпака: " << testCap.getRadius() << endl;
            outputFile << "Об’єм ковпака: " << testCap.getVolume() << endl << endl;
        }

        cout << "Роботу застосунку завершено, результат збережений у файлі TestResults.txt" << endl;
        system("pause");

        inputFile.close();
        outputFile.close();
    }

    return 0;
}
