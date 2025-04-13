#include <iostream>
#include "audio_manager.hpp"
#include "input_handler.hpp"
#include "window.hpp"
#include "renderer.hpp"
#include "scene_manager.hpp"
#include "scenes/splash_screen_scene.hpp"
#include "scenes/menu_scene.hpp"
#include "scenes/game_scene.hpp"
#include "scenes/options_scene.hpp"

int main() {
    Window window("Homeros", 800, 600, 60);
    Renderer renderer(window);
    SceneManager sceneManager;
    InputHandler inputHandler(sceneManager);

    AudioManager audio;

    audio.loadMusic("fondo", "assets/audio/music.ogg");
    audio.loadSound("click", "assets/audio/click.wav");

    audio.playMusic("fondo");
    audio.playSound("click");


    sceneManager.addScene("splash", std::make_shared<SplashScreenScene>(renderer, sceneManager, "assets/logo.png"));
    sceneManager.addScene("menu", std::make_shared<MenuScene>(sceneManager));
    sceneManager.addScene("game", std::make_shared<GameScene>(sceneManager, renderer));
    sceneManager.addScene("options", std::make_shared<OptionsScene>(sceneManager));

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

    audio.clear();
    TTF_Quit();
    SDL_Quit();
    return 0;
}
