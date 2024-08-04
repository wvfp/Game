#include "level.hpp"

Level::Level(RendererPtr r){
    level_id =0;
    running = true;
    render = r;   
}
void Level::initLevel(unsigned int){
    SDL_Rect G = {0,400,640,80};
    GameObjectPtr ptr=BarrierPtr(new Barrier(render,G));
    GameObjectTable[ptr->getUID()] = ptr;    
}
void Level::draw(){
    if(running){
        for(auto i:GameObjectTable)
            i.second->draw();
    }
}
void Level::event_handle(SDL_Event* event){
    if(running){
        for(auto i:GameObjectTable)
            i.second->event_handle(event);
    }
}

void Level::setLevelRunState(bool r){
    running = r;
}

void  Level::clearObject(){
    GameObjectTable.clear();
}