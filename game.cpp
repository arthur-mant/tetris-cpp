#include "game.h"

void Game::new_piece() {
    piece = next_piece;
    next_piece = Piece((board_width/2)-2, -2);
    pieces++;
}
void Game::break_lines() {
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
bool Game::intersects() {
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
}
bool Game::freeze() {
    int i, j;
    for (int block: piece.image()) {
        i = block/4;
        j = block%4;
        field[i+piece.get_y()][j+piece.get_x()] = piece.get_type();
    }
    break_lines();
    new_piece();
    if (intersects())
        gameover = true;
}

Game::Game(int h, int w, int **new_field) {
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

void Game::hard_drop() {
    while (!intersects())
       piece.move_down(1); 
    piece.move_down(-1);
    freeze();
}
void Game::go_down() {
    piece.move_down(1);
    if (intersects()) {
        piece.move_down(-1);
        freeze();
    }
}
void Game::go_side(int direction) {
    piece.move_x(direction);
    if (intersects())
        piece.move_x(-direction);
}
void Game::rotate() {
    piece.rotate(1);
    if (intersects())
        piece.rotate(-1);
}
