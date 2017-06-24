#include "leap.h"

bool leap::is_leap_year(int year) {
  bool modFour = year % 4 == 0;
  bool modHundred = year % 100 == 0;
  bool modFourHundress = year % 400 == 0;

  /*
  Let us create a truth table to lay this out algebraically.
  A = 1, when modFour is true; and A' = 0, when modFour is false
  B is same for modHundred
  C is same for modFourHundress

  C B A | X
  ---------
  0 0 0 | 0
  0 0 1 | 1
  0 1 0 | 0
  0 1 1 | 0
  1 0 0 | 0
  1 0 1 | 1
  1 1 0 | 0
  1 1 1 | 1

  Ergo:
  1 = A*B'*C' + A*B'*C + A*B*C
  1 = A * (B'*C' + B'*C + B*C)
  1 = A * (B'*(C'+C) + B*C)
    C'+C = 1
  1 = A * (B' + B*C)
    Distributive law (almost missed this. This answer can be further simplified)
  1 = A * (B'+B) * (B'+C)
    B'+B = 1
  1 = A * (B'+C)

  Thus, using boolean algebra, we can write this as a one-liner.
  */

  return modFour && (!modHundred || modFourHundress);
}
