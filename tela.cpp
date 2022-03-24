#include "tela.h"

Tela::Tela(){}

Tela::Tela(Game game) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("error initializing SDL\n");
    }

    this->win = SDL_CreateWindow(
        "Tetris",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        500, 500, 0);
    //this->game = game;

    if(!this->win) {
        throw std::runtime_error("Failed to create window\n");
    }

    this->surface = SDL_GetWindowSurface(this->win);

    if(!this->surface) {
        throw std::runtime_error("Failed to get surface from window\n");
    }

    SDL_UpdateWindowSurface(this->win);

    this->render = SDL_CreateRenderer(this->win, -1, 
        SDL_RENDERER_ACCELERATED | 
        SDL_RENDERER_PRESENTVSYNC | 
        SDL_RENDERER_TARGETTEXTURE);

    if (this->render == NULL) {
        throw std::runtime_error("SDL_CreateRender Error\n");
    }

    SDL_RenderClear(this->render);

    SDL_SetRenderDrawColor(this->render, 100, 100, 100, 100);
    SDL_RenderPresent(this->render);

    SDL_Rect rect;
    rect.x = 100;
    rect.y = 100;
    rect.w = BOARD_WIDTH*10;
    rect.h = BOARD_HEIGHT*10;

    SDL_SetRenderDrawColor(this->render, 255, 255, 255, 255);
    SDL_RenderDrawRect(this->render, &rect);

    printf("im here!\n");

}

void Tela::update() {



}

void Tela::cleanup_graphics() {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);

}

