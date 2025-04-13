#include "options_scene.hpp"
#include <iostream>

OptionsScene::OptionsScene(SceneManager& sceneManager)
    : sceneManager(sceneManager), options({"Brillo", "Volumen", "Idioma", "Sorpresa", "Volver"}),
      selectedIndex(0),
      font(nullptr) {

    font = TTF_OpenFont("assets/fonts/FreeSans.ttf", 24);
    if (!font) {
        std::cerr << "Error cargando fuente en OptionsScene: " << TTF_GetError() << std::endl;
    }

    std::cout << "OptionsScene inicializada." << std::endl;
}

OptionsScene::~OptionsScene() {
    if (font) {
        TTF_CloseFont(font);
    }
}

void OptionsScene::handleInput(SDL_Event& event) {
    if (event.type == SDL_QUIT) {
        exit(0);
    }

    if (event.type == SDL_KEYDOWN) {
        SDL_Keycode key = event.key.keysym.sym;
        if (key == SDLK_KP_TAB) {
            std::cout << "Volviendo al menú..." << std::endl;
            sceneManager.changeScene("menu");
        } else if (key == SDLK_DOWN) {
            selectedIndex = (selectedIndex + 1) % options.size();
        } else if (key == SDLK_UP) {
            selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
        } else if (key == SDLK_RETURN || key == SDLK_KP_ENTER) {
            std::cout << "Elegiste: " << options[selectedIndex] << std::endl;
            if (options[selectedIndex] == "Volver") {
                sceneManager.changeScene("menu");
            } else if (options[selectedIndex] == "Sorpresa") {
                std::cout << "Algo va a pasar, eventualmente" << std::endl;
            }
        }
    }

    if (event.type == SDL_MOUSEMOTION) {
        int mouseX = event.motion.x;
        int mouseY = event.motion.y;

        int x = 100, y = 150;
        for (size_t i = 0; i < options.size(); ++i) {
            int w, h;
            TTF_SizeText(font, options[i].c_str(), &w, &h);
            SDL_Rect rect = {x, y + static_cast<int>(i) * 50, w, h};
            SDL_Point point{mouseX, mouseY};
            if (SDL_PointInRect(&point, &rect)) {
                selectedIndex = static_cast<int>(i);
                break;
            }
        }
    }

    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        int mouseX = event.button.x;
        int mouseY = event.button.y;

        int x = 100, y = 150;
        for (size_t i = 0; i < options.size(); ++i) {
            int w, h;
            TTF_SizeText(font, options[i].c_str(), &w, &h);
            SDL_Rect rect = {x, y + static_cast<int>(i) * 50, w, h};
            SDL_Point point{mouseX, mouseY};
            if (SDL_PointInRect(&point, &rect)) {
                std::cout << "Clickeado: " << options[i] << std::endl;
                if (options[selectedIndex] == "Volver"){
                    sceneManager.changeScene("menu");
                }
                // Acción específica según la opción
                break;
            }
        }
    }

}

void OptionsScene::update() {
    // Lógica futura
}

void OptionsScene::render(Renderer& renderer) {
    SDL_SetRenderDrawColor(renderer.getSDLRenderer(), 30, 30, 40, 255);
    SDL_RenderClear(renderer.getSDLRenderer());

    int x = 100, y = 120;

    for (size_t i = 0; i < options.size(); ++i) {
        SDL_Color color = (i == selectedIndex)
                            ? SDL_Color{0, 255, 255, 255}
                            : SDL_Color{200, 200, 200, 255};

        SDL_Texture* textTex = renderer.renderText(options[i], font, color);
        if (textTex) {
            renderer.renderTextTexture(textTex, x, y + static_cast<int>(i) * 50);
            SDL_DestroyTexture(textTex);
        }
    }

}
