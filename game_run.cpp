#include "game_run.h"


GameRun::GameRun(bool keyboard, bool screen, bool limit_fps, int fps) {

    this->game = new Game(BOARD_HEIGHT, BOARD_WIDTH);
    this->done = false;
    this->counter = 0;
    this->virtual_fps = fps;
    this->real_fps = -1;
    this->limit_fps = limit_fps;
    this->uses_keyboard = keyboard;
    this->uses_screen = screen;

    this->pressing_down = false;


    if (keyboard) {
        this->k_inp = new KeyboardInput();
    }
//    else
//        q_inp = &Queue_Input();

    if (screen) {
        this->tela = new Tela(game);
    }
    printf("created game_run instance\n");        

}

int GameRun::exec_command(char c) {

//    std::cout << "comando: " << c << "\n";

    switch(c) {
        case 'U':
            game->rotate();
            break;
        case 'D':
            game->go_down();
            break;
        case 'L':
            game->go_side(-1);
            break;
        case 'R':
            game->go_side(1);
            break;
        case 'H':
            game->hard_drop();
            break;
        case 'E':  //fechar janela
            done = true;
            break;
        case '0':
            break;
        default:
            fprintf(stderr, "\nERROR: unrecognized command%c\n", c);
            
    }
    return 0;
}

bool GameRun::run_frame() {

    auto start = std::chrono::system_clock::now();

    counter++;
    if (counter > 10000)
        counter = 0;

    if (!game->get_gameover() && (counter % (virtual_fps/(2*game->get_level())) == 0))
        game->go_down();


    if (uses_keyboard) {
        exec_command(k_inp->get_command());
    }
/*
    else
        exec_command(q_inp->get_command());
*/

    tela->update();

    if (limit_fps) {
        while((std::chrono::system_clock::now() - start).count() < 1.0/(double)virtual_fps*1000000000)
            usleep(1000);
/*
        std::cout << (std::chrono::system_clock::now() - start).count() << ", " 
            << 1.0/(double)virtual_fps*1000000000 << "\n";
*/
    }

    real_fps = 1.0/((std::chrono::system_clock::now() - start).count());

    if(done)
        tela->cleanup_graphics();
    return !done;
/*
    if (done) {
        return false;
    }
    return true;
*/
}
