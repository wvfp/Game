#ifndef _GAMEWIDGET_
#define _GAMEWIDGET_

#include <Widget.hpp>
#include <PushButton.hpp>
#include <tinyxml2.h>
#include <WidgetMaker.hpp>

using namespace tinyxml2;

class Level;
using LevelPtr = std::shared_ptr<Level>;


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
private:
    //LevelPtr level;
    WidgetPtr stopWidget;
    XMLDocument doc;
};

// class Level{
// public:
//     Level(unsigned int l_id);
//     void initLevel();
//     void draw();
//     void event_handle();
//     unsigned int getLevelID(){
//         return level_id;
//     }

// private:
//     unsigned int level_id;
// };


#endif
