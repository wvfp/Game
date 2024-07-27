#ifndef _APPLICATION_
#define _APPLICATION_
#include <core/core.hpp>

//指向SDL_Window的指针类型
using WindowPtr = std::shared_ptr<SDL_Window>;

//指向SDL_Renderer的指针类型
using RendererPtr = std::shared_ptr<SDL_Renderer>;
//指向TTF_Font的指针类型
using FontPtr = std::shared_ptr<TTF_Font>;

//智能指针 WindowPtr 的deleter
void WinddowPtrDeleter(SDL_Window*);
//智能指针 RendererPtr 的deleter
void  RendererPtrDeleter(SDL_Renderer*);

//封装SDL的初始化操作，以及相关指针
class Application{
public: 
    Application(std::string name,SDL_Rect pos_size);
    virtual void draw();
    virtual void event_handle(SDL_Event*);
    virtual void present();
    virtual ~Application();
    virtual void setColor(SDL_Color={0xff,0xff,0xff,0xff});
    void setDisplay();
protected:
    //父类子类共有的成员

    WindowPtr window;
    RendererPtr render;
    FontPtr font;
    //Attributions
    std::string WindowName;
    SDL_Rect    WindowPos_Size;
    SDL_Color   WindowColor;
};

#endif
