#include "defs.h"
#include "game.h"

class Tela {

    private:
        SDL_Window *win;
        SDL_Renderer *renderer;
        SDL_Texture *display;
        SDL_Surface *surface;
        TTF_Font *text_font;
        bool keyboard;
        Game *game;

    public:
        Tela();
        Tela(Game *game);
        void update();
        void cleanup_graphics();
};
