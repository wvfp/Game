#ifndef _GAMEWIDGET_
#define _GAMEWIDGET_

#include <Widget.hpp>
#include <PushButton.hpp>
#include <tinyxml2.h>
#include <WidgetMaker.hpp>
#include "../../GameObject/GameObject.hpp"
#include "../level/level.hpp"

using namespace tinyxml2;



class gameWidget:public Widget{
public:
    gameWidget(RendererPtr,SDL_Rect);
    void initGameWidget();
    void initPushButton();
    void initStopWidget();
    void initStopWidgetPushButton(Action<PushButtonEvent>);
    void initLevel(int);
    void releaseLevel();
    void draw();
    void event_handle(SDL_Event*);
    void setState(bool);
private:
    LevelPtr level;
    WidgetPtr stopWidget;
    XMLDocument doc;
    bool stopping;
};


#endif
