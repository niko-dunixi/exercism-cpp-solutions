#include "rna_transcription.h"

namespace transcription {
char to_rna(char letter) {
  if (letter == 'C'){
    return 'G';
  } else if (letter == 'G') {
    return 'C';
  } else if (letter == 'A') {
    return 'U';
  } else if (letter == 'T') {
    return 'A';
  }
  return ' ';
}
std::string to_rna(std::string letters) {
  for(int i = 0; i< letters.size(); ++i) {
    letters[i] = to_rna(letters[i]);
  }
  return letters;
}
}
