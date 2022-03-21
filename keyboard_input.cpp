#include "keyboard_input.h"

char KeyboardInput::get_command() {

    SDL_Event event;

    SDL_PollEvent(&event);

    if (event.type == SDL_KEYDOWN) {
        switch (event.type) {
            case SDLK_LEFT:
                return 'L';
            case SDLK_RIGHT:
                return 'R';
            case SDLK_UP:
                return 'U';
            case SDLK_DOWN:
                return 'D';
            case SDLK_SPACE:
                return 'H';
        }
    }
    return '0';
}
