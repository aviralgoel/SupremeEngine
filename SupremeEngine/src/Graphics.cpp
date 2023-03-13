#include "Graphics.h"
#include <iostream>

// Static variable definitions
SDL_Window* Graphics::m_window = NULL;
SDL_Renderer* Graphics::m_renderer = NULL;
int Graphics::m_windowWidth = 0;
int Graphics::m_windowHeight = 0;

int Graphics::Width() {
    return m_windowWidth;
}

int Graphics::Height() {
    return m_windowHeight;
}

bool Graphics::OpenWindow() {
    
    // Check if SDL initialization is successful
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL\n";
        return false;
    }

    // fetch screen width and height using SDL
    SDL_DisplayMode display_mode;
    SDL_GetCurrentDisplayMode(0, &display_mode);
    m_windowWidth = display_mode.w;
    m_windowHeight = display_mode.h;
    
    //create a full screen window
    m_window = SDL_CreateWindow(NULL, 0, 0, m_windowWidth, m_windowHeight, SDL_WINDOW_BORDERLESS);
    if (!m_window) {
        std::cerr << "Error creating SDL window\n";
        return false;
    }
    // create a rendering context
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_renderer) {
        std::cerr << "Error creating SDL renderer\n";
        return false;
    }
    return true;
}

void Graphics::ClearScreen(Uint32 color) {
    // associate a color with the rendering context
    SDL_SetRenderDrawColor(m_renderer, color >> 16, color >> 8, color, 255);
    // wash the context with that color
    SDL_RenderClear(m_renderer);
}

void Graphics::RenderFrame() {

    // render the backbuffer all at once
    SDL_RenderPresent(m_renderer);
}

void Graphics::DrawLine(int x0, int y0, int x1, int y1, Uint32 color) {
    lineColor(m_renderer, x0, y0, x1, y1, color);
}

void Graphics::DrawCircle(int x, int y, int radius, float angle, Uint32 color) {
    circleColor(m_renderer, x, y, radius, color);
    lineColor(m_renderer, x, y, x + cos(angle) * radius, y + sin(angle) * radius, color);
}

void Graphics::DrawFillCircle(int x, int y, int radius, Uint32 color) {
    filledCircleColor(m_renderer, x, y, radius, color);
}

void Graphics::DrawRect(int x, int y, int width, int height, Uint32 color) {
    lineColor(m_renderer, x - width / 2.0, y - height / 2.0, x + width / 2.0, y - height / 2.0, color);
    lineColor(m_renderer, x + width / 2.0, y - height / 2.0, x + width / 2.0, y + height / 2.0, color);
    lineColor(m_renderer, x + width / 2.0, y + height / 2.0, x - width / 2.0, y + height / 2.0, color);
    lineColor(m_renderer, x - width / 2.0, y + height / 2.0, x - width / 2.0, y - height / 2.0, color);
}

void Graphics::DrawFillRect(int x, int y, int width, int height, Uint32 color) {
    boxColor(m_renderer, x - width / 2.0, y - height / 2.0, x + width / 2.0, y + height / 2.0, color);
}

void Graphics::DrawPolygon(int x, int y, const std::vector<Vec2>& vertices, Uint32 color) {
    for (int i = 0; i < vertices.size(); i++) {
        int currIndex = i;
        int nextIndex = (i + 1) % vertices.size();
        lineColor(m_renderer, vertices[currIndex].m_x, vertices[currIndex].m_y, vertices[nextIndex].m_x, vertices[nextIndex].m_y, color);
    }
    filledCircleColor(m_renderer, x, y, 1, color);
}

void Graphics::DrawFillPolygon(int x, int y, const std::vector<Vec2>& vertices, Uint32 color) {
    std::vector<short> vx;
    std::vector<short> vy;
    for (int i = 0; i < vertices.size(); i++) {
        vx.push_back(static_cast<int>(vertices[i].m_x));
    }
    for (int i = 0; i < vertices.size(); i++) {
        vy.push_back(static_cast<int>(vertices[i].m_y));
    }
    filledPolygonColor(m_renderer, &vx[0], &vy[0], vertices.size(), color);
    filledCircleColor(m_renderer, x, y, 1, 0xFF000000);
}

void Graphics::DrawTexture(int x, int y, int width, int height, float rotation, SDL_Texture* texture) {
    SDL_Rect dstRect = {x - (width / 2), y - (height / 2), width, height};
    float rotationDeg = rotation * 57.2958;
    SDL_RenderCopyEx(m_renderer, texture, NULL, &dstRect, rotationDeg, NULL, SDL_FLIP_NONE);
}

void Graphics::CloseWindow(void) {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}