#include "FPSControler.hpp"

FPSControler::FPSControler(uint16_t f){
    fps = f ;
    return;
}

uint64_t FPSControler::start(){
    isStart = true;
    start_time = SDL_GetTicks();
    last_time = start_time;
    return start_time;
}
uint64_t FPSControler::stop(){
    isStart = false;
    stop_time = SDL_GetTicks();
    return start_time;
}
uint64_t FPSControler::tick(){
    int64_t delay=0;
    uint64_t now = SDL_GetTicks();
    if(isStart){
      delay = now - last_time;
      delay = (1000/fps - delay)>0?(1000/fps- delay):0;
      SDL_Delay(delay);
    }  
    last_time = now;
    return now; 
}