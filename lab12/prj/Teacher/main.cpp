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
            resultFile << "���������� ������ ������� ��������� ����������� ������ ��������!";
            resultFile.close();
        } else {
            std::cerr << "�� ������� ������� ���� ��� ������.";
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
            outputFile << "���� �" << testCase << endl;
            outputFile << "���� �������: " << testCap.getColor() << endl;
            outputFile << "������� �������: " << testCap.getPattern() << endl;
            outputFile << "������ �������: " << testCap.getHeight() << endl;
            outputFile << "����� ������ �������: " << testCap.getRadius() << endl;
            outputFile << "�ᒺ� �������: " << testCap.getVolume() << endl << endl;
        }

        cout << "������ ���������� ���������, ��������� ���������� � ���� TestResults.txt" << endl;
        system("pause");

        inputFile.close();
        outputFile.close();
    }

    return 0;
}
