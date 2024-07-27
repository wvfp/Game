#include "Application.hpp"

void WinddowPtrDeleter(SDL_Window* window){
    SDL_DestroyWindow(window);
    window = nullptr;
    return;
}

void RendererPtrDeleter(SDL_Renderer* render){
    SDL_DestroyRenderer(render);
    render = nullptr;
    return;
}

void FontPtrDeleter(TTF_Font* font){
    TTF_CloseFont(font);
    font = nullptr;
    return;
}

Application::Application(std::string name,SDL_Rect pos_size):WindowName(name),
WindowPos_Size(pos_size){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG/*|IMG_INIT_JPG|IMG_INIT_WEBP*/);
    TTF_Init();
    window = WindowPtr(SDL_CreateWindow(name.c_str(),WindowPos_Size.x,WindowPos_Size.y,WindowPos_Size.w,WindowPos_Size.h,SDL_WINDOW_RESIZABLE),
    WinddowPtrDeleter);
    render = RendererPtr(SDL_CreateRenderer(window.get(),-1,0),RendererPtrDeleter);
    SDL_RenderSetLogicalSize(render.get(),640,480);
    font = FontPtr(TTF_OpenFont("./res/Fonts/game_ttf2.ttf",128),FontPtrDeleter);
    WindowColor = {0,0,0,0xff};
}

void Application::draw(){
    setDisplay();
	SDL_SetRenderDrawColor(render.get(), WindowColor.r,WindowColor.b ,WindowColor.g, WindowColor.a); // 设置绘制颜色
	SDL_RenderClear(render.get());						     // 用颜色填充Application绘制区域
    return;
}


void Application::present(){
    	SDL_RenderPresent(render.get());
}
//对设置进行统一
void Application::setDisplay(){

    SDL_Rect p={0,0,WindowPos_Size.w,WindowPos_Size.h};
    //SDL_RenderSetViewport(render.get(),&p);

    SDL_DisplayMode dm;
    SDL_GetWindowDisplayMode(window.get(),&dm);
    if(dm.w<dm.h)
        std::swap(dm.w,dm.h);
    SDL_SetWindowDisplayMode(window.get(),&dm);
    SDL_RenderSetLogicalSize(render.get(),640,480);
    SDL_RenderSetViewport(render.get(),&p);
}

Application::~Application(){
    SDL_Quit();
}

void Application::event_handle(SDL_Event* event){

}

void Application::setColor(SDL_Color c){
    WindowColor = c;
    return ;
}