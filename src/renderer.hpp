#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "window.hpp"

class Renderer {
public:
    Renderer(Window& window);
    ~Renderer();

    void clear();
    void present();
    SDL_Renderer* getSDLRenderer() const { return renderer; };

    SDL_Texture* loadTexture(const std::string& filePath);
    void renderTexture(SDL_Texture* texture, int x, int y, int w, int h);

    SDL_Texture* renderText(const std::string& message, TTF_Font* font, SDL_Color color);
    void renderTextTexture(SDL_Texture* texture, int x, int y);

    void drawRect(const SDL_Rect& rect, SDL_Color color, bool filled = true);

    void drawText(TTF_Font* font, const std::string& message, int x, int y, SDL_Color color, bool centered = false);

//Ver renderer.cpp
//    void setClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

private:
    SDL_Renderer* renderer;
};

#endif
