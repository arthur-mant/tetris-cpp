#include <stdlib.h>

int ***pieces_def = {
        {{8, 9, 10, 11}, {2, 6, 10,14}},    //I
        {{8, 9, 10, 14}, {5, 9, 12, 13}, {4, 8, 9, 10}, {5, 6, 9, 13}},      //J
        {{8, 9, 10, 12}, {4, 5, 9, 13}, {6, 8, 9, 10}, {5, 9, 13, 14}},      //L
        {{8, 9, 10, 13}, {5, 8, 9, 13}, {5, 8, 9, 10}, {5, 9, 10, 13}},      //T
        {{9, 10, 13, 14}},                    //O
        {{8, 9, 13, 14}, {6, 9, 10, 13}},     //Z
        {{9, 10, 12, 13}, {5, 9, 10, 14}}     //S
}

class Piece {

    private:
        int x, y, type, rotation;
        int **rot_array;

    public:
        Piece(int orig_x, int orig_y) {
            x = orig_x;
            y = orig_y;
            type = rand() % 7;
            rotation = 0;
            rot_array = pieces_def[type];
        }
        int *image() {
            return rot_array[rotation];
        }
        void rotate(direction) {
            rotation = (rotation+direction) % (sizeof(rot_array)/sizeof(rot_array[0]));
        }
        int move_x(int n) {
            if ((n != 1) && (n != -1))
                printf("ERROR: ILLEGAL X AXIS PIECE MOVE\n");
                return NULL;
            x += n;
            return x;
        }
        int move_down(int n) {
            y += n;
            return y;
        }
/*
        std::tuple<int, int, int> get_coordinates() {
            return std::make_tuple(x, y, rotation);
        }
*/
        int get_x() {
            return x;
        }
        int get_y() {
            return y;
        }
        int get_rotation() {
            return rotation;
        }
}

class Game {

    private:
        int score, lines, pieces, board_height, board_width, level;
        Piece piece, next_piece;
        bool gameover;
        double fps;
        int **field;
    private:
        void new_piece() {
            piece = next_piece;
            next_piece = Piece((board_width/2)-2, -2);
            pieces++;
        }
        void break_lines() {
            int lines = 0;
            int holes;
            for (int i=0; i<board_height; i++) {
                holes = 0;
                for (int j=0; j<board_width; j++) {
                    if (field[i][j] == -1)
                        holes++;
                }
                if (holes == 0) {
                    lines++;
                    for (int k=i; k<0; k--) {
                        for (int l=0; l<board_width; l++)
                            field[k][l] = field[k-1][l];
                    }
                }
            }
        }
        bool intersects() {
            bool intersection = false;
            int i, j;

            for (int block: piece.image()) {
                i = block/4;
                j = block%4;

                if ((i+piece.get_y() >= 0) &&
                    ((i+piece.get_y() >= board_height) ||
                     (j+piece.get_x() >= board_width) ||
                     (j+piece.get_x() < 0) ||
                     (field[i+piece.get_y()][j+piece.get_x()])))
                        intersection = true;
            return intersection;
        }
        bool freeze() {
            int i, j;
            for (int block: piece.image()) {
                i = block/4;
                j = block%4;
                field[i+piece.y][j+piece.x] = piece.type;
            }
            break_lines();
            new_piece();
            if (intersects())
                gameover = true;
        }

    public:
        Game(int h, int w, int **new_field) {
            board_height = h;
            board_width = w;
            field = new_field;
            score = lines = pieces = 0;
            gameover = false;
            fps = -1;
            piece = Piece((board_width/2)-2, -2);
            next_piece = Piece((board_width/2)-2, -2);
            level = 1;
        }
        void hard_drop() {
            while (!intersects())
               piece.move_down(1); 
            piece.move_down(-1);
            freeze();
        }
        void go_down() {
            piece.move_down(1);
            if (intersects()) {
                piece.move_down(-1);
                freeze();
            }
        }
        void go_side(int direction) {
            piece.move_x(direction);
            if (intersects())
                piece.move_x(-direction);
        }
        void rotate() {
            piece.rotate(1);
            if (intersects())
                piece.rotate(-1);
        }
}

class GameRun {

    bool done, pressing_down;
    Game game;
    int counter, fps;
    Controller controller;
    Screen screen;

    GameRun(Game new_game) {

        done = false;
        game = new_game;
        counter = 0;
        fps = 1;
        pressing_down = false;

    }

    bool run_frame() {

        counter++;
        if (counter > 10000)
            counter = 0;
        if (!game.gameover && (counter % (fps/2*game.level) == 0))
            game.go_down();

        switch(controller.get_command()) {
            case 'U':
                game.rotate();
                break;
            case 'D':
                game.go_down();
                break;
            case 'L':
                game.go_side(-1);
                break;
            case 'R':
                game.go_side(1);
                break;
            case 'H':
                game.hard_drop();
                break;
        }

        screen.update_screen();

        if (done) {
            return false;
        }
        return true;
    }

}
