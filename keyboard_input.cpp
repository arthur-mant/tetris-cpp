#include "keyboard_input.h"

char KeyboardInput::get_command() {

    SDL_Event event;

    SDL_PollEvent(&event);

    //std::cout << "event: " << event.type << " , left: " << SDLK_LEFT << "\n";

    if (event.type == SDL_KEYDOWN) {
        //std::cout << "key down! " << event.key.keysym.sym << "\n";
        //std::cout << "left: " << SDLK_LEFT << " right: " << SDLK_RIGHT << "\n";
        switch (event.key.keysym.sym) {
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
    
    if (event.type == SDL_QUIT)
        return 'E';
    return '0';
}
