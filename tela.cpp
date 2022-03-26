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

Tela::Tela(Game *game) {

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

    SDL_SetWindowTitle(this->win, "Tetris");

    SDL_SetRenderDrawColor(this->renderer, 210, 210, 210, 255);
    SDL_RenderClear(this->renderer);

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    
    SDL_Rect rect;
    rect.x = 50+BOARD_WIDTH*20;
    rect.y = 50;
    rect.w = BOARD_WIDTH*20;
    rect.h = BOARD_HEIGHT*20;

    SDL_RenderDrawRect(this->renderer, &rect);

    rect = {50, 50, 20, 20}; //{x, y, w, h}

    //desenhando tabuleiro

    for (int i=0; i<BOARD_HEIGHT; i++) {
        rect.x = 50;
        for (int j=0; j<BOARD_WIDTH; j++) {
            SDL_RenderDrawRect(this->renderer, &rect);
            if (game->get_field()[i][j] > -1) {
                auto color = colors[game->get_field()[i][j]];

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

    //desenhando peça

    for (auto aux: game->get_piece()->image()) {
        int i = aux/4;
        int j = aux%4;
        rect = {50+(game->get_piece()->get_x()+j)*20+1,
            50+(game->get_piece()->get_y()+i)*20+1,
            20-2, 20-2};

        if (game->get_piece()->get_y()+i >= 0) {
            auto color = colors[game->get_piece()->get_type()];

            SDL_SetRenderDrawColor(this->renderer, color[0], color[1], color[2], 255);
            SDL_RenderFillRect(this->renderer, &rect);
        }
    }

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);

    //desenhando grade próx peça

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++) {
            rect = {50+200+3*20+20*j, 50+50+20*i, 20, 20};
            SDL_RenderDrawRect(this->renderer, &rect);
        }
            

    //desenhando próxima peça

    for (auto aux: game->get_next_piece()->image()) {
        int i = aux/4;
        int j = aux%4;
        rect = {50+200+(3+j)*20+1,
            50+50+(-1+i)*20+1,
            20-2, 20-2};

        if (game->get_next_piece()->get_y()+i >= 0) {
            auto color = colors[game->get_next_piece()->get_type()];

            SDL_SetRenderDrawColor(this->renderer, color[0], color[1], color[2], 255);
            SDL_RenderFillRect(this->renderer, &rect);
        }
    }
    

    SDL_RenderPresent(this->renderer);

}

void Tela::cleanup_graphics() {
    printf("destroying screen\n");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

