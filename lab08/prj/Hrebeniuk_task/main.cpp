#include <iostream>
#include "Copyright.h"
#include "ModulesHrebeniuk.h"

using namespace std;

bool getBoolResult(char a, char b)
{
    cout << boolalpha;
    return (a + 5 >= b);
}

int getHexadecimal(int number)
{
    cout << hex;
    return number;
}

int main()
{
    cout << printCopyright() << endl;

    int x;
    cout << "Уведіть x: ";
    cin >> x;

    int y;
    cout << "Уведіть y: ";
    cin >> y;

    int z;
    cout << "Уведіть z: ";
    cin >> z;

    char a;
    cout << "Уведіть a: ";
    cin >> a;

    char b;
    cout << "Уведіть b: ";
    cin >> b;

    cout << "\n" << "Результат логічного виразу: " << getBoolResult(a, b) << endl;
    cout << "\nx (в десятковій): " << x << "\ny (в десятковій): " << y << "\nz (в десятковій): " << z << endl;
    cout << "\nx (в шістнадцятковій): " << getHexadecimal(x) << "\ny (в шістнадцятковій): " << getHexadecimal(y) << "\nz (в шістнадцятковій): " << getHexadecimal(z) << endl;
    cout << "\nS = " << s_calculation(x, y, z) << endl;

    return 0;
}
