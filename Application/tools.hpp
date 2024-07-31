#ifndef  _TOOLS_HPP_
#define  _TOOLS_HPP_

#include <core/core.hpp>

enum class WidgetRelationship{
    CONTAIN, //两个形状一个包含另一个
    INTERSET,//两个形状相交
    DISTENCE,//两个形状相离
};

//判断一个点在不在一个矩形内(不包含边界
bool isPointInRect(SDL_Point p,SDL_Rect rect);
//判断两个矩形的关系
WidgetRelationship getRelationshipOfRect(SDL_Rect,SDL_Rect);
#endif //_TOOLS_HPP

