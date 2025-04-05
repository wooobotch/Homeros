#include "input_handler.hpp"

InputHandler::InputHandler(SceneManager& sceneManager) : sceneManager(sceneManager) {}

void InputHandler::handleEvents(bool &running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false; // Cerrar ventana con el botón X
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false; // Cerrar con Esc
        }
        sceneManager.handleInput(event); // Pipe eventos al scene actual
    }
}
