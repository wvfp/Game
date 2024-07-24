#include "PushButton.hpp"


Action<PushButtonEvent> PushButton::defaultAction = Action<PushButtonEvent>(
    [](void*)->void{},
    PushButtonEvent::ON_NONE,
    std::string("default")
);

PushButton::PushButton(RendererPtr r,SDL_Rect rt):
    Widget(r,rt),text_Color({0xff,0xff,0xff,0xff}),
    text_content(""),PBEvent(PushButtonEvent::ON_NONE)
{
    Action_List.push_back(defaultAction);
}
    //按钮事件处理
void PushButton::event_handle(SDL_Event*event){
    if(!isHide()){

        SDL_Point p{event->button.x,event->button.y};
        switch(event->type){
        case SDL_MOUSEBUTTONDOWN:
            if(isPointInRect(p,getPrimaryRect()))
                PBEvent = PushButtonEvent(ON_CLICKED);
            break;
        case SDL_MOUSEBUTTONUP:
            if(isPointInRect(p,getPrimaryRect()))
                PBEvent = PushButtonEvent(ON_RELEASED);
        case SDL_MOUSEMOTION:
            if(isPointInRect(p,getPrimaryRect()))
                PBEvent = PushButtonEvent(ON_SELECTED);
        }
        //std::cout<<int(PBEvent)<<std::endl;
        (Action_List.front())();
        actAction();
    }

}
//判断是否执行后,执行响应函数
void PushButton::actAction(){
    using PB = PushButtonEvent;
    switch (PBEvent) {
    case PB::ON_CLICKED:
        for(auto i:Action_List){
            if(i.getEventType()==PB::ON_CLICKED)
                i();
        }
        break;
    case PB::ON_PRESSED:
        for(auto i:Action_List){
            if(i.getEventType()==PB::ON_PRESSED)
                i();
        }
        break;
    case PB::ON_RELEASED:
        for(auto i:Action_List){
            if(i.getEventType()==PB::ON_RELEASED)
                i();
        }
        break;
    case PB::ON_CLICKED_AND_PRESSED:
        for(auto i:Action_List){
            if(i.getEventType()==PB::ON_CLICKED)
                i();
        }
        for(auto i:Action_List){
            if(i.getEventType()==PB::ON_PRESSED)
                i();
        }
        PBEvent = PB::ON_PRESSED;
        break;
    case PB::ON_NONE:
    default:
        for(auto i:Action_List){
            if(i.getEventType()==PB::ON_NONE)
                i();
        }
        break;
    }
     //重置按钮状态
    //PBEvent = PushButtonEvent::ON_NONE;
}
    //设置图标
void PushButton::setIcon(TexturePtr _icon){
    icon = _icon;
}
void PushButton::setIcon(std::string path){
    icon = LoadImageTexture(render,path);
}
    //设置文本
void PushButton::setText(std::string t_c,SDL_Color color,float rate){
    text_content = t_c;
    text_Color = color;
    if(font)
        text = LoadTextTexture(render,text_content,font,text_Color);
    else
        std::cout<<"Warning :Font is no seting"<<std::endl;
}
    //设置颜色
void PushButton::setTextColor(SDL_Color c){
    text_Color = c;
    //update the text texture to new color
    if(font)
        text = LoadTextTexture(render,text_content,font,text_Color);
}


void PushButton::updata(){
    if(PBEvent==PushButtonEvent::ON_SELECTED)
        SDL_SetTextureColorMod(icon.get(),128,128,128);

}
void PushButton::draw(){
    updata();
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
        //设置widget的背景
        //保存render的颜色
        SDL_Color preColor;
        SDL_GetRenderDrawColor(render.get(),
        &preColor.r,&preColor.g,&preColor.b,&preColor.a);
        //设置render为widget的背景颜色
        SDL_SetRenderDrawColor(render.get(),bg_color.r,bg_color.g,bg_color.b,bg_color.a);
        //填颜色
        SDL_RenderFillRect(render.get(),&Pos_Size);
        //绘制Button 图标
        if(icon){
            SDL_RenderCopy(render.get(),icon.get(),nullptr,&Pos_Size);
        }
        //绘制Button 文本
        if(text){
            SDL_RenderCopy(render.get(),text.get(),nullptr,&Pos_Size);
        }
        //判断是不是有边框
        if(!isHideFrame()){
            //绘制边框
            SDL_SetRenderDrawColor(render.get(),f_color.r,f_color.g,f_color.b,f_color.a);
            SDL_RenderDrawRect(render.get(),&Pos_Size);
        }
        //重置颜色
        SDL_SetRenderDrawColor(render.get(),preColor.r,preColor.b,preColor.g,preColor.a);
        //绘制子widget
        //drawChild();
        if(parent){
            SDL_RenderSetViewport(render.get(),&preRect);
        }
    }
}