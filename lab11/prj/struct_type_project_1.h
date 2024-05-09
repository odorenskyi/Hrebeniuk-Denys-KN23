#ifndef STRUCT_TYPE_PROJECT_1_H_INCLUDED
#define STRUCT_TYPE_PROJECT_1_H_INCLUDED

struct CarRecord {
  std::string lastName;
  std::string firstName;
  std::string middleName;
  std::string carBrand;
  int year;
  std::string registrationDate;
  std::string licensePlate;
  std::string notes;
};

struct Node {
  CarRecord data;
  Node * previous;
  Node * next;
};

Node * loadRegisterData(std::string registerFileName);
void outputRegisterData(Node *head, std::string outputFileName = "");
void addCarInRegister(Node *head);
void searchCarInRegister(Node *head, std::string stateLicensePlate);
void removeCarFromRegister(Node *head, std::string stateLicensePlate);
void saveRegisterData(Node *head, std::string registerFileName);

#endif // STRUCT_TYPE_PROJECT_1_H_INCLUDED