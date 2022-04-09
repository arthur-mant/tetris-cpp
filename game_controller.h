#include "defs.h"
#include "input_interface.h"
#include "game.h"

#ifndef _GAME_CONTROLLER
#define _GAME_CONTROLLER

class GameController {

    private:
        InputInterface *interface;
        bool is_pos_linearly_valid(Game *game, std::tuple<int, int, int> pos);
    public:
        GameController(InputInterface *interface);
        int get_all_positions(Game *game, std::tuple<int, int, int> *v);
        bool place_piece(Game *game, std::tuple<int, int, int> pos);

};

#endif
