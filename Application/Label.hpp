#ifndef _LABEL_HPP_
#define _LABEL_HPP_

#include "Widget.hpp"
#include "Texture.hpp"

class Label:public Widget{
public:
    Label(RendererPtr,SDL_Rect);
    void setText(std::string,SDL_Color={0x0,0x0,0x0,0x0});
    void setTextColor(SDL_Color);
    void setTexture(std::string);
    void setTexture(TexturePtr);
    void setFont(std::string);
    void setFont(FontPtr);
    void initializeFromXML();
    void draw();
private:
    TexturePtr text;
    std::string text_content;
    SDL_Color text_color;
    FontPtr font;
    TexturePtr texture;
};

using LabelPtr = std::shared_ptr<Label>;

#endif // LABEL_HPP
