#include <iostream>
#include "ModulesHrebeniuk.h"

using namespace std;

void test_tc(int test_case, int x, int y, int z, float expected) {
    cout << "Тест-кейс №" << test_case << endl;
    cout << "Вхідні дані:\nx: " << x << "\ny: " << y << "\nz: " << z << endl;

    float result = s_calculation(x, y, z);
    cout << "Результат: " << result << endl;

    if (result == expected) {
        cout << "Статус тест-кейса: passed" << endl;
    } else {
        cout << "Статус тест-кейса: failed" << endl;
    }

    cout << endl;
}

int main() {
    system("chcp 65001 & cls");

    test_tc(1, 5, -27, -21, 532048248832);
    test_tc(2, -20, 28, -24, 1446257098752);
    test_tc(3, 27, 21, 15, 1318815744);
    test_tc(4, 15, 4, 14, 87.865631103515625);
    test_tc(5, 27, -7, -25, 1156.3165283203125);
    test_tc(6, 16, 30, 16, 10686474223616);
    test_tc(7, 28, -28, 16, 1446257098752);
    test_tc(8, 10, -17, -18, 24154966);
    test_tc(9, 20, -17, 30, 24154986);
    test_tc(10, -25, 19, 23, 178482192);

    return 0;
}
