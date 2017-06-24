//
// Created by Paul Baker on 6/24/17.
//

#include "series.h"

namespace series {
    std::vector<int> digits(std::string input) {
        std::vector<int> result(input.length());
        std::transform(std::begin(input), std::end(input), std::begin(result),
                       [](const char &c) { return int(c - '0'); });
        return result;
    }
}