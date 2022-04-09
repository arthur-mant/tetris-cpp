#include "game_controller.h"

GameController::bool is_pos_linearly_valid(Game *game, std::tuple<int, int, int> pos) {

    if ((pos<0> < 0) || (pos<0> >= game->get_board_width()) ||
        (pos<1> < 0) || (pos<1> >= game->get_board_width()) ||
        (pos<2> < 0) || (pos<2> >= game->get_piece()->get_num_rot())) {
        fprintf(stderr, "ERROR: INVALID POSITION TUPLE (%d, %d, %d)\n", pos<0>, pos<1>, pos<2>);

    bool is_free = true;
    int height = 0;
    int i, j;

    //verifica se está livre no eixo y
    while ((height < pos<1>) && is_free) {
        for (int k=0; k<game->get_piece()->get_rot_array()[pos<2>].size(); k++) {

            i = game->get_piece()->get_rot_array()[pos<2>][k]/4;
            j = game->get_piece()->get_rot_array()[pos<2>][k]%4;

            if (game->get_field()[height+i][x+j] != -1)
                if_free = false;
        }
        height++;
    }

    //verifica se está livre no eixo x
    for (int k=(game->get_board_width()/2)-2; k<pos<0>; k++) {
        for (int l=0; l<game->get_piece()->get_rot_array[pos<2>].size(); l++) {

            i = game->get_piece()->get_rot_array()[pos<2>][l]/4;
            j = game->get_piece()->get_rot_array()[pos<2>][l]%4;

            if (game->get_field()[-2+i][k+j] != -1)
                is_free = false;
            
    }
    for (int k=(game->get_board_width()/2)-2; k>pos<0>; k--) {
        for (int l=0; l<game->get_piece()->get_rot_array[pos<2>].size(); l++) {

            i = game->get_piece()->get_rot_array()[pos<2>][l]/4;
            j = game->get_piece()->get_rot_array()[pos<2>][l]%4;

            if (game->get_field()[-2+i][k+j] != -1)
                is_free = false;
            
    }
    return is_free;
}

GameController::GameController(InputInterface *interface) {

    this->interface = interface;

}

int GameController::get_all_positions(Game *game, std::tuple<int, int, int> *v) {

    bool has_block_under, collides;
    int tam = 0;

    for (int y=0; y<game->get_board_height(); y++) {
        for (int x=0; x<game->get_board_width(); x++) {   //para cada posicao no tabuleiro
            has_block_under = false;
            collides = false;
            for (int rot=0; rot<game->get_piece()->get_rot_array().size(); rot++) {
                for (int k=0; k<game->get_piece()->get_rot_array()[rot].size(); k++) {
                    i = game->get_piece()->get_rot_array()[rot][k]/4;
                    j = game->get_piece()->get_rot_array()[rot][k]%4;

                    if ((y+i < 0) ||
                        (x+j < 0) ||
                        (y+i >= game->get_board_height()) ||
                        (x+j >= game->get_board_width()) ||
                        (game->get_field()[y+i][x+j] != -1))
                        collides = true;
                    if ((y+i+1 == game->get_board_height()) || (game->get_field()[y+i+1][x+j] != -1))
                        has_block_under = true;
                }
                if (!collides && has_block_under)
                    v[tam++] = make_tuple(x, y, rot);
            }
        }
    }
    return tam;
}

bool place_piece(Game *game, std::tuple<int, int, int> pos) {

    if (!this->is_pos_linearly_valid(game, pos)
        return false;

    this->interface->rotate(pos<2>);
    this->interface->go_side(pos<1>-(game->get_board_width()/2)-2);
    this->interface->hard_drop();

    return true;

}
