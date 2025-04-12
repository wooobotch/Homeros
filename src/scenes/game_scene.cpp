#include "game_scene.hpp"
#include <iostream>

GameScene::GameScene(SceneManager& sceneManager)
    : sceneManager(sceneManager), font(nullptr) {
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
        if (event.key.keysym.sym == SDLK_ESCAPE) {
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
    SDL_SetRenderDrawColor(renderer.getSDLRenderer(), 10, 50, 10, 255); // Fondo verde oscuro
    SDL_RenderClear(renderer.getSDLRenderer());

    // Lugar para renderizar
    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Texture* textTex = renderer.renderText("Escena de juego en progreso... [ESC vuelve al menú]", font, textColor);
    if (textTex) {
        renderer.renderTextTexture(textTex, 50, 100);
        SDL_DestroyTexture(textTex);
    }

    renderer.present();
}
