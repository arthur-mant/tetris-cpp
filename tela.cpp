#include "tela.h"

Tela::Tela(){}

Tela::Tela(Game game) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("error initializing SDL\n");
    }

    SDL_CreateWindowAndRenderer(500, 500, SDL_WINDOW_RESIZABLE, &this->win, &this->renderer);
    SDL_RenderSetLogicalSize(this->renderer, 500, 500);

    if(!this->win) {
        throw std::runtime_error("Failed to create window\n");
    }


    //this->game = game;
    printf("created screen\n");

}

void Tela::update() {

    SDL_RenderClear(this->renderer);

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    
    SDL_Rect rect;//= {50, 50, BOARD_WIDTH*20, BOARD_HEIGHT*20};  //{x, y, w, h}
    rect.x = 50;
    rect.y = 50;
    rect.w = BOARD_WIDTH*20;
    rect.h = BOARD_HEIGHT*20;

    SDL_RenderFillRect(this->renderer, &rect);
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

    SDL_RenderPresent(this->renderer);

}

void Tela::cleanup_graphics() {
    printf("destroying screen\n");
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

