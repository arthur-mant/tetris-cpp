#include "tela.h"

const std::array<std::array<int, 3>, 8> colors = {{
    {0, 0, 204},
    {0, 204, 0},
    {204, 0, 0},
    {102, 0, 204},
    {255, 153, 0},
    {255, 0, 255},
    {0, 204, 255},
    {190, 190, 190}
}};

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


    this->game = game;
    printf("created screen\n");

}

void Tela::update() {

    SDL_RenderClear(this->renderer);

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    
    SDL_Rect rect;
    rect.x = 50+BOARD_WIDTH*20;
    rect.y = 50;
    rect.w = BOARD_WIDTH*20;
    rect.h = BOARD_HEIGHT*20;

    SDL_RenderDrawRect(this->renderer, &rect);

    rect = {50, 50, 20, 20}; //{x, y, w, h}

    for (int i=0; i<BOARD_HEIGHT; i++) {
        rect.x = 50;
        for (int j=0; j<BOARD_WIDTH; j++) {
            SDL_RenderDrawRect(this->renderer, &rect);
            if (game.get_field()[i][j] > -1) {
                auto color = colors[game.get_field()[i][j]];

                auto aux_rect = rect;
                aux_rect.x += 1;
                aux_rect.y += 1;
                aux_rect.w += -2;
                aux_rect.h += -2;
                
                SDL_SetRenderDrawColor(this->renderer, color[0], color[1], color[2], 255);
                SDL_RenderFillRect(this->renderer, &aux_rect);
            }
            rect.x += 20;
            SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
        }
        rect.y += 20;
    }

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

    SDL_RenderPresent(this->renderer);

}

void Tela::cleanup_graphics() {
    printf("destroying screen\n");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

