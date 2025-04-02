#ifndef SCENE_HPP
#define SCENE_HPP

#include "../renderer.hpp"

class Scene {
public:
    virtual ~Scene() = default;

    // Para manejar la entrada del usuario
    virtual void handleInput() = 0;

    // Para actualizar la lógica de la escena
    virtual void update() = 0;

    // Para renderizar la escena
    virtual void render(Renderer& renderer) = 0;
};

#endif
