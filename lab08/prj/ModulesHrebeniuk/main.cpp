#include <cmath>
#include "ModulesHrebeniuk.h"

using namespace std;

// Laboratory work ¹8
float s_calculation(int x, int y, int z) {
  float S = M_PI * x + pow(M_E, abs(y)) - sqrt(abs(pow(z, 2) - y));
  return S;
}

// Laboratory work ¹9
float calculateElectricityConsume(int kWh) {
  float sum = 0.0;

  if (kWh > 0 && kWh <= 150) {
    sum = kWh * 130.843;
  } else if (kWh > 150 && kWh <= 800) {
    sum = kWh * 241.945;
  } else if (kWh > 800) {
    sum = kWh * 534.047;
  }

  return sum;
}

Temperature averageYearTemperature(int averageMonthTemperature[MONTH_IN_YEAR]) {
  Temperature averageYearTemperature;

  int totalMonthTemperature = 0;
  for (int i = 0; i < MONTH_IN_YEAR; ++i) {
    totalMonthTemperature += averageMonthTemperature[i];
  }

  averageYearTemperature.celsius = (float)totalMonthTemperature / MONTH_IN_YEAR;
  averageYearTemperature.fahrenheit =
      32 + (9.0 / 5) * averageYearTemperature.celsius;

  return averageYearTemperature;
}

unsigned int countBinaryZerosOrOnes(unsigned int N) {
  if (N > 0 && N < 5740500) {
    unsigned int tenthBit = (N >> 9) & 1;
    unsigned int result = 0;

    for (int i = 0; i < sizeof(N) * 8; i++) {
      result += ((N & 1) == tenthBit) ? 1 : 0;
      N = N >> 1;
    }

    return result;
  } else {
    return -1;
  }
}
