#include "Label.hpp"

Label::Label(RendererPtr r,SDL_Rect r_t)
    :Widget(r,r_t)
{
    text_rect = r_t;
    text_rect.x = 0;
    text_rect.y = 0;
}
void Label::setText(std::string t_c,SDL_Color color){
    text_content = t_c;
    text_color = color;
    if(font)
        text = LoadTextWrappedTexture(render,text_content,font,text_color);
    else
        std::cout<<"Warning :Font is no seting"<<std::endl;
}
//设置颜色
void Label::setTextColor(SDL_Color c){
    text_color = c;
    //update the text texture to new color
    if(font)
        text = LoadTextWrappedTexture(render,text_content,font,text_color);
}

void Label::setFont(std::string path){
    font = FontPtr(TTF_OpenFont(path.c_str(),20),FontPtrDeleter);
}

void Label::setFont(FontPtr f){
    font = f;
    return;
}
void Label::setTexture(std::string p){
    texture = LoadImageTexture(render,p);
    return;
}
void Label::setTexture(TexturePtr t){
    texture = t;
    return;
}

void Label::setTextRect(SDL_Rect r){
    text_rect= r;
}

void Label::draw(){
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
        if(texture){
            SDL_RenderCopy(render.get(),texture.get(),nullptr,&Pos_Size);
        }
        if(text){
            SDL_RenderCopy(render.get(),text.get(),nullptr,&text_rect);
        }
        //绘制子widget
        drawChild();
        if(parent){
            SDL_RenderSetViewport(render.get(),&preRect);
        }

    }
}



