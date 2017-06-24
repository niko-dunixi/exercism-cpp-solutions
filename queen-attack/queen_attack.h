
#include<string>
#include<utility>

namespace queen_attack {

    class chess_board {
    public:
        chess_board();

        chess_board(std::pair<int, int>, std::pair<int, int>);

        std::pair<int, int> white() const;

        std::pair<int, int> black() const;

        // https://stackoverflow.com/a/20157061/1478636
        operator std::string &() const;

    private:
        std::pair<int, int> m_white;
        std::pair<int, int> m_black;
    };

}
