//
// Created by Paul Baker on 6/24/17.
//

#import<utility>
#import"queen_attack.h"

namespace queen_attack {

    chess_board::chess_board() : m_white(0, 3), m_black(7, 3) {

    }

    chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black) : m_white(white), m_black(black) {

    }

    std::pair<int, int> chess_board::white() const {
        return m_white;
    }

    std::pair<int, int> chess_board::black() const {
        return m_black;
    }
}