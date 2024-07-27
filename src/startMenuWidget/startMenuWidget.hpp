#ifndef _STARTMENUWIDGET_
#define _STARTMENUWIDGET_
#include <Widget.hpp>
#include <tinyxml2.h>
#include <WidgetMaker.hpp>

using namespace tinyxml2;

class startMenuWidget:public Widget{
public:
    startMenuWidget(RendererPtr r,SDL_Rect r_t);
    void init();
    void initLabel();
    void initPushButton();
    void updata();
private:
    XMLDocument doc;
};


#endif