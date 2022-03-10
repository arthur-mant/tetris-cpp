#include "game_run.h"



GameRun::GameRun(Game new_game) {

    done = false;
    game = new_game;
    counter = 0;
    fps = 1;
    pressing_down = false;

}

bool GameRun::run_frame() {

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
