#include "tela.h"


Tela::Tela(Game game) {

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

void Tela::update() {



}

void Tela::cleanup_graphics() {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);

}

