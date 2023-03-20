#include "Application.h"


bool Application::IsRunning() {
    return m_running;
}

// Setup function (called once per game)
void Application::Setup() {
    m_running = Graphics::OpenWindow();
    // TODO: setup objects in the scene
}

// Input Detection & Processing (called every frame) 
void Application::Input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: // ALT + F4
                m_running = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    m_running = false;
                break;
        }
    }
}

// Update function (called once per frame)
void Application::Update() {
    // TODO: update all objects in the scene
}

// Render function (called several times per second to draw objects)
void Application::Render() {
    // Clear Screen with Solid Color (Format: A R G B)         
    Graphics::ClearScreen(COLOR_PURPLE);
    Graphics::DrawFillCircle(200, 200, 40, 0xFFFFFFFF);
    // Render the backbuffer context for this frame
    Graphics::RenderFrame();
}


// Destroy function to delete objects, close the window and free the memory
void Application::Destroy() {
    // TODO: destroy all objects in the scene
    Graphics::CloseWindow();
}