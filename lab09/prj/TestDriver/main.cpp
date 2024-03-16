#include <iostream>
#include "ModulesHrebeniuk.h"

using namespace std;

void testFirstTask(int test_case, int kWh, float expected) {
    cout << "Тест-кейс №" << test_case << endl;
    cout << "Вхідні дані:\nkWh: " << kWh << endl;

    float result = calculateElectricityConsume(kWh);
    cout << "Результат: " << result << endl;

    if (result == expected) {
        cout << "Статус тест-кейса: passed" << endl;
    } else {
        cout << "Статус тест-кейса: failed" << endl;
    }

    cout << endl;
}

void testSecondTask(int test_case, int averageMonthTemperature[MONTH_IN_YEAR], Temperature expected) {
    cout << "Тест-кейс №" << test_case << endl;
    cout << "Вхідні дані:\naverageMonthTemperature: ";

    for (int i = 0; i < MONTH_IN_YEAR; i++) {
        cout << averageMonthTemperature[i];
        if (i != (MONTH_IN_YEAR - 1)) cout << ", ";
    }

    cout << endl;

    Temperature result = averageYearTemperature(averageMonthTemperature);
    cout << "Результат:" << endl;
    cout << "Celsius: " << result.celsius << endl;
    cout << "Fahrenheit: " << result.fahrenheit << endl;

    if (result.celsius == expected.celsius && result.fahrenheit == expected.fahrenheit) {
        cout << "Статус тест-кейса: passed" << endl;
    } else {
        cout << "Статус тест-кейса: failed" << endl;
    }

    cout << endl;
}

void testThirdTask(int test_case, unsigned int N, unsigned int expected) {
    cout << "Тест-кейс №" << test_case << endl;
    cout << "Вхідні дані:\nN: " << N << endl;

    unsigned int result = countBinaryZerosOrOnes(N);
    cout << "Результат: " << result << endl;

    if (result == expected) {
        cout << "Статус тест-кейса: passed" << endl;
    } else {
        cout << "Статус тест-кейса: failed" << endl;
    }

    cout << endl;
}

int main()
{
    system("chcp 65001 & cls");

    // Task 9.1
    cout << "=== TS_9_1 ===" << endl;
    testFirstTask(1, 130, 17009.58984375);
    testFirstTask(2, 151, 36533.6953125);
    testFirstTask(3, 515, 124601.671875);
    testFirstTask(4, -1, 0);
    testFirstTask(5, 0, 0);
    testFirstTask(6, 820, 437918.53125);
    testFirstTask(7, 155, 37501.4765625);
    testFirstTask(8, 80, 10467.4404296875);
    testFirstTask(9, 1500, 801070.5);
    testFirstTask(10, 1331, 710816.5625);

    // Task 9.2
    cout << "=== TS_9_2 ===" << endl;
    int testCasesInput[10][MONTH_IN_YEAR] = {
        {-6, 1, 20, -18, -7, 15, 25, -17, -28, 26, -30, 8},    // TC-01
        {-23, 29, -1, 4, 2, -13, 15, 1, 15, -10, 18, -15},     // TC-02
        {-6, 14, -5, -22, 12, -1, -30, -22, -29, 20, -10, -5}, // TC-03
        {4, -14, 10, 8, -19, 10, -13, -12, 9, 19, 23, -20},    // TC-04
        {-25, 9, 11, 22, -29, 0, -24, -3, -15, 3, 7, 30},      // TC-05
        {-27, 7, -23, -25, -1, -3, 0, -28, 15, -21, 13, 27},   // TC-06
        {22, 30, -16, 0, 18, -22, 10, 25, 20, -7, 16, 21},     // TC-07
        {25, 24, -11, -20, -1, 26, -21, 2, 4, -12, 9, -28},    // TC-08
        {17, -20, -25, 1, -8, 20, -3, -17, 19, 14, 13, 9},     // TC-09
        {24, -6, 5, 13, 19, -9, 5, 14, -14, 24, 26, 17}        // TC-10
    };
    Temperature testCasesOutput[10];

    testCasesOutput[0].celsius = -0.91666668653488159;
    testCasesOutput[0].fahrenheit = 30.350000381469727;
    testSecondTask(1, testCasesInput[0], testCasesOutput[0]);  // TC-01

    testCasesOutput[1].celsius = 1.8333333730697632;
    testCasesOutput[1].fahrenheit = 35.299999237060547;
    testSecondTask(2, testCasesInput[1], testCasesOutput[1]);  // TC-02

    testCasesOutput[2].celsius = -7;
    testCasesOutput[2].fahrenheit = 19.399999618530273;
    testSecondTask(3, testCasesInput[2], testCasesOutput[2]);  // TC-03

    testCasesOutput[3].celsius = 0.4166666567325592;
    testCasesOutput[3].fahrenheit = 32.75;
    testSecondTask(4, testCasesInput[3], testCasesOutput[3]);  // TC-04

    testCasesOutput[4].celsius = -1.1666666269302368;
    testCasesOutput[4].fahrenheit = 29.899999618530273;
    testSecondTask(5, testCasesInput[4], testCasesOutput[4]);  // TC-05

    testCasesOutput[5].celsius = -5.5;
    testCasesOutput[5].fahrenheit = 22.100000381469727;
    testSecondTask(6, testCasesInput[5], testCasesOutput[5]);  // TC-06

    testCasesOutput[6].celsius = 9.75;
    testCasesOutput[6].fahrenheit = 49.549999237060547;
    testSecondTask(7, testCasesInput[6], testCasesOutput[6]);  // TC-07

    testCasesOutput[7].celsius = -0.25;
    testCasesOutput[7].fahrenheit = 31.549999237060547;
    testSecondTask(8, testCasesInput[7], testCasesOutput[7]);  // TC-08

    testCasesOutput[8].celsius = 1.6666666269302368;
    testCasesOutput[8].fahrenheit = 35;
    testSecondTask(9, testCasesInput[8], testCasesOutput[8]);  // TC-09

    testCasesOutput[9].celsius = 9.8333330154418945;
    testCasesOutput[9].fahrenheit = 49.700000762939453;
    testSecondTask(10, testCasesInput[9], testCasesOutput[9]); // TC-10

    // Task 9.3
    cout << "=== TS_9_3 ===" << endl;
    testThirdTask(1, 2527920, 9);
    testThirdTask(2, 2840999, 19);
    testThirdTask(3, 5116662, 12);
    testThirdTask(4, 1280412, 22);
    testThirdTask(5, 1698360, 11);
    testThirdTask(6, 413992, 25);
    testThirdTask(7, 4027283, 14);
    testThirdTask(8, 5401843, 19);
    testThirdTask(9, 2933116, 21);
    testThirdTask(10, 5156645, 13);

    return 0;
}
