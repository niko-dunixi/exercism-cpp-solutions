//
// Created by Paul Baker on 6/24/17.
//

#include <iostream>
#include "series.h"

namespace series {
    std::vector<int> digits(std::string input_digits) {
        std::vector<int> result(input_digits.length());
        std::transform(std::begin(input_digits), std::end(input_digits), std::begin(result),
                       [](const char &c) { return int(c - '0'); });
        return result;
    }

    std::vector<std::vector<int>> slice(std::string input_digits, int size) {
        if (size > input_digits.size()) {
            throw std::domain_error("You cannot take a slice larger than the sample.");
        }
        const std::vector<int> &parsed_digits = digits(input_digits);
        std::vector<std::vector<int>> results;

        for (auto i(0); i < (parsed_digits.size() - size + 1); ++i) {
            auto begin = std::begin(parsed_digits) + i;
            auto end = std::begin(parsed_digits) + (i + size);
            results.emplace_back(std::vector<int>(begin, end));
        }
        return results;
    }
}