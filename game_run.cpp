#include "game_run.h"


GameRun::GameRun(bool keyboard, bool screen) {

    Game new_game(BOARD_HEIGHT, BOARD_WIDTH);

    done = false;
    counter = 0;
    fps = 1;
    uses_keyboard = keyboard;
    uses_screen = screen;

    pressing_down = false;


    if (keyboard)
        k_inp = KeyboardInput();
//    else
//        q_inp = Queue_Input();

    if (screen)
        tela = Tela(game);
        

}

int GameRun::exec_command(char c) {

    switch(c) {
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
        case '0':
            break;
        default:
            fprintf(stderr, "\nERROR: unrecognized command%c\n", c);
            
    }
    return 0;
}

bool GameRun::run_frame() {

    counter++;
    if (counter > 10000)
        counter = 0;
    if (!game.get_gameover() && (counter % (fps/2*game.get_level()) == 0))
        game.go_down();

    if (uses_keyboard)
        exec_command(k_inp.get_command());
/*
    else
        exec_command(q_inp.get_command());
*/

    tela.update();

    if (done) {
        return false;
    }
    return true;
}
