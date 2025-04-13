#include "game_scene.hpp"
#include <iostream>

GameScene::GameScene(SceneManager& sceneManager, Renderer& renderer)
    : sceneManager(sceneManager), font(nullptr), pauseMenu(renderer, 400, 400) {
    font = TTF_OpenFont("assets/fonts/FreeSans.ttf", 24);
    if (!font) {
        std::cerr << "Error cargando fuente en GameScene: " << TTF_GetError() << std::endl;
    }

    std::cout << "GameScene inicializada." << std::endl;
}

GameScene::~GameScene() {
    if (font) {
        TTF_CloseFont(font);
    }
}

void GameScene::handleInput(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_SPACE) {
//            std::cout << "Volviendo al menú..." << std::endl;
//            std::cout << "Volviendo al menú..." << std::endl;
//            sceneManager.changeScene("menu");
              isPaused = !isPaused;
        }
    }

    if (isPaused) {
        pauseMenu.handleInput(event);
        return;
    }

    if (event.type == SDL_QUIT) {
        exit(0);
    }
}

void GameScene::update() {
    if (isPaused) return;
    // Más lógica por acá.
}

void GameScene::render(Renderer& renderer) {
    SDL_SetRenderDrawColor(renderer.getSDLRenderer(), 10, 50, 10, 255); // Fondo verde oscuro
    SDL_RenderClear(renderer.getSDLRenderer());

    // Lugar para renderizar
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Texture* textTex = renderer.renderText("Escena de juego en progreso... [ESC vuelve al menú]", font, textColor);
    if (textTex) {
        renderer.renderTextTexture(textTex, 50, 100);
        SDL_DestroyTexture(textTex);
    }

    if (isPaused) {
        pauseMenu.render();  // Superpone el menú
    }

}
