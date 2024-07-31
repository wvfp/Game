#ifndef _WIDGET_
#define _WIDGET_
#include "Application.hpp"

class Widget;
using WidgetPtr = std::shared_ptr<Widget>;
using WidgetPtrList = std::list<WidgetPtr>;

class Widget
{
public:
    Widget(RendererPtr,SDL_Rect);
    virtual ~Widget();
    //更改Widget的大小
    void reSize(int w,int h);
    //更改Widget的位置，以左上角为基准
    void rePos(int x,int y);
    //进行绘制Widgwt中的元素
    virtual void draw();
    void drawBase();
    virtual void drawChild();
    virtual void event_handle(SDL_Event*);
    inline void hide(){
        _hide = !_hide;
        return;
    }
    inline void hideFrame(){
        _hide_frame =!_hide_frame;
        return;
    }
    inline bool isHide(){
        return _hide;
    }
    inline bool isHideFrame(){
        return _hide_frame;
    }
    void setParent(WidgetPtr p){
        parent = p;
        return;
    }
    void addChild(WidgetPtr w){
        ChildWidgetList.push_back(w);
        w->setParent(WidgetPtr(this));
        if(w->font==nullptr&&font)
            w->setFont(font);
        return;
    }
    void setBackgroundColor(SDL_Color color){
        bg_color = color;
    }
    void setFrameColor(SDL_Color color){
        f_color = color;
    }
    SDL_Point getPos(){
        return SDL_Point({Pos_Size.x,Pos_Size.y});
    }
    SDL_Rect getSize(){
        return Pos_Size;
    }
    SDL_Point getPrimaryPos(){
        SDL_Point p=SDL_Point({0,0});
        if(parent){
            p = parent->getPrimaryPos();
        }
        p.x += Pos_Size.x;
        p.y += Pos_Size.y;
        return p;
    }
    SDL_Rect getPrimaryRect(){
        SDL_Point p = getPrimaryPos();
        return SDL_Rect({p.x,p.y,Pos_Size.w,Pos_Size.h});
    }
    RendererPtr getRender(){
        return render;
    }
    void setFont(FontPtr f){
        font = f;
        return;
    }
protected:
    //子类可见
    RendererPtr render;
    WidgetPtr parent;
    WidgetPtrList ChildWidgetList;
    FontPtr font;
    SDL_Rect Pos_Size;
    bool _hide;
    bool _hide_frame;
    SDL_Color bg_color;
    SDL_Color f_color;
};


#endif
