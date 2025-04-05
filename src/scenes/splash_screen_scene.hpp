#ifndef SPLASH_SCREEN_SCENE_HPP
#define SPLASH_SCREEN_SCENE_HPP

#include "scene.hpp"
#include "../renderer.hpp"
#include <SDL2/SDL.h>
#include <string>

class SplashScreenScene : public Scene {
private:
    SDL_Texture* logoTexture;
    Uint32 startTime;
    const Uint32 duration = 3000; // 3 segundos

public:
    SplashScreenScene(Renderer& renderer, const std::string& logoPath);
    ~SplashScreenScene();

    void handleInput(SDL_Event& event) override;
    void update() override;
    void render(Renderer& renderer) override;
};

#endif
