#include <SDL.h>

unsigned char **colors = {
    {255, 0, 0, 204},
    {255, 0, 204, 0},
    {255, 204, 0, 0},
    {255, 102, 0, 204},
    {255, 255, 153, 0},
    {255, 255, 0, 255},
    {255, 0, 204, 255},
    {255, 190, 190, 190},
}

class Framework{
public:
    // Contructor which initialize the parameters.
    Framework(int height_, int width_): height(height_), width(width_){
        SDL_Init(SDL_INIT_VIDEO);       // Initializing SDL as Video
        SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);      // setting draw color
        SDL_RenderClear(renderer);      // Clear the newly created window
        SDL_RenderPresent(renderer);    // Reflects the changes done in the
                                        //  window.
    }

    // Destructor
    ~Framework(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

private:
    int height;     // Height of the window
    int width;      // Width of the window
    SDL_Renderer *renderer = NULL;      // Pointer for the renderer
    SDL_Window *window = NULL;      // Pointer for the window
};

int main(int argc, char * argv[]){

    // Creating the object by passing Height and Width value.
    Framework fw(200, 400);

    SDL_Event event;    // Event variable

    // Below while loop checks if the window has terminated using close in the
    //  corner.
    while(!(event.type == SDL_QUIT)){
        SDL_Delay(10);  // setting some Delay
        SDL_PollEvent(&event);  // Catching the poll event.
    }
}

