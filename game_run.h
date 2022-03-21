#include "game.h"
#include "keyboard_input.h"
#include "tela.h"
#include "defs.h"

#ifndef _GAME_RUN
#define _GAME_RUN

class GameRun {

    private:
        bool done, pressing_down, uses_keyboard, uses_screen;
        Game game;
        int counter, fps;
        KeyboardInput k_inp;
        //QueueInput q_inp;
        Tela tela;

        int exec_command(char c);

    public:
        GameRun(bool, bool);    
        bool run_frame();

};
#endif
