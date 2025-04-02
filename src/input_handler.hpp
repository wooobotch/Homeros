#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <SDL2/SDL.h>

class InputHandler {
public:
    InputHandler();
    void handleEvents(bool &running); // Maneja eventos y actualiza la variable running
};

#endif
