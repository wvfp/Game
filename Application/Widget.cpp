#include "Widget.hpp"
#include "tools.hpp"

Widget::Widget(RendererPtr r,SDL_Rect p_s):render(r),Pos_Size(p_s),parent(nullptr),
_hide(false),_hide_frame(false){
    bg_color = {0xff,0xff,0xff,0xff};
    f_color = {0x0,0x0,0x0,0xff};
}

Widget::~Widget()
{
}
//更改Widget的大小
void Widget::reSize(int w,int h){
    Pos_Size.w = w;
    Pos_Size.h = h;
}
//更改Widget的位置，以左上角为基准
void Widget::rePos(int x,int y){
    Pos_Size.x = x;
    Pos_Size.y = y;
}
//进行绘制Widgwt中的元素
void Widget::draw(){
    //判断是否隐藏
    if(!isHide()){
        SDL_Rect preRect;
        if(parent){
            SDL_RenderGetViewport(render.get(),&preRect);
            SDL_Rect nowRect = getPrimaryRect();
            SDL_Rect edge=nowRect;
            edge.w=std::min(preRect.w+preRect.x,nowRect.w+nowRect.x)-nowRect.x;
            edge.h=std::min(preRect.h+preRect.y,nowRect.h+nowRect.y)-nowRect.y;
            SDL_RenderSetViewport(render.get(),&edge);
        }
        drawBase();
        //绘制子widget
        drawChild();
        if(parent){
            SDL_RenderSetViewport(render.get(),&preRect);
        }
    }
}

void Widget::drawBase(){
    //设置widget的背景
    //保存render的颜色
    SDL_Color preColor;
    SDL_GetRenderDrawColor(render.get(),
                           &preColor.r,&preColor.g,&preColor.b,&preColor.a);
    //设置render为widget的背景颜色
    SDL_SetRenderDrawColor(render.get(),bg_color.r,bg_color.g,bg_color.b,bg_color.a);
    //填颜色
    SDL_RenderFillRect(render.get(),&Pos_Size);
    //判断是不是有边框
    if(!isHideFrame()){
        //绘制边框
        SDL_SetRenderDrawColor(render.get(),f_color.r,f_color.g,f_color.b,f_color.a);
        SDL_RenderDrawRect(render.get(),&Pos_Size);
    }
    //重置颜色
    SDL_SetRenderDrawColor(render.get(),preColor.r,preColor.b,preColor.g,preColor.a);
}

void Widget::drawChild(){
    for(auto i = ChildWidgetList.rbegin();i!=ChildWidgetList.rend();i++){
        (*i)->draw();
    }
    return;
}
void Widget::event_handle(SDL_Event* event){
    for(auto i:ChildWidgetList)
        i->event_handle(event);
    return;
}
