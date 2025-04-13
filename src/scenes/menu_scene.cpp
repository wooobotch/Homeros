#include "menu_scene.hpp"
#include <iostream>

MenuScene::MenuScene(SceneManager& sceneManager)
    : sceneManager(sceneManager), options({"Iniciar", "Opciones", "Salir"}), selectedIndex(0), font(nullptr) {

    font = TTF_OpenFont("assets/fonts/FreeSans.ttf", 28);
    if (!font) {
        std::cerr << "Error cargando fuente: " << TTF_GetError() << std::endl;
    }

    std::cout << "MenuScene inicializada." << std::endl;
}

MenuScene::~MenuScene() {
    if (font) {
        TTF_CloseFont(font);
    }
}

void MenuScene::handleInput(SDL_Event& event) {
    if (event.type == SDL_QUIT) {
        exit(0);
    }

    if (event.type == SDL_KEYDOWN) {
        SDL_Keycode key = event.key.keysym.sym;
        if (key == SDLK_SPACE) {
            std::cout << "Saliendo desde el menú..." << std::endl;
            exit(0);
        } else if (key == SDLK_DOWN) {
            selectedIndex = (selectedIndex + 1) % options.size();
        } else if (key == SDLK_UP) {
            selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
        } else if (key == SDLK_RETURN || key == SDLK_KP_ENTER) {
            std::cout << "Seleccionado: " << options[selectedIndex] << std::endl;
            if (options[selectedIndex] == "Salir") {
                exit(0);
            } else if (options[selectedIndex] == "Iniciar"){
                sceneManager.changeScene("game");
            } else if (options[selectedIndex] == "Opciones"){
                sceneManager.changeScene("options");
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
                if (options[i] == "Salir") {
                    exit(0);
                } else if (options[selectedIndex] == "Iniciar"){
                    sceneManager.changeScene("game");
                } else if (options[selectedIndex] == "Opciones"){
                    sceneManager.changeScene("options");
                }
                // Acción específica según la opción
                break;
            }
        }
    }
}

void MenuScene::update() {
    // Algo, eventualmente
}

void MenuScene::render(Renderer& renderer) {
    SDL_SetRenderDrawColor(renderer.getSDLRenderer(), 20, 30, 60, 255);
    SDL_RenderClear(renderer.getSDLRenderer());

    int x = 100, y = 150;

    for (size_t i = 0; i < options.size(); ++i) {
        SDL_Color color = (i == selectedIndex)
                            ? SDL_Color{255, 255, 0, 255}  // Amarillo para seleccionado
                            : SDL_Color{255, 255, 255, 255}; // Blanco

        SDL_Texture* textTex = renderer.renderText(options[i], font, color);
        if (textTex) {
            renderer.renderTextTexture(textTex, x, y + static_cast<int>(i) * 50);
            SDL_DestroyTexture(textTex);
        }
    }
}
