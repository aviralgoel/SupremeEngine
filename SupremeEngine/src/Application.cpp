#include "Application.h"
#include "Constants.h"


bool Application::IsRunning() {
    return m_running;
}

// Setup function (called once per game)
void Application::Setup() {
    m_running = Graphics::OpenWindow();
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



    float deltaTime = (SDL_GetTicks() - m_lastFrameTime)/1000.0f;
    m_lastFrameTime = SDL_GetTicks();
    if (deltaTime > 0.016) 	deltaTime = 0.016; 

    m_particle->m_acceleration = Vec2(2.0f, 9.8f);
    m_particle->m_velocity += m_particle->m_acceleration * deltaTime * PIXELS_PER_METER;
    m_particle->m_position += m_particle->m_velocity * deltaTime;

    CheckBoundaryLimits();


}

void Application::CheckBoundaryLimits()
{
    if (m_particle->m_position.m_y > Graphics::Height() - m_particle->m_radius) { // down wall
        m_particle->m_position.m_y = Graphics::Height() - m_particle->m_radius;
        m_particle->m_velocity.m_y *= -0.9f;
    }
    if (m_particle->m_position.m_x > Graphics::Width() - m_particle->m_radius) { // right wall
        m_particle->m_position.m_x = Graphics::Width() - m_particle->m_radius;
        m_particle->m_velocity.m_x *= -0.9f;
    }
    if (m_particle->m_position.m_x <= m_particle->m_radius) { // left wall
        m_particle->m_position.m_x = m_particle->m_radius;
        m_particle->m_velocity.m_x *= -0.9f;
    }
    if (m_particle->m_position.m_y <= m_particle->m_radius) { // up wall
        m_particle->m_position.m_y = m_particle->m_radius;
        m_particle->m_velocity.m_y *= -0.9f;
    }
}

// Render function (called several times per second to draw objects)
void Application::Render() {
    Graphics::ClearScreen(COLOR_PURPLE);
    Graphics::DrawFillCircle(m_particle->m_position.m_x, m_particle->m_position.m_y, m_particle->m_radius, COLOR_BLUE);
    Graphics::RenderFrame();
}


// Destroy function to delete objects, close the window and free the memory
void Application::Destroy() {

    delete m_particle;
    // TODO: destroy all objects in the scene
    Graphics::CloseWindow();
}