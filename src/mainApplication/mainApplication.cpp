#include "mainApplication.hpp"

void mainApplication::draw(){
    //更新显示状态
    setDisplay();
	SDL_SetRenderDrawColor(render.get(), WindowColor.r,WindowColor.b ,WindowColor.g, WindowColor.a); // 设置绘制颜色
    SDL_RenderClear(render.get());
    drawWidgets();
}

void  mainApplication::init(){
    WidgetPtr w1{new Widget(render,{0,0,WindowPos_Size.w,WindowPos_Size.h})};
    w1->setBackgroundColor({0xff,0xff,0xff,0xff});
    widgets.push_back(w1);
}

void mainApplication::event_handle(SDL_Event* event){
    for(auto i:widgets){
        i->event_handle(event);
    }

}


void mainApplication::drawWidgets(){
    for(auto i = widgets.rbegin();i!=widgets.rend();i++)
        (*i)->draw();
    return;
}
