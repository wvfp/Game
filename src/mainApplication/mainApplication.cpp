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
    if(W_State == WidgetState::LEVELSELECTWIDGET){
        initGameWidget();
        Action<PushButtonEvent> act = Action<PushButtonEvent>([=](void*)->void{
                this->ChangeWidget(WidgetState::LEVELSELECTWIDGET);
                dynamic_cast<levelSelectWidget*>((this->widgets[LEVELSELECTWIDGET]).get())->setLevelValue(0);
            },PushButtonEvent::ON_CLICKED);
        dynamic_cast<gameWidget*>((widgets[WidgetState::GAMEWIDGET]).get())->initStopWidgetPushButton(act); 
        dynamic_cast<gameWidget*>((widgets[WidgetState::GAMEWIDGET]).get())->
        initLevel(dynamic_cast<levelSelectWidget*>((widgets[WidgetState::LEVELSELECTWIDGET]).get())->getLevel());
        if(dynamic_cast<levelSelectWidget*>((widgets[LEVELSELECTWIDGET]).get())->getLevel()>0)
            W_State = WidgetState::GAMEWIDGET;
    }
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
    Action<PushButtonEvent> act(
        [=](void*)->void{
            this->initLevelSelectWidget();
            this->ChangeWidget(WidgetState::LEVELSELECTWIDGET);
        },PushButtonEvent::ON_RELEASED,"Go back"
    );
    w->initButtonStartGame(act);
    widgets.push_back(w);
}

void mainApplication::initLevelSelectWidget(){
    static bool inited=false;
    if(!inited){
    std::shared_ptr<levelSelectWidget> w{new  levelSelectWidget(render,{0,0,640,480})};
    w->setFont(font);
    w->init();
    Action<PushButtonEvent> act(
        [=](void*)->void{
            this->ChangeWidget(WidgetState::STARTMENUWIDGET);
        },PushButtonEvent::ON_RELEASED,"Go back"
    );
    w->initButtonGoBack(act);
    widgets.push_back(w);
    inited=true;
    }
}
void mainApplication::initGameWidget(){
    static bool inited=false;
    if(!inited){
        std::shared_ptr<gameWidget> w{new gameWidget(render,{0,0,640,480})};
        w->setFont(font);
        w->initGameWidget();
        widgets.push_back(w);
        inited = true;
    }

}
