#include "tela.h"

Tela::Tela(){}

Tela::Tela(Game game) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("error initializing SDL\n");
    }

/*
    this->win = SDL_CreateWindow(
        "Tetris",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        500, 500, 0);
*/
    SDL_CreateWindowAndRenderer(500, 500, SDL_WINDOW_RESIZABLE, &this->win, &this->renderer);
    SDL_RenderSetLogicalSize(this->renderer, 500, 500);

    //this->game = game;

    if(!this->win) {
        throw std::runtime_error("Failed to create window\n");
    }

}

void Tela::update() {

    SDL_RenderClear(this->renderer);

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    
    SDL_Rect rect;
    rect.x = 50;
    rect.y = 50;
    rect.w = BOARD_WIDTH*20;
    rect.h = BOARD_HEIGHT*20;

    SDL_RenderFillRect(this->renderer, &rect);
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

    SDL_RenderPresent(this->renderer);

}

Tela::~Tela() {
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

