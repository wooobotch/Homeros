#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "scene.hpp"
#include "../renderer.hpp"
#include "../scene_manager.hpp"
//#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class GameScene : public Scene {
public:
    GameScene(SceneManager& sceneManager);
    ~GameScene();

    void handleInput(SDL_Event& event) override;
    void update() override;
    void render(Renderer& renderer) override;

private:
    SceneManager& sceneManager;
    TTF_Font* font;
};

#endif
