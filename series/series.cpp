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
        const std::vector<int> &parsed_digits = digits(input_digits);
        const auto count = (input_digits.length() - size + 1) * size;
//        std::cout << "count: " << count << std::endl;
        std::vector<std::vector<int>> results;

        for (auto i(0); i < (parsed_digits.size() - (size) + 1); ++i) {
            auto begin = std::begin(parsed_digits) + i;
            auto end = std::begin(parsed_digits) + (i + size);
//            std::cout << "begin: " << *begin << " end: " << *end << std::endl;
            results.emplace_back(std::vector<int>(begin, end));
        }
//        std::cout << "done" << std::endl << std::endl;
//        std::for_each(std::begin(results), std::end(results), [](const std::vector<int> &items) {
//            std::cout << items.size() << ": ";
//            std::for_each(std::begin(items), std::end(items), [](const int &current_item) {
//                std::cout << current_item << " ";
//            });
//            std::cout << std::endl;
//        });
        return results;
    }
}