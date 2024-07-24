#include "tools.hpp"

//判断点是不是在矩形内
bool isPointInRect(SDL_Point p,SDL_Rect rect){
    bool result =  (p.x>rect.x)&&(p.x < rect.x + rect.w );
    result = result&&(p.y>rect.y)&&(p.y < rect.y + rect.h );
    return result;
}
//判断两个矩形的关系
WidgetRelationship getRelationshipOfRect(SDL_Rect,SDL_Rect){
   //暂时不定义
    return WidgetRelationship();
}
