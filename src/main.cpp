#include "window.hpp"
#include "renderer.hpp"
#include "scene_manager.hpp"
#include "scenes/splash_screen_scene.hpp"
#include "input_handler.hpp"
#include <iostream>

int main() {
    Window window("Homeros", 800, 600, 60);
    Renderer renderer(window);
    InputHandler inputHandler;
    SceneManager sceneManager;

    sceneManager.changeScene(new SplashScreenScene(renderer, "assets/logo.png"));

    bool running = true;

    while (running) {
        inputHandler.handleEvents(running);
        renderer.clear();
        renderer.present();
        window.delayFrame();
    }

    SDL_DestroyTexture(image);
    SDL_Quit();
    return 0;
}
