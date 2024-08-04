#ifndef _ROLE_
#define _ROLE_

#include "GameObject.hpp"
#include <Label.hpp>
class Role:public GameObject{
public:
    Role(RendererPtr,SDL_Rect);
    void draw();
    void event_handle(SDL_Event*);
    void ground();
    void update();
private:
    int speeds[2];
};

using RolePtr = std::shared_ptr<Role>;

#endif //_ROLE_