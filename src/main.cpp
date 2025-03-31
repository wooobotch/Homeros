#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error al iniciar SDL2: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Quit();
    std::cout << "SDL2 inicializado correctamente." << std::endl;
    return 0;
}
