#ifndef _LEVEL_
#define _LEVEL_

#include "../../GameObject/GameObject.hpp"
#include "../../GameObject/Barrier.hpp"
class Level{
public:
    Level(RendererPtr);
    void initLevel(unsigned int);
    void draw();
    void event_handle(SDL_Event*);
    unsigned int getLevelID(){
        return level_id;
    }
    void clearObject();
    void setLevelRunState(bool r);
private:
    unsigned int level_id;
    bool running;
    std::map<unsigned int,GameObjectPtr> GameObjectTable;
    RendererPtr render;
};

using LevelPtr = std::shared_ptr<Level>;


#endif