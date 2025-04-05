#include "menu_scene.hpp"
#include <iostream>

MenuScene::MenuScene() {
    std::cout << "MenuScene inicializada." << std::endl;
}

MenuScene::~MenuScene() {}

void MenuScene::handleInput(SDL_Event& event) {
    if (event.type == SDL_QUIT) {
        exit(0);
    }

    if (event.type == SDL_KEYDOWN) {
        SDL_Keycode key = event.key.keysym.sym;
        if (key == SDLK_ESCAPE) {
            std::cout << "Saliendo desde el menú..." << std::endl;
            exit(0);
        }
    }
}

void MenuScene::update() {
    // Menu + lógica
}

void MenuScene::render(Renderer& renderer) {
    SDL_SetRenderDrawColor(renderer.getSDLRenderer(), 20, 30, 60, 255);
    SDL_RenderClear(renderer.getSDLRenderer());
    renderer.present();
}
