#ifndef _LEVEL_
#define _LEVEL_

#include "../../GameObject/GameObject.hpp"

class Level{
public:
    Level(unsigned int l_id);
    void initLevel();
    void draw();
    void event_handle();
    unsigned int getLevelID(){
        return level_id;
    }
    void clearObject();
    void setLevelRunState(bool r);
private:
    unsigned int level_id;
    bool running;
    std::map<unsigned int,GameObjectPtr> GameObjectTable;
};




#endif