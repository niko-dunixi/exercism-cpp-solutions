
#include <utility>

namespace queen_attack {

    class chess_board {
    public:
        chess_board();

        chess_board(std::pair<int, int>, std::pair<int, int>);

        std::pair<int, int> white() const;

        std::pair<int, int> black() const;

    private:
        std::pair<int, int> m_white;
        std::pair<int, int> m_black;
    };

}