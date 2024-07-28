#include "PushButton.hpp"


Action<PushButtonEvent> PushButton::defaultAction = Action<PushButtonEvent>(
    [](void*)->void{/*std::cout<<"Hi"<<std::endl;*/},
    PushButtonEvent::ON_NONE,
    std::string("default")
);

PushButton::PushButton(RendererPtr r,SDL_Rect rt):
    Widget(r,rt),text_Color({0,0,0,0xff}),
    text_content(""),PBEvent(PushButtonEvent::ON_NONE)
{
    Action_List.push_back(defaultAction);
    text_rect = {0,0,rt.w,rt.h};
}
    //按钮事件处理
void PushButton::event_handle(SDL_Event*event){
    if(!isHide()){
        //重置按钮状态
        PBEvent = PushButtonEvent::ON_NONE;
        SDL_Point p{event->motion.x,event->motion.y};

        switch(event->type){
        case SDL_MOUSEBUTTONDOWN:
            if(isPointInRect(p,getPrimaryRect()))
                PBEvent = ON_CLICKED;
            //std::cout<<"x:"<<event->button.x<<std::endl;
	    	//std::cout<<"y:"<<event->button.y<<std::endl;
            break;
        case SDL_MOUSEBUTTONUP:
            if(isPointInRect(p,getPrimaryRect()))
                PBEvent = ON_RELEASED;
            break;
        case SDL_MOUSEMOTION:
            if(isPointInRect(p,getPrimaryRect()))
                PBEvent = ON_SELECTED;
            break;
        default:
            PBEvent = ON_NONE;
            break;
        }
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
}
    //设置图标
void PushButton::setIcon(TexturePtr _icon){
    icon = _icon;
}
void PushButton::setIcon(std::string path){
    icon = LoadImageTexture(render,path);
}
    //设置文本
void PushButton::setText(std::string t_c,SDL_Color color){
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

    switch (PBEvent)
    {
    case ON_CLICKED:
     if(!changed){
            Pos_Size.x-=2;
            Pos_Size.y-=2;
            Pos_Size.w+=4;
            Pos_Size.h+=4;
            changed = true;
        }
    case ON_SELECTED:

        SDL_SetTextureColorMod(icon.get(),200,200,200);
        SDL_SetTextureColorMod( text.get(),200,200,200);
   
        break;
    default:
        SDL_SetTextureColorMod(icon.get(),0xff,0xff,0xff);  
        SDL_SetTextureColorMod(text.get(),0xff,0xff,0xff);  
        if(changed){
            Pos_Size.x+=2;
            Pos_Size.y+=2;
            Pos_Size.w-=4;
            Pos_Size.h-=4;
            changed = false;
        }
        break;
    }
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
            SDL_RenderCopy(render.get(),text.get(),nullptr,&text_rect);
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

void PushButton::setTextRect(const SDL_Rect& r){
    text_rect = r;
}
