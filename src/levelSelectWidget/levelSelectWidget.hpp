#ifndef _LEVELSELECTWIDGET_
#define _LEVELSELECTWIDGET_
#include <Widget.hpp>
#include <tinyxml2.h>
#include <WidgetMaker.hpp>

using namespace tinyxml2;

class levelSelectWidget:public Widget{
public:
    levelSelectWidget(RendererPtr,SDL_Rect);
    void init();
    void initLabel();
    void initPushButton();
    int getLevel();
    void setLevelValue(int);
    void initButtonGoBack(Action<PushButtonEvent>);
private: 
    XMLDocument doc;
    int level;
};



#endif //_LEVELSELECTWIDGET_