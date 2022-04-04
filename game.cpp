#include "game.h"

void Game::new_piece() {

    piece = next_piece;
    next_piece = new Piece((board_width/2)-2, -2);
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
            for (int k=i; k>0; k--) {
                for (int l=0; l<board_width; l++)
                    field[k][l] = field[k-1][l];
            }
            for (int l=0; l<board_width; l++)
                field[0][l] = -1;
        }
    }
    switch(lines) {
        case 1:
            this->score += 40;
            break;
        case 2:
            this->score += 100;
            break;
        case 3:
            this->score += 300;
            break;
        case 4:
            this->score += 1200;
            break;
        case 0:
            break;
        default:
            fprintf(stderr, "ERROR: number of lines(%d) broke???\n", lines);
    }
}
bool Game::intersects() {
//    std::cout << "in intersect\n";
    bool intersection = false;
    int i, j;

    for (int k=0; k<piece->image().size(); k++) {
        i = piece->image()[k]/4;
        j = piece->image()[k]%4;

//        std::cout << "(" << piece->get_x()+j << ", " << piece->get_y()+i << ")\n";

        if ((i+piece->get_y() >= 0) &&
            ((i+piece->get_y() >= board_height) ||
             (j+piece->get_x() >= board_width) ||
             (j+piece->get_x() < 0) ||
             (field[i+piece->get_y()][j+piece->get_x()] > -1)))
                intersection = true;

    }
    return intersection;
}
bool Game::freeze() {
    int i, j;
    for (int block: piece->image()) {
        i = block/4;
        j = block%4;
        field[i+piece->get_y()][j+piece->get_x()] = piece->get_type();
    }
    break_lines();
    new_piece();
    if (intersects()) {
        //std::cout << "GAMEOVER\n";
        gameover = true;
    }
}

Game::Game(){}

Game::Game(int h, int w) {
    board_height = h;
    board_width = w;
    score = lines = pieces = 0;
    gameover = false;
    fps = -1;

    piece = new Piece((board_width/2)-2, -2);
    next_piece = new Piece((board_width/2)-2, -2);

    level = 1;

    this->field = (int **)malloc(h*sizeof(int *));
    for (int i=0; i<h; i++) {
        this->field[i] = (int *)malloc(w*sizeof(int));
        for (int j=0; j<w; j++)
            this->field[i][j] = -1;
    }

}

void Game::hard_drop() {
    while (!intersects()) {
        piece->move_down(1);
    }
    piece->move_down(-1);
    freeze();
}
void Game::go_down() {
    piece->move_down(1);
    if (intersects()) {
        piece->move_down(-1);
        freeze();
    }
}
void Game::go_side(int direction) {
    piece->move_x(direction);
    if (intersects()) {
        piece->move_x(-direction);
    }
}
void Game::rotate() {
    piece->rotate(1);
    if (intersects())
        piece->rotate(-1);
}
int **Game::get_field() {
    return this->field;
}

Piece *Game::get_piece() {
    return this->piece;
}
Piece *Game::get_next_piece() {
    return this->next_piece;
}

bool Game::get_gameover() {
    return gameover;
}
int Game::get_level() {
    return level;
}
int Game::get_score() {
    return score;
}
