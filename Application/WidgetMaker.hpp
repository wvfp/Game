#ifndef _WIDGETMAKER_
#define _WIDGETMAKER_

#include "Widget.hpp"
#include "PushButton.hpp"
#include "Label.hpp"
#include "tinyxml2.h"

using namespace tinyxml2;
//根据XML文件加载资源和创建widget实例

WidgetPtr makeWidget(RendererPtr,std::string);
WidgetPtr makeWidget(RendererPtr,XMLElement*);

// PushButtonPtr makePushButton(RendererPtr,::string);
// PushButtonptr makePushButton(RendererPtr,XMLElement*);

LabelPtr makeLabel(RendererPtr,std::string);
LabelPtr makeLabel(RendererPtr,XMLElement*);
PushButtonPtr makePushButton(RendererPtr,XMLElement*,FontPtr);

SDL_Point makePosition(XMLElement*);
SDL_Rect  makeRect(XMLElement*);
SDL_Color makeColor(XMLElement*);
std::string makeText(XMLElement*);


#endif