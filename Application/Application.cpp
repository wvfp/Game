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


Application::Application(std::string name,SDL_Rect pos_size):WindowName(name),
WindowPos_Size(pos_size){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG/*|IMG_INIT_JPG|IMG_INIT_WEBP*/);
    TTF_Init();
    window = WindowPtr(SDL_CreateWindow(name.c_str(),WindowPos_Size.x,WindowPos_Size.y,WindowPos_Size.w,WindowPos_Size.h,SDL_WINDOW_SHOWN),
    WinddowPtrDeleter);
    render = RendererPtr(SDL_CreateRenderer(window.get(),-1,0),RendererPtrDeleter);
    SDL_RenderSetLogicalSize(render.get(),1280,960);
    font = TTF_OpenFont("./res/Fonts/game_ttf2.ttf",128);

}

void Application::draw(){
	SDL_SetRenderDrawColor(render.get(), 0x0,0x0 ,0x0, 255); // 设置绘制颜色为白色
	SDL_RenderClear(render.get());						  // 清空渲染器
    return;
}

void Application::event_handle(SDL_Event* event){

}

void Application::present(){
    	SDL_RenderPresent(render.get());
}

Application::~Application(){
    TTF_CloseFont(font);
    SDL_Quit();
}