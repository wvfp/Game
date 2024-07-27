#ifndef _LABEL_HPP_
#define _LABEL_HPP_

#include "Widget.hpp"
#include "Texture.hpp"

class Label:public Widget{
public:
    Label(RendererPtr,SDL_Rect);
    void setText(std::string,SDL_Color);
    void setTextColor(SDL_Color);
    void setTexture(std::string);
    void setTexture(TexturePtr);
    void setFont(FontPtr);
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
