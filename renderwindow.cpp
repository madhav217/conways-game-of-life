#include "renderwindow.hpp"


renderwindow::renderwindow(const char* p_title, int p_w, int p_h):window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow( p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN );

    	if (!window){
		printf("window could not be created");
	    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void renderwindow::renderclear(){
    //these two are combined but should they not be?
    SDL_RenderClear(renderer);	
}

void renderwindow::renderdisplay(){
    SDL_RenderPresent(renderer);
}


void renderwindow::fillcolour(int r, int g, int b, int a){
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

SDL_Texture* renderwindow::LoadTextureMe(const char *p_filepath){
    SDL_Texture * texture = NULL;

    texture = IMG_LoadTexture(renderer, p_filepath);

    if (texture == NULL){
        printf("texture failed to load %s \n", SDL_GetError());
    }

    return texture;
}

void renderwindow::render(Entity& p_entity){
    SDL_Rect source;
    source.x = p_entity.getCurrentFrame().x;
    source.y = p_entity.getCurrentFrame().y;
    source.w = p_entity.getCurrentFrame().w;
    source.h = p_entity.getCurrentFrame().h;

    SDL_Rect dest;
    dest.x = p_entity.getX();  
    dest.y = p_entity.getY();
    dest.w = p_entity.getCurrentFrame().w;
    dest.h = p_entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_entity.getTxt(), &source, &dest);
}

void renderwindow::cleanup(){
    SDL_DestroyWindow(window);
}