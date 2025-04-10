#include "options_scene.hpp"
#include <iostream>

OptionsScene::OptionsScene()
    : options({"Brillo", "Volumen", "Idioma", "Sorpresa"}), selectedIndex(0), font(nullptr) {

    font = TTF_OpenFont("assets/fonts/FreeSans.ttf", 28);
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
        if (key == SDLK_ESCAPE) {
            std::cout << "Volviendo al menú..." << std::endl;
            // Presuponemos acceso global o singleton a SceneManager, o se adapta a tu flujo.
            // Lo ideal es que SceneManager se pase por referencia en constructor como en SplashScreenScene.
            // Por ahora puedes modificar el constructor si querés que vuelva.
        } else if (key == SDLK_DOWN) {
            selectedIndex = (selectedIndex + 1) % options.size();
        } else if (key == SDLK_UP) {
            selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
        } else if (key == SDLK_RETURN || key == SDLK_KP_ENTER) {
            std::cout << "Elegiste: " << options[selectedIndex] << " (sin acción por ahora)." << std::endl;
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

    renderer.present();
}
