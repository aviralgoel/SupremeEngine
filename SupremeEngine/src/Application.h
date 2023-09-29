#pragma once

#include "./Graphics.h"
#include "Physics/Particle.h"

class Application {
    private:
        bool m_running = false;
        Particle* m_particle;
        int m_lastFrameTime = 0;


    public:
        Application() = default;
        ~Application() = default;
        bool IsRunning();
        void Setup();
        void Input();
        void Update();
        void CheckBoundaryLimits();
        void Render();
        void Destroy();
};