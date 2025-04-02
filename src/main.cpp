#include "window.hpp"
#include "renderer.hpp"
#include "scene_manager.hpp"
#include "scenes/splash_screen_scene.hpp"
#include "input_handler.hpp"
#include <iostream>

int main() {
    Window window("Homeros", 800, 600, 60);
    Renderer renderer(window);
    SceneManager sceneManager;
    InputHandler inputHandler(sceneManager);

    sceneManager.addScene("splash", std::make_shared<SplashScreenScene>(renderer, "assets/logo.png"));
    sceneManager.changeScene("splash");

    bool running = true;

    while (running) {
        inputHandler.handleEvents(running);

        sceneManager.update();
        renderer.clear();
        sceneManager.render(renderer);
        renderer.present();

        window.delayFrame();
    }

    SDL_Quit();
    return 0;
}
