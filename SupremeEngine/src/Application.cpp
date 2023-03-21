#include "Application.h"
#include "Constants.h"


bool Application::IsRunning() {
    return m_running;
}

// Setup function (called once per game)
void Application::Setup() {
    m_running = Graphics::OpenWindow();
    // TODO: setup objects in the scene
    m_particle = new Particle(Vec2(100, 100), 1.0f);
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

    // frame rate independence
    static int timePreviousFrame; // default value is 0
    //while (!SDL_TICKS_PASSED(SDL_GetTicks(), timePreviousFrame + MILLISECS_PER_FRAME));
    //int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - timePreviousFrame);
    //if (timeToWait > 0)
    //{
    //    SDL_Delay(timeToWait);
    //}
    float deltaTime = (SDL_GetTicks() - timePreviousFrame) / 1000.0f;
    if (deltaTime > 0.016)
    {
        deltaTime = 0.016f;
    }

    timePreviousFrame = SDL_GetTicks();

    m_particle->setVelocity(Vec2(100.0f*deltaTime, 30.0f*deltaTime));
    m_particle->setPosition(m_particle->getPosition() + m_particle->getVelocity());
}

// Render function (called several times per second to draw objects)
void Application::Render() {
    // Clear Screen with Solid Color (Format: A R G B)         
    Graphics::ClearScreen(COLOR_PURPLE);
    Graphics::DrawFillCircle(200, 200, 40, COLOR_WHITE);
    Graphics::DrawFillCircle(m_particle->getPosition(), 20, COLOR_LIME);
    // Render the backbuffer context for this frame
    Graphics::RenderFrame();
}


// Destroy function to delete objects, close the window and free the memory
void Application::Destroy() {

    delete m_particle;
    // TODO: destroy all objects in the scene
    Graphics::CloseWindow();
}