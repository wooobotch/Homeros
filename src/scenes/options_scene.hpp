#ifndef OPTIONS_SCENE_HPP
#define OPTIONS_SCENE_HPP

#include "scene.hpp"
#include <vector>
#include <string>
#include <SDL2/SDL_ttf.h>

class OptionsScene : public Scene {
public:
    OptionsScene();
    ~OptionsScene();

    void handleInput(SDL_Event& event) override;
    void update() override;
    void render(Renderer& renderer) override;

private:
    std::vector<std::string> options;
    int selectedIndex;
    TTF_Font* font;
};

#endif
