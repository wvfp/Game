#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <functional>
#include "global.hpp"
using namespace std;

//user-defined event handel function defination
typedef std::function < void (void *) > _Fun;
_Fun empty_fun =[](void *)->void { };

//constant of button state
enum ButtonState{
    STRESSED,
    UNSTRESSED
};
//the class of button
class Button{
public:
    Button(){};
    Button(SDL_Renderer*_render):render(_render){
       texture=NULL;
    };
    void handle(SDL_Event& event){
       if(render) SDL_GetRendererOutputSize(render,&G_Rect.w,&G_Rect.h);
      if (event.type== SDL_FINGERUP || event.type == SDL_FINGERMOTION || event.type == SDL_FINGERDOWN){
      //get current position
      SDL_Point mousePos = { int(event.tfinger.x * G_Rect.w), int(event.tfinger.y *G_Rect.h) };
      if(mousePos.x>B_Rect.x&&
         mousePos.y>B_Rect.y&&
         mousePos.x<(B_Rect.x+B_Rect.w)&&
         mousePos.y<(B_Rect.y+B_Rect.h)){
      switch(event.type){
          case SDL_FINGERDOWN:
          case SDL_FINGERMOTION:
              state=STRESSED;
              Event_Handeler(NULL);
              break;
          case SDL_FINGERUP:
              state=UNSTRESSED;
             // Event_Handeler(NULL);
              break;
      }
      }
      
    }
    }
    void setTexture(SDL_Texture*tex){
        texture=tex;
    }
    void setText(string txt){
        text=loadFromRendererText(render,txt);
    }
    void setIcon(string path){
        texture=loadPicture(path);
    }
    void draw(){
        SDL_Rect desRect=B_Rect;
        if(state==STRESSED){
            desRect.x-=5;
            desRect.y-=5;
            desRect.w+=10;
            desRect.h+=10;
        }
        SDL_RenderCopy(render, texture, NULL, &desRect);
        SDL_RenderCopy(render, text, NULL, &desRect);
    };
    //user-defined event handel function 
    _Fun Event_Handeler=empty_fun;
    void setPos(SDL_Point& p){
        B_Pos=p;
        B_Rect.x=p.x;
        B_Rect.y=p.y;
    }
    void setSize(SDL_Rect &r){
        B_Rect.w=r.w;
        B_Rect.h=r.h;
    }
    void setRect(SDL_Rect &r){
        B_Rect=r;
        B_Pos.x=r.x;
        B_Pos.y=r.y;
    }
private:
    //button state
    ButtonState state=UNSTRESSED;
    SDL_Texture* texture;
    SDL_Texture* text;
    SDL_Renderer*render;
    SDL_Point B_Pos;
    SDL_Rect  B_Rect;
    SDL_Rect  G_Rect;
    
};




#endif //_BUTTON_HPP_