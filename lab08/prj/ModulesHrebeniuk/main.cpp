#include <cmath>
#include <fstream>
#include <ctime>
#include <bitset>

#include "ModulesHrebeniuk.h"

using namespace std;

// Laboratory work №8
float s_calculation(int x, int y, int z) {
  float S = M_PI * x + pow(M_E, abs(y)) - sqrt(abs(pow(z, 2) - y));
  return S;
}

// Laboratory work №9
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

// Laboratory work №10
void taskTenthPointOne(string inputFileName, string outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        return;
    }

    ofstream outputFile(outputFileName, ios::out | ios::trunc);
    outputFile << " ---------------------------------------------------------- " << endl;
    outputFile << "| Гребенюк Денис                                           |" << endl;
    outputFile << "| Центральноукраїнський національний технічний університет |" << endl;
    outputFile << "| м. Кропивницький, Україна                                |" << endl;
    outputFile << "| 2024                                                     |" << endl;
    outputFile << " ------------------ © All rights reserved ----------------- " << endl;
    outputFile << endl;

    int exclamationMarkCount = 0, questionMarkCount = 0;
    string vowels = "аеиіоуяюєї", line, inputFileContent, newOuputFileContent;
    while (getline(inputFile, line)) {
        inputFileContent += line + "\n";
    }
    inputFile.close();

    for (int i = 0; i < inputFileContent.length(); i++) {
        if (inputFileContent[i] == '!') {
            exclamationMarkCount++;
        } else if (inputFileContent[i] == '?') {
            questionMarkCount++;
        }

        if (vowels.find(inputFileContent[i]) == string::npos) {
            newOuputFileContent += inputFileContent[i];
        }
    }

    outputFile << "У файлі " << inputFileName << " міститься " << exclamationMarkCount << " знаків оклику." << endl;
    outputFile << "У файлі " << inputFileName << " міститься " << questionMarkCount << " знаків запитання." << endl;
    outputFile << "Речення з файлу " << inputFileName << " без голосних літер:" << endl << newOuputFileContent << endl;
    outputFile.close();
}

void taskTenthPointTwo(string inputFileName) {
    string transliteration[256];
    transliteration[192] = "A";
    transliteration[193] = "B";
    transliteration[194] = "V";
    transliteration[195] = "H";
    transliteration[165] = "G";
    transliteration[196] = "D";
    transliteration[197] = "E";
    transliteration[170] = "Ye";
    transliteration[198] = "Zh";
    transliteration[199] = "Z";
    transliteration[200] = "Y";
    transliteration[178] = "I";
    transliteration[175] = "Yi";
    transliteration[201] = "Y";
    transliteration[202] = "K";
    transliteration[203] = "L";
    transliteration[204] = "M";
    transliteration[205] = "N";
    transliteration[206] = "O";
    transliteration[207] = "P";
    transliteration[208] = "R";
    transliteration[209] = "S";
    transliteration[210] = "T";
    transliteration[211] = "U";
    transliteration[212] = "F";
    transliteration[213] = "Kh";
    transliteration[214] = "Ts";
    transliteration[215] = "Ch";
    transliteration[216] = "Sh";
    transliteration[217] = "Shch";
    transliteration[222] = "Yu";
    transliteration[223] = "Ya";
    transliteration[224] = "a";
    transliteration[225] = "b";
    transliteration[226] = "v";
    transliteration[227] = "h";
    transliteration[180] = "g";
    transliteration[228] = "d";
    transliteration[229] = "e";
    transliteration[186] = "ie";
    transliteration[230] = "zh";
    transliteration[231] = "z";
    transliteration[232] = "y";
    transliteration[179] = "i";
    transliteration[191] = "i";
    transliteration[233] = "i";
    transliteration[234] = "k";
    transliteration[235] = "l";
    transliteration[236] = "m";
    transliteration[237] = "n";
    transliteration[238] = "o";
    transliteration[239] = "p";
    transliteration[240] = "r";
    transliteration[241] = "s";
    transliteration[242] = "t";
    transliteration[243] = "u";
    transliteration[244] = "f";
    transliteration[245] = "kh";
    transliteration[246] = "ts";
    transliteration[247] = "ch";
    transliteration[248] = "sh";
    transliteration[249] = "shch";
    transliteration[254] = "iu";
    transliteration[255] = "ia";

    ifstream inputFile(inputFileName);
    if (!inputFile) {
        return;
    }

    string line, inputFileContent, newOuputFileContent;
    while (getline(inputFile, line)) {
        inputFileContent += line + "\n";
    }
    inputFile.close();

    for (int i = 0; i < inputFileContent.length(); i++) {
        if (inputFileContent[i] == 'Ь' || inputFileContent[i] == 'ь' || inputFileContent[i] == '\'') {
            continue;
        }

        if ((i - 1) >= 0) { // перевірка, чи існує попередня літера
            if (
                (inputFileContent[i] == 'г' || inputFileContent[i] == 'Г') &&
                (inputFileContent[i - 1] == 'з' || inputFileContent[i - 1] == 'З')
            ) {
                newOuputFileContent += 'g';
            }
        }

        string transliteratedLetter = transliteration[(unsigned char)inputFileContent[i]];
        if (transliteratedLetter.empty()) {
            newOuputFileContent += inputFileContent[i];
        } else {
            newOuputFileContent += transliteratedLetter;
        }
    }

    ofstream outputFile(inputFileName, ios::out | ios::app);
    outputFile << endl << newOuputFileContent;

    time_t curr_time;
	curr_time = time(NULL);
    outputFile << "Дата й час дозапису інформації: " << ctime(&curr_time);

    outputFile.close();
}

void taskTenthPointThree(int x, int y, int z, unsigned int b, string outputFileName) {
    ofstream outputFile(outputFileName, ios::out | ios::app);
    outputFile << "Результат виконання функції s_calculation: " << s_calculation(x, y, z) << endl;
    outputFile << "Число b у двійковому коді: " << bitset<32>(b).to_string() << endl << endl;
    outputFile.close();
}
