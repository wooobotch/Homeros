#ifndef SCENE_HPP
#define SCENE_HPP

#include <SDL2/SDL.h>
#include "../renderer.hpp"

class Scene {
public:
    virtual ~Scene() = default;

    virtual void handleInput(SDL_Event& event) = 0;

    virtual void update() = 0;

    virtual void render(Renderer& renderer) = 0;
};

#endif
