#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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

private:
    SDL_Renderer* renderer;
};

#endif
