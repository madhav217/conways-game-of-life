#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, SDL_Texture*p_txt, bool status, int entitySize){
    exist = status;
    x = p_x;
    y = p_y;
    txt = p_txt;

    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = entitySize;
    currentFrame.h = entitySize;
}

//void Entity::toggleexist(){
//    exist = (exist+1)%2;
//}
void Entity::update(){
    int temp = neighbourcount;
    if(temp < 2){exist=0;} //underpopulation
	else if(temp == 3){exist=1;} //reproductions
	else if(temp > 3){exist=0;} //overpopulation
									//sum = 2 stagnation is implied
}

float Entity::getX(){
    return x;
}

void Entity::setX(float x1){
    x = x1;
}

float Entity::getY(){
    return y;
}

void Entity::setY(float y1){
    y = y1;
}


SDL_Texture* Entity::getTxt(){
    return txt;
}

SDL_Rect Entity::getCurrentFrame(){
    return currentFrame;
}

