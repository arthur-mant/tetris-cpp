#include "defs.h"

class Tela {

    private:
        SDL_Window *win;
        SDL_Renderer *render;
        SDL_Texture *display;
//        TTF_Font *gFont;
        bool keyboard;
        //Game game;

    public:
        Tela();
        Tela(Game game);
        void cleanup_graphics();
};
