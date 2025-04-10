#include "game_scene.hpp"
#include <iostream>

GameScene::GameScene(SceneManager& sceneManager)
    : sceneManager(sceneManager) {}

void GameScene::handleInput(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        SDL_Keycode key = event.key.keysym.sym;

        if (key == SDLK_ESCAPE) {
            std::cout << "Volviendo al menú..." << std::endl;
            sceneManager.changeScene("menu");
        }
    }

    if (event.type == SDL_QUIT) {
        exit(0);
    }
}

void GameScene::update() {
    // Por ahora, sin lógica interna
}

void GameScene::render(Renderer& renderer) {
    renderer.clear();

    SDL_SetRenderDrawColor(renderer.getSDLRenderer(), 20, 20, 50, 255); // Fondo azul oscuro
    SDL_RenderClear(renderer.getSDLRenderer());

    // Lugar para renderizar

    renderer.present();
}
