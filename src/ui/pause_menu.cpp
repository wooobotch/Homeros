#include "ui/pause_menu.hpp"
#include "renderer.hpp"  // Asegurate que Renderer tenga métodos como drawRect, drawText o similares
#include <iostream>

PauseMenu::PauseMenu(Renderer& renderer, int screenWidth, int screenHeight)
    : renderer(renderer), active(false), selectedIndex(0),
      screenWidth(screenWidth), screenHeight(screenHeight)
{
    font = TTF_OpenFont("assets/fonts/FreeSans.ttf", 24);
    if (!font) {
        std::cerr << "Error al cargar fuente para PauseMenu: " << TTF_GetError() << std::endl;
    }

    textColor = {255, 255, 255, 255};       // Blanco
    selectedColor = {255, 215, 0, 255};     // Dorado
    bgColor = {0, 0, 0, 200};               // Negro semi-transparente

    initOptions();
}

PauseMenu::~PauseMenu() {
    if (font) {
        TTF_CloseFont(font);
    }
}

void PauseMenu::initOptions() {
    options.push_back({"Reanudar", [this]() { toggle(); }});
    options.push_back({"Guardar Partida", []() { std::cout << "Guardar aún no implementado\n"; }});
    options.push_back({"Cargar Partida", []() { std::cout << "Cargar aún no implementado\n"; }});
    options.push_back({"Salir", []() { std::cout << "Salir aún no implementado\n"; }});
}

void PauseMenu::toggle() {
    active = !active;
}

bool PauseMenu::isActive() const {
    return active;
}

void PauseMenu::handleInput(const SDL_Event& event) {
    if (!active) return;

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                toggle();  // También se cierra con ESC
                break;
            case SDLK_UP:
                selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
                break;
            case SDLK_DOWN:
                selectedIndex = (selectedIndex + 1) % options.size();
                break;
            case SDLK_RETURN:
            case SDLK_KP_ENTER:
                if (selectedIndex >= 0 && selectedIndex < options.size()) {
                    options[selectedIndex].action();
                }
                break;
            default:
                break;
        }
    }
}

void PauseMenu::render() {
    if (!active) return;

    renderBackground();

    int baseY = screenHeight / 2 - static_cast<int>(options.size()) * 30 / 2;

    for (size_t i = 0; i < options.size(); ++i) {
        renderText(options[i].label, screenWidth / 2, baseY + static_cast<int>(i) * 40, i == selectedIndex);
    }
}

void PauseMenu::renderBackground() {
    SDL_Rect bg = {screenWidth / 4, screenHeight / 4, screenWidth / 2, screenHeight / 2};
    renderer.drawRect(bg, bgColor, true);
}

void PauseMenu::renderText(const std::string& text, int x, int y, bool selected) {
    SDL_Color color = selected ? selectedColor : textColor;
    renderer.drawText(font, text, x, y, color, true);  // `true` indica centrado a drawText
}
