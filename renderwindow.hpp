#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Entity.hpp"
#include <iostream>


class renderwindow{
public:
    renderwindow(const char * p_title, int p_w, int p_h);
    void renderclear();
    void renderdisplay();
    void fillcolour(int r, int g, int b, int a);
    SDL_Texture* LoadTextureMe(const char *p_filepath);
    void render(Entity& p_entity);
    void cleanup();
private:   
    SDL_Window* window;
    SDL_Renderer* renderer;
};