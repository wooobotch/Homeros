#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height, int targetFps = 60);
    ~Window();

    bool isOpen() const;
    void pollEvents();
    void clear();
    void present();
    void delayFrame() const;

    SDL_Window* getSDLWindow() const;

private:
    SDL_Window* window;
    bool running;
    int frameDelay;
};

#endif
