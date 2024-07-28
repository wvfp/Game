#include "mainApplication.hpp"


void mainApplication::ChangeWidget(WidgetState w_s){
    W_State = w_s;
    return;
}


void mainApplication::draw(){
    //更新显示状态
    setDisplay();
	SDL_SetRenderDrawColor(render.get(), WindowColor.r,WindowColor.b ,WindowColor.g, WindowColor.a); // 设置绘制颜色
    SDL_RenderClear(render.get());
    drawWidgets();
}

void  mainApplication::init(){
    W_State = WidgetState::STARTMENUWIDGET;
    initStartMenuWidget();
    return;
}

void mainApplication::event_handle(SDL_Event* event){
    widgets[W_State]->event_handle(event);
    return;
}


void mainApplication::drawWidgets(){
    widgets[W_State]->draw();
    return;
}
void mainApplication::initStartMenuWidget(){
    std::shared_ptr<startMenuWidget> w{new startMenuWidget(render,{0,0,640,480})};
    w->setFont(font);
    w->init();
    widgets.push_back(w);
}

void mainApplication::initLevelSelectWidget(){

}
void mainApplication::initGameWidget(){

}
