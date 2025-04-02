#include "window.hpp"
#include <iostream>
#include <SDL2/SDL_timer.h>

Window::Window(const std::string& title, int width, int height, int targetFps)
    : window(nullptr), renderer(nullptr), running(true) {

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        running = false;
        return;
    }

    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "Error al crear la ventana: " << SDL_GetError() << std::endl;
        running = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Error al crear el renderer: " << SDL_GetError() << std::endl;
        running = false;
    }

    frameDelay = 1000 / targetFps; // Calculamos el tiempo de cada frame
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Window::isOpen() const {
    return running;
}

void Window::pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
    }
}

void Window::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Window::present() {
    SDL_RenderPresent(renderer);
}

void Window::delayFrame() const {
    SDL_Delay(frameDelay);
}

SDL_Window* Window::getSDLWindow() const {
    return window;
}

SDL_Renderer* Window::getSDLRenderer() const {
    return renderer;
}
