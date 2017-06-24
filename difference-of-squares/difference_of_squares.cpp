#include "difference_of_squares.h"
#include <math.h>

namespace squares {
unsigned int square_of_sums(unsigned int n) {
  unsigned int result(0);
  for (int i = 1; i <= n; ++i) {
    result += i;
  }
  return pow(result, 2);
}
unsigned int sum_of_squares(unsigned int n) {
  unsigned int result(0);
  for (int i = 1; i <= n; ++i) {
    result += pow(i, 2);
  }
  return result;
}
unsigned int difference(unsigned int n) {
  return square_of_sums(n) - sum_of_squares(n);
}
}
