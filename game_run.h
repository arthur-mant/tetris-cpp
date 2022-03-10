#ifndef _GAME_RUN
#define _GAME_RUN

class GameRun {

    bool done, pressing_down;
    Game game;
    int counter, fps;
    Controller controller;
    Screen screen;

    GameRun(Game new_game);
    bool run_frame();

}
#endif
