#include "Role.hpp"

Role::Role(RendererPtr r,SDL_Rect r_t):GameObject(r,r_t){
    std::string path{"./res/Pictures/role.png"};
    dynamic_cast<Label*>(wt.get())->setTexture(path);
    speeds[0] = 0.;
    speeds[1] = 0.;
}

void Role::draw(){
    wt->draw();
}

void Role::event_handle(SDL_Event* event){
    int max_speed=10;
    int g=5; 
    if(event->type==SDL_KEYDOWN){
         switch(event->key.keysym.sym)
         {
         case SDLK_w:
            if(Pos_Size.h+Pos_Size.y==400)
              speeds[1] = -10; 
             break;
         case SDLK_a:
            speeds[0] -=3 ;
            if(speeds[0]<-max_speed)
                speeds[0]=-max_speed; 
             break;
         case SDLK_d:
            speeds[0] += 3;
            if(speeds[0]>max_speed)
                speeds[0]=max_speed; 
             break;

         }
    }

    update();
}

void Role::ground(){
    if(Pos_Size.y+Pos_Size.h>400){
        Pos_Size.y = 400-Pos_Size.h;
        speeds[1]=0;
    }
}

void Role::update(){

    Pos_Size.x += speeds[0];
    Pos_Size.y += speeds[1];
    if(speeds[0]<0)
        speeds[0]++;
    if(speeds[0]>0)
        speeds[0]--;
    speeds[1]++;
    ground();
    wt->rePos(Pos_Size.x,Pos_Size.y);

}