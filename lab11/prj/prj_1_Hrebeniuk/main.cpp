#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>

#include "struct_type_project_1.h"
#include "ModulesHrebeniuk.h"
#include "ModulesHoncharenko.h"
#include "ModulesKlui.h"

#define REGISTER_NAME "register_database"

using namespace std;

void displayMenu() {
    system("cls");
    cout << " ======================= ����� ��� ������ ========================= " << endl;
    cout << "| 1. ������ ��������� � �����                                      |" << endl;
    cout << "| 2. ����� ��������� �� �������                                     |" << endl;
    cout << "| 3. ��������� ��������� � ������ �� �������� ������               |" << endl;
    cout << "| 4. ������� �� ��� � ������                                      |" << endl;
    cout << "| 5. ����� � ��������                                                |" << endl;
    cout << " ==================================================================== " << endl;
    cout << "������� �����: ";
}


void exitApp(List *list) {
    delete list->head;
    delete list->tail;
    delete list;

    exit(0);
}

int main()
{
    system("chcp 1251 & cls");

    List *list = loadRegisterData(REGISTER_NAME);
    if (list == nullptr) {
        list = new List;
        list->head = nullptr;
        list->tail = nullptr;
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        system("cls");

        switch (choice) {
            case 1: {
                addCarInRegister(list);
                saveRegisterData(list, REGISTER_NAME);
                break;
            }
            case 2: {
                string searchLicensePlate;
                cout << "������ ����� ���� ��� ������: ";
                cin >> searchLicensePlate;

                if (searchLicensePlate.empty() || searchLicensePlate.size() > 10) {
                    cout << "�������: �������� ���� �� ���� ���� ������� �� ���� ����������� ������� ������� ���� �� ����� 10 �������!" << endl;
                    break;
                }

                searchCarInRegister(list, searchLicensePlate);
                break;
            }
            case 3: {
                string removeLicensePlate;
                cout << "������ ����� ���� ��� ���������: ";
                cin >> removeLicensePlate;

                if (removeLicensePlate.empty() || removeLicensePlate.size() > 10) {
                    cout << "�������: �������� ���� �� ���� ���� ������� �� ���� ����������� ������� ������� ���� �� ����� 10 �������!" << endl;
                    break;
                }

                removeCarFromRegister(list, removeLicensePlate);
                saveRegisterData(list, REGISTER_NAME);
                break;
            }
            case 4: {
                outputRegisterData(list);
                break;
            }
            case 5: {
                cout << "�� ���������!" << endl;
                exitApp(list);
                break;
            }
            default:
                cout << "������� ����. ��������� �� ���." << endl;
        }

        cout << "���������� ������ ����������? (y/n): ";
        choice = getch();
    } while (choice == 'Y' || choice == 'y');

    exitApp(list);

    return 0;
}
