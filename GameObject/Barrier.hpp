#ifndef _BARRIER_
#define _BARRIER_

#include "GameObject.hpp"

class Barrier:public GameObject{
public:
    Barrier(RendererPtr,SDL_Rect&);
    void draw();
    void event_handle(SDL_Event*);
private:

};

using BarrierPtr = std::shared_ptr<Barrier>;

#endif
