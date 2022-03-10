#ifndef _GAME
#define _GAME

class Game {

    private:
        int score, lines, pieces, board_height, board_width, level;
        Piece piece, next_piece;
        bool gameover;
        double fps;
        int **field;
    private:
        void new_piece();
        void break_lines();
        bool intersects();
        bool freeze();
    public:
        Game(int h, int w, int **new_field);
        void hard_drop();
        void go_down();
        void go_side(int direction);
        void rotate();
};
#endif