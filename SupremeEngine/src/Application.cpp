#include "Application.h"
#include "Constants.h"


bool Application::IsRunning() {
    return m_running;
}

// Setup function (called once per game)
void Application::Setup() {
    m_running = Graphics::OpenWindow();
    // TODO: setup objects in the scene
    m_particle = new Particle(Vec2(100, 100), 10.0f, 10.0f);
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

    //int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - m_lastFrameTime);
    //if (timeToWait > 0)
    //{
    //    SDL_Delay(timeToWait);
    //}
    //m_lastFrameTime = SDL_GetTicks();

    float deltaTime = (SDL_GetTicks() - m_lastFrameTime)/1000.0f;
    m_lastFrameTime = SDL_GetTicks();

    m_particle->m_velocity = Vec2(100*deltaTime, 100*deltaTime);
    m_particle->m_position += m_particle->m_velocity;

}

// Render function (called several times per second to draw objects)
void Application::Render() {
    // Clear Screen with Solid Color (Format: A R G B)         
    Graphics::ClearScreen(COLOR_PURPLE);
    //Graphics::DrawFillCircle(200, 200, 40, COLOR_WHITE);
    Graphics::DrawFillCircle(m_particle->m_position.m_x, m_particle->m_position.m_y, m_particle->m_radius, COLOR_BLUE);
    // Render the backbuffer context for this frame
    Graphics::RenderFrame();
}


// Destroy function to delete objects, close the window and free the memory
void Application::Destroy() {

    delete m_particle;
    // TODO: destroy all objects in the scene
    Graphics::CloseWindow();
}