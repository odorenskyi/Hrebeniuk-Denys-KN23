#include <cmath>

float s_calculation(int x, int y, int z) {
  float S = M_PI * x + pow(M_E, abs(y)) - sqrt(abs(pow(z, 2) - y));
  return S;
}
