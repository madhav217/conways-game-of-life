#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


class Entity{
public:
    
    Entity(){exist = false;}
    Entity(float p_x, float p_y, SDL_Texture*p_txt,bool status);

    void update();

    float getX();
    void setX(float x1);

    float getY();
    void setY(float y1);

    SDL_Texture* getTxt();

    SDL_Rect getCurrentFrame();
   
    bool exist;
    int neighbourcount;

    //people tell me to make getter. but why?
private:
    float x,y;
    SDL_Texture* txt;
    SDL_Rect currentFrame;
    
    
};