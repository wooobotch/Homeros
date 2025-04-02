#include "window.hpp"
#include "renderer.hpp"
#include "input_handler.hpp"

int main() {
    Window window("Homeros", 800, 600, 60);
    Renderer renderer(window.getSDLWindow());
    InputHandler inputHandler;

    bool running = true;

    // Cargar una imagen
    SDL_Texture* image = renderer.loadTexture("assets/sprites/logo.png");
    if (!image) return -1;

    while (running) {
        inputHandler.handleEvents(running);
        renderer.clear();
        renderer.renderTexture(image, 200, 150, 400, 300);
        renderer.present();
        window.delayFrame();
    }

    SDL_DestroyTexture(image);
    return 0;
}
