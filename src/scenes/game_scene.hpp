#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "scene.hpp"
#include "../renderer.hpp"
#include "../scene_manager.hpp"
//#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../ui/pause_menu.hpp"

class GameScene : public Scene {
public:
    GameScene(SceneManager& sceneManager, Renderer& renderer);
    ~GameScene();

    void handleInput(SDL_Event& event) override;
    void update() override;
    void render(Renderer& renderer) override;

private:
    SceneManager& sceneManager;
    PauseMenu pauseMenu;
    TTF_Font* font;
    bool isPaused = false;
};

#endif
