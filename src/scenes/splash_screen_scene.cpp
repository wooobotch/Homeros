#include "splash_screen_scene.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

SplashScreenScene::SplashScreenScene(Renderer& renderer, const std::string& logoPath)
    : logoTexture(nullptr), startTime(SDL_GetTicks()) {
    logoTexture = renderer.loadTexture(logoPath);
    if (!logoTexture) {
        std::cerr << "Error cargando la imagen del splash screen: " << IMG_GetError() << std::endl;
    }
}

SplashScreenScene::~SplashScreenScene() {
    if (logoTexture) {
        SDL_DestroyTexture(logoTexture);
    }
}

void SplashScreenScene::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        }
    }
}

void SplashScreenScene::update() {
    if (SDL_GetTicks() - startTime > duration) {
        std::cout << "Splash Screen terminado. Cambiar a la siguiente escena." << std::endl;
        // Aquí iría la lógica para cambiar a otra escena
    }
}

void SplashScreenScene::render(Renderer& renderer) {
    renderer.clear();
    if (logoTexture) {
        renderer.renderTexture(logoTexture, 100, 100, 300, 200); // Posición y tamaño arbitrarios
    }
    renderer.present();
}
