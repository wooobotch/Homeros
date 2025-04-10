#ifndef OPTIONS_SCENE_HPP
#define OPTIONS_SCENE_HPP

#include "scene.hpp"
#include <vector>
#include <string>
#include <SDL2/SDL_ttf.h>
#include "../renderer.hpp"
#include "../scene_manager.hpp"

class OptionsScene : public Scene {
public:
    OptionsScene(SceneManager& sceneManager);
    ~OptionsScene();

    void handleInput(SDL_Event& event) override;
    void update() override;
    void render(Renderer& renderer) override;

private:
    std::vector<std::string> options;
    int selectedIndex;
    TTF_Font* font;
    SceneManager& sceneManager;
};

#endif
