#include "Barrier.hpp"
Barrier::Barrier(RendererPtr r,SDL_Rect& r_t):GameObject(r,r_t){
    SDL_Color color={71,68,68,255};
    wt->setBackgroundColor(color);
}

void Barrier::draw(){
    if(!isHide()){
        wt->draw();
    }
}

void Barrier::event_handle(SDL_Event*){
    
}