#include <iostream>
#include <conio.h>
#include <string>
#include "ModulesHrebeniuk.h"

using namespace std;

#define TEST_CASES_COUNT 5

void testFirstTask(int test_case, string inputFileName, string outputFileName) {
    cout << "Тест-кейс №" << test_case << endl;
    cout << "Вхідні дані:\ninputFileName: " << inputFileName << "\noutputFileName: " << outputFileName << endl;

    taskTenthPointOne(inputFileName, outputFileName);
    cout << "Відкрийте модифікований файл та порівняйте з текстом із поля Expected Result. Співпадає? (y/n): " ;
    char checkResult = getch();

    if (checkResult == 'y' || checkResult == 'Y') {
        cout << endl << "Статус тест-кейса: passed" << endl;
    } else {
        cout << endl << "Статус тест-кейса: failed" << endl;
    }

    cout << endl;
}

void testSecondTask(int test_case, string inputFileName) {
    cout << "Тест-кейс №" << test_case << endl;
    cout << "Вхідні дані:\ninputFileName: " << inputFileName << endl;

    taskTenthPointTwo(inputFileName);
    cout << "Відкрийте модифікований файл та порівняйте з текстом із поля Expected Result. Співпадає? (y/n): " ;
    char checkResult = getch();

    if (checkResult == 'y' || checkResult == 'Y') {
        cout << endl << "Статус тест-кейса: passed" << endl;
    } else {
        cout << endl << "Статус тест-кейса: failed" << endl;
    }

    cout << endl;
}

void testThirdTask(int test_case, int x, int y, int z, unsigned int b, string outputFileName) {
    cout << "Тест-кейс №" << test_case << endl;
    cout << "Вхідні дані: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;
    cout << "b: " << b << endl;
    cout << "outputFileName: " << outputFileName << endl;

    taskTenthPointThree(x, y, z, b, outputFileName);
    cout << "Відкрийте модифікований файл та порівняйте з текстом із поля Expected Result. Співпадає? (y/n): " ;
    char checkResult = getch();

    if (checkResult == 'y' || checkResult == 'Y') {
        cout << endl << "Статус тест-кейса: passed" << endl;
    } else {
        cout << endl << "Статус тест-кейса: failed" << endl;
    }

    cout << endl;
}

int main()
{
    system("chcp 1251 & cls");

    // Task 10.1
    cout << "=== TS_10_1 ===" << endl;
    const string firstTaskTCData[TEST_CASES_COUNT][2] = {
        {"input_1.txt", "output_1.txt"},
        {"input_2.txt", "output_2.txt"},
        {"input_3.txt", "output_3.txt"},
        {"input_1.txt", "output_4.txt"},
        {"input_4.txt", "output_1.txt"}
    };
    for (int i = 0; i < TEST_CASES_COUNT; i++) {
        testFirstTask(i + 1, firstTaskTCData[i][0], firstTaskTCData[i][1]);
    }

    // Task 10.2
    cout << "=== TS_10_2 ===" << endl;
    const string secondTaskTCData[TEST_CASES_COUNT] = {
        "input_1.txt",
        "input_2.txt",
        "input_3.txt",
        "input_1.txt",
        "input_4.txt"
    };
    for (int i = 0; i < TEST_CASES_COUNT; i++) {
        testSecondTask(i + 1, secondTaskTCData[i]);
    }

    // Task 10.3
    cout << "=== TS_10_3 ===" << endl;
    const string thirdTaskTCData[TEST_CASES_COUNT][5] = {
        {"5", "-27", "-21", "90", "output_1.txt"},
        {"-20", "28", "-24", "2024", "output_2.txt"},
        {"27", "21", "15", "912012", "output_3.txt"},
        {"15", "4", "14", "1007", "output_1.txt"},
        {"27", "-7", "-25", "128", "output_4.txt"}
    };
    for (int i = 0; i < TEST_CASES_COUNT; i++) {
        testThirdTask(i + 1, stoi(thirdTaskTCData[i][0]), stoi(thirdTaskTCData[i][1]), stoi(thirdTaskTCData[i][2]), stoi(thirdTaskTCData[i][3]), thirdTaskTCData[i][4]);
    }

    system("pause");
    return 0;
}
