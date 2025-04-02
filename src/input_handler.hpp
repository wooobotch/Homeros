#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <SDL2/SDL.h>
#include "scene_manager.hpp"

class InputHandler {
public:
    InputHandler(SceneManager& sceneManager);
    void handleEvents(bool &running); // Maneja eventos y actualiza la variable running

private:
    SceneManager& sceneManager;
};

#endif
