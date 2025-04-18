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

SDL_Texture* Renderer::renderText(const std::string& message, TTF_Font* font, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, message.c_str(), color);
    if (!surface) {
        std::cerr << "Error creando superficie de texto: " << TTF_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        std::cerr << "Error creando textura de texto: " << SDL_GetError() << std::endl;
    }

    return texture;
}

void Renderer::renderTextTexture(SDL_Texture* texture, int x, int y) {
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

void Renderer::drawRect(const SDL_Rect& rect, SDL_Color color, bool filled) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);  // Necesario para alpha
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    if (filled) {
        SDL_RenderFillRect(renderer, &rect);
    } else {
        SDL_RenderDrawRect(renderer, &rect);
    }
}

void Renderer::drawText(TTF_Font* font, const std::string& message, int x, int y, SDL_Color color, bool centered) {
    SDL_Texture* texture = renderText(message, font, color);
    if (!texture) return;

    SDL_Rect destRect;
    SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);

    destRect.x = centered ? x - destRect.w / 2 : x;
    destRect.y = centered ? y - destRect.h / 2 : y;

    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    SDL_DestroyTexture(texture);  // Evitamos fugas
}
