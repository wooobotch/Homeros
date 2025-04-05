#include "renderer.hpp"
#include <iostream>

Renderer::Renderer(Window& window) {
    renderer = SDL_CreateRenderer(window.getSDLWindow(), -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Error al crear renderer: " << SDL_GetError() << std::endl;
    }
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}

SDL_Texture* Renderer::loadTexture(const std::string& filePath) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath.c_str());
    if (!texture) {
        std::cerr << "Error cargando textura: " << IMG_GetError() << std::endl;
    }
    return texture;
}

// Alternativa a clear(), puede estar piola para generalizar, pero por qué un color liso?
//void Renderer::setClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
//    SDL_SetRenderDrawColor(sdlRenderer, r, g, b, a);
//}

void Renderer::renderTexture(SDL_Texture* texture, int x, int y, int w, int h) {
    SDL_Rect destRect = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}
