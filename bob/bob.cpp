#include <string>
// #include <iterator>
#include <boost/algorithm/string.hpp>
#include "bob.h"

std::string bob::hey(std::string message){
  boost::trim(message);
  int size = message.size();
  if (size != 0){
    char lastChar(message[message.size() - 1]);

    int char0('0'), char9('9');
    int lowerA('a'), lowerZ('z');
    int upperA('A'), upperZ('Z');
    bool hasNum(false);
    bool hasLetter(false);
    bool anyLower(false);
    for (int i = 0; i < size; ++i) {
      int current = message[i];
      if (current >= lowerA && current <= lowerZ) {
        anyLower = hasLetter = true;
      } else if (current >= upperA && current <= upperZ) {
        hasLetter = true;
      } else if (current >= char0 && current <= char9) {
        hasNum = true;
      }
    }

    if (!anyLower && hasLetter) {
      return "Whoa, chill out!";
    } else if (lastChar == '?') {
      return "Sure.";
    }

    return "Whatever.";
  }
  return "Fine. Be that way!";
}
