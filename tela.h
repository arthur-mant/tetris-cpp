#include "defs.h"
#include "game.h"

class Tela {

    private:
        SDL_Window *win;
        SDL_Renderer *render;
        SDL_Texture *display;
        SDL_Surface *surface;
//        TTF_Font *gFont;
        bool keyboard;
        //Game game;

    public:
        Tela();
        Tela(Game game);
        void update();
        void cleanup_graphics();
};
