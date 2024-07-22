#include <Application.hpp>
#include <Texture.hpp>
#include <Widget.hpp>
#include <iostream>

class mainApplication:public Application {
public:
    using Application::render;
    mainApplication(std::string name,SDL_Rect P_S):Application(name,P_S){
        init();
        //SDL_SetWindowFullscreen(window.get(),SDL_WINDOW_FULLSCREEN_DESKTOP);
        //std::string ImgPath="./res/Pictures/a1.jpg";
        // static SurfacePtr sur =  LoadImageSurface(render,ImgPath);
        // SDL_SetWindowIcon(window.get(),sur.get());
        // SDL_Rect r = {0,0,500,500};
        // SDL_RenderSetViewport(render.get(),&r);
    }
    void draw();
    void init();
    void drawWidgets();
private:
    WidgetPtrList widgets;
    TexturePtr texture;
    TexturePtr tex ;
};

void mainApplication::draw(){
    SDL_SetRenderDrawColor(render.get(),0x0,0xff,0xa6,0xff);
    SDL_RenderClear(render.get());

  
    SDL_Rect srect={0,0,1000,1000};
    SDL_Rect rect={0,0,500,500};
    //SDL_QueryTexture(texture.get(),0,0,&srect.w,&srect.h); 
    SDL_RenderCopy(render.get(),texture.get(),NULL,&srect);
    srect = {0,0,250,30};
    SDL_RenderCopy(render.get(),tex.get(),NULL,&srect);
    SDL_Point p = (*(widgets.begin())).get()->getPos();
    (*(widgets.begin())).get()->rePos(p.x+1,p.y+1);
    drawWidgets();
}

void  mainApplication::init(){
    WidgetPtr w1{new Widget(render,{100,100,200,200})};
    w1->setBackgroundColor({0xff,0xff,0x0,0xff});
    WidgetPtr w2{new Widget(render,{0,40,75,75})};
    w2->setBackgroundColor({0xff,0x0 ,0x0,0xff});
    WidgetPtr w3{new Widget(render,{0,0,35,75})};
    w3->setBackgroundColor({0x0,0xff ,0x0,0xff});
    w2->addChild(w3);
    w1->addChild(w2);
    std::cout<<"Init"<<std::endl;
    widgets.push_back(w1);    
    
    std::string ImgPath="./res/Pictures/a2.webp";
    texture = LoadImageTexture(render,ImgPath.c_str());
    std::string str="Hello Games!";
    tex = LoadTextTexture(render,str,font,{0x0,0x0,0x0,0xff});
}

void mainApplication::drawWidgets(){
    for(auto i:widgets)
        i->draw();
    return;
}