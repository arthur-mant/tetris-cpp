#include "tela.h"

class Tela {

    private:
        SDL_Window *win;
        SDL_Renderer *render;
        SDL_Texture *display;
//        TTF_Font *gFont;
        bool keyboard;
        //Game game;

    public:
        Tela() {//Game game) {

            if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
                printf("error initializing SDL: %s\n", SDL_GetError());
            this->win = SDL_CreateWindow(
                "Tetris",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                500, 500, 0);
            //this->game = game;

            this->render = SDL_CreateRenderer(this->win, -1, 
                SDL_RENDERER_ACCELERATED | 
                SDL_RENDERER_PRESENTVSYNC | 
                SDL_RENDERER_TARGETTEXTURE);

            if (this->render == NULL) {
                fprintf(stderr, "\nSDL_CreateRender Error: %s\n",
                SDL_GetError());
            }


        }

        void cleanup_graphics() {
            SDL_DestroyRenderer(render);
            SDL_DestroyWindow(win);

        }

};

int main (int, char**) {
    Tela tela;

    while(1);

    return 0;
}
