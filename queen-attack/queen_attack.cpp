//
// Created by Paul Baker on 6/24/17.
//

#include<iterator>
#include<cmath>
#include<stdexcept>
#include<string>
#include<utility>
#include <iostream>
#include"queen_attack.h"

namespace queen_attack {

    // https://stackoverflow.com/a/39888153/1478636
    chess_board::chess_board() : chess_board{std::make_pair(0, 3), std::make_pair(7, 3)} {
    }

    chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black) : m_white(white), m_black(black) {
        // This dude is zen as heck
        // http://www.gotw.ca/publications/mill13.htm
        if (m_white == m_black) {
            // https://isocpp.org/wiki/faq/exceptions#how-exceptions
            throw std::domain_error("You cannot place two queens on top of each other.");
        }
    }

    std::pair<int, int> chess_board::white() const {
        return m_white;
    }

    std::pair<int, int> chess_board::black() const {
        return m_black;
    }

    // https://stackoverflow.com/a/20157061/1478636
    chess_board::operator std::string() const {
        std::string result{
                "_ _ _ _ _ _ _ _\n"
                        "_ _ _ _ _ _ _ _\n"
                        "_ _ _ _ _ _ _ _\n"
                        "_ _ _ _ _ _ _ _\n"
                        "_ _ _ _ _ _ _ _\n"
                        "_ _ _ _ _ _ _ _\n"
                        "_ _ _ _ _ _ _ _\n"
                        "_ _ _ _ _ _ _ _\n"};
        // https://stackoverflow.com/a/2151141/1478636
        result[16 * white().first + 2 * white().second] = 'W';
        result[16 * black().first + 2 * black().second] = 'B';
        return result;
    }

    std::pair<int, int> calculate_delta_vector(std::pair<int, int> a, std::pair<int, int> b) {
        return std::make_pair(a.first - b.first, a.second - b.second);
    };

    int calculate_dot_product(std::pair<int, int> a, std::pair<int, int> b) {
        return a.first * b.first + a.second * b.second;
    }

    double calculate_magnitude(std::pair<int, int> a) {
        return std::sqrt(std::pow(a.first, 2) + std::pow(a.second, 2));
    }

    double calculate_rads_between_vectors(std::pair<int, int> a, std::pair<int, int> b) {
        int dot_product = calculate_dot_product(a, b);
        double magnitude_a = calculate_magnitude(a);
        double magnitude_b = calculate_magnitude(b);

        return std::acos(dot_product / (magnitude_a * magnitude_b));
    }

    const double pi = 4 * std::atan(1);

    double calculate_degs_between_vectors(std::pair<int, int> a, std::pair<int, int> b) {
        double radians_between_vectors = calculate_rads_between_vectors(a, b);
        // The angle between these two vectors is in the range
        // of 0, pi according to this:
        // http://en.cppreference.com/w/cpp/numeric/math/acos
        //
        // If we're in radians, we need to cancel out pi and multiply by 180
        return radians_between_vectors / pi * 180;
    }

    bool chess_board::can_attack() const {
        // Okay. So coordinates on a board are nothing more than points.
        // Points are vectors. We can determine the vector connecting
        // the other vectors (let's call it C connecting A and B) and
        // then take the angle between C and either A or B will tell us
        // their relationship. If the degrees between C and either of
        // them is evenly divisible by 45, it means they're diagonally,
        // horizontally, or vertically connected. All with one mathematical
        // operation.
        //
        const std::pair<int, int> delta_vector = calculate_delta_vector(white(), black());
        double angle_between = calculate_degs_between_vectors(white(), delta_vector);
        int angle_integer = static_cast<int>(angle_between);
        int angle_modded = angle_integer % 45;
        bool queenCanAttack = angle_modded == 0;
        std::cout << angle_between << ' ' << angle_integer << ' ' << angle_modded << ' ';
        std::cout << (queenCanAttack ? "can attack" : "can't attack") << std::endl;
        // Let's do this...
        // LEEEROOOOOOOOOOOY JEEEEENKIIIIINS!!!!
        return queenCanAttack;
    }

}