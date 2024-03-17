#include <iostream>
#include <conio.h>
#include "Copyright.h"
#include "ModulesHrebeniuk.h"

using namespace std;

int main()
{
    char task;

    do {
        cout << printCopyright() << endl;

        cout << "Оберіть функцію, що бажаєте виконати (\"n\", \"v\", \"c\", \"x\"): ";
        cin >> task;
        cout << endl;

        switch (task) {
            case 'n': {
                int x;
                cout << "x: ";
                cin >> x;

                int y;
                cout << "y: ";
                cin >> y;

                int z;
                cout << "z: ";
                cin >> z;

                cout << "Результат функції s_calculation(): " << s_calculation(x, y, z) << endl;
                break;
            }
            case 'v': {
                int kWh;
                cout << "kWh: ";
                cin >> kWh;

                cout << "Результат функції 9.1: " << calculateElectricityConsume(kWh) << endl;
                break;
            }
            case 'c': {
                int averageMonthTemperature[MONTH_IN_YEAR];
                for (int i = 0; i < MONTH_IN_YEAR; i++) {
                    cout << "Введіть середню температуру за " << i + 1 << "-ий місяць: ";
                    cin >> averageMonthTemperature[i];
                }
                cout << endl;

                Temperature result = averageYearTemperature(averageMonthTemperature);
                cout << "Результат функції 9.2:" << "\nCelsius: " << result.celsius << "\nFahrenheit: " << result.fahrenheit << endl;
                break;
            }
            case 'x': {
                unsigned int N;
                cout << "N: ";
                cin >> N;

                cout << "Результат функції 9.3: " << countBinaryZerosOrOnes(N) << endl;
                break;
            }
            default: {
                cout << "\aВи вказали неіснуючу функцію, спробуйте ще раз!" << endl;
                break;
            }
        }

        cout << "\nНатисніть \"z\" або \"Z\" для повторення виконання програми";
        task = getch();
    } while (task == 'z' || task == 'Z');

    return 0;
}
