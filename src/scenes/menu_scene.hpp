#ifndef MENU_SCENE_HPP
#define MENU_SCENE_HPP

#include <vector>
#include <SDL2/SDL_ttf.h>
#include "scene.hpp"
#include "../renderer.hpp"
#include <string>

class MenuScene : public Scene {
public:
    MenuScene();
    ~MenuScene();

    void handleInput(SDL_Event& event) override;
    void update() override;
    void render(Renderer& renderer) override;

private:
    std::vector<std::string> options;
    int selectedIndex;
    TTF_Font* font;
};

#endif
