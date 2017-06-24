#include "grains.h"

namespace grains {
unsigned long long square(int square) {
  return 1ULL << (square - 1);
}

unsigned long long total() {
  unsigned long long total = 1;
  for (int i = 1; i <= 64; ++i) {
    total = (total << 1) | 1;
  }
  return total;
}
}
