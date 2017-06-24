//
// Created by Paul Baker on 6/24/17.
//

#include<utility>
#include<stdexcept>
#include<string>
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
    chess_board::operator std::string &() const {
        std::string *result = new std::string;
        std::string &board = *result;
        for (int i(0); i < 8; ++i) {
            std::string current = "_ _ _ _ _ _ _ _\n";
            if (i == white().first) {
                current[white().second * 2] = 'W';
            }
            if (i == black().first) {
                current[black().second * 2] = 'B';
            }
            board += current;
        }
        return *result;
    }

    bool chess_board::can_attack() const {
        if (white().first == black().first || white().second == black().second) {
            return true;
        }
        return false;
    }

}