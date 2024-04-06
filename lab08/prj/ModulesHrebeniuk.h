#ifndef MODULESHREBENIUK_H_INCLUDED
#define MODULESHREBENIUK_H_INCLUDED

#define MONTH_IN_YEAR 12

struct Temperature {
  float celsius;
  float fahrenheit;
};

// Laboratory work �8
float s_calculation(int, int, int);

// Laboratory work �9
float calculateElectricityConsume(int);
Temperature averageYearTemperature(int averageMonthTemperature[MONTH_IN_YEAR]);
unsigned int countBinaryZerosOrOnes(unsigned int);

// Laboratory work �10
void taskTenthPointOne(std::string, std::string);
void taskTenthPointTwo(std::string);
void taskTenthPointThree(int, int, int, unsigned int, std::string);

#endif // MODULESHREBENIUK_H_INCLUDED
