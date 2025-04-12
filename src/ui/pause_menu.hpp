#ifndef PAUSE_MENU_HPP
#define PAUSE_MENU_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <functional>

class Renderer; // Forward declaration para evitar dependencias cruzadas

class PauseMenu {
public:
    PauseMenu(Renderer& renderer, int screenWidth, int screenHeight);
    ~PauseMenu();

    void handleInput(const SDL_Event& event);
    void render();
    void toggle();  // Abre o cierra el menú
    bool isActive() const;

private:
    struct MenuOption {
        std::string label;
        std::function<void()> action;
    };

    Renderer& renderer;
    bool active;
    int selectedIndex;
    int screenWidth;
    int screenHeight;

    std::vector<MenuOption> options;

    // Estética
    TTF_Font* font;
    SDL_Color textColor;
    SDL_Color selectedColor;
    SDL_Color bgColor;

    void initOptions();
    void renderText(const std::string& text, int x, int y, bool selected);
    void renderBackground();
};

#endif
