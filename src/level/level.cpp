#include "level.hpp"

Level::Level(unsigned int l_id){
    level_id = l_id;
    running = true;
}
void Level::initLevel(){

}
void Level::draw(){
    for(auto i:GameObjectTable)
        i.second->draw();
}
void Level::event_handle(){

}

void Level::setLevelRunState(bool r){
    running = r;
}

void  Level::clearObject(){
    GameObjectTable.clear();
}