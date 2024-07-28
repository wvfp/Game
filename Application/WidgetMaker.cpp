#include "WidgetMaker.hpp"
#include <string>
#include <iostream>

WidgetPtr makeWidget(RendererPtr render,std::string xmlpath){
    XMLDocument xml;
    if(xml.LoadFile(xmlpath.c_str())){
        std::cerr<<"Error:can't load file:"<<xmlpath<<"\nerror in makeWidget"<<std::endl;
        std::abort(); 
    }
    XMLElement* widget_node = xml.RootElement();
    WidgetPtr widget = makeWidget(render,widget_node);
    return widget;
}


WidgetPtr makeWidget(RendererPtr render,XMLElement* xml){
    SDL_Color bg_c={0,0,0,0};
    SDL_Rect Pos_Size={0,0,0,0};    
    bg_c=makeColor(xml);
    Pos_Size=makeRect(xml);
    SDL_Point pos=makePosition(xml);
    Pos_Size.x = pos.x;
    Pos_Size.y = pos.y;
    WidgetPtr widget{new Widget(render,Pos_Size)};
    widget->setBackgroundColor(bg_c);
    XMLElement *node=nullptr;
    for(node=xml->FirstChildElement("label");node!=nullptr;node=node->NextSiblingElement()){
        widget->addChild(makeLabel(render,node));
    }
    return widget;
}

LabelPtr makeLabel(RendererPtr render,std::string xmlpath){
    XMLDocument xml;
    if(xml.LoadFile(xmlpath.c_str())){
        std::cerr<<"Error:can't load file:"<<xmlpath<<"\nerror in makeLabel"<<std::endl;
        std::abort(); 
    }
    XMLElement* Label_node = xml.RootElement();
    LabelPtr label = makeLabel(render,Label_node);
    return label;
}

LabelPtr makeLabel(RendererPtr render,XMLElement*xml){

    SDL_Color bg_c={0,0,0,0};
    SDL_Rect Pos_Size={0,0,0,0};    
    bg_c=makeColor(xml);
    Pos_Size=makeRect(xml);
    SDL_Point pos=makePosition(xml);
    Pos_Size.x = pos.x;
    Pos_Size.y = pos.y;

    LabelPtr label{new Label(render,Pos_Size)};
    label->setBackgroundColor(bg_c);

    std::string text;
    XMLElement* node = xml->FirstChildElement("text");
    if(node)
        text = node->GetText();
    std::string path;
    node = xml->FirstChildElement("font");
    if(node){
        path = node->FindAttribute("src") != 0 ?node->FindAttribute("src")->Value():"";
    }
    if(!path.empty())
        label->setFont(path);
    label->setText(text);
    return label; 
}

PushButtonPtr makePushButton(RendererPtr render,XMLElement* but,FontPtr font){
    SDL_Point p;
    SDL_Rect r;
    std::string str;
    PushButtonPtr button;
    SDL_Rect t_r;
    XMLElement* t_z;
    const XMLAttribute * attrib;
    if(but){
        p = makePosition(but);
        r = makeRect(but);
        r.x=p.x,r.y=p.y;
        str = makeText(but);
        button = PushButtonPtr(new PushButton(render,r));
        button->setFont(font);
        button->setText(str,{0,0,0,0xff});
        t_z = but->FirstChildElement("text");
        attrib = t_z->FindAttribute("x");
        t_r.x = attrib->IntValue();
        attrib = t_z->FindAttribute("y");
        t_r.y = attrib->IntValue();
        attrib = t_z->FindAttribute("w");
        t_r.w = attrib->IntValue();
        attrib = t_z->FindAttribute("h");
        t_r.h = attrib->IntValue();
        button->setTextRect(t_r);
    }
    return button;
}




SDL_Point makePosition(XMLElement*xml){
    XMLElement* node=nullptr;
    const XMLAttribute* attrib=nullptr;   
    node = xml->FirstChildElement("position");
    SDL_Point Pos={0,0};
    if(node){
        attrib = node->FindAttribute("x");
        Pos.x = attrib->IntValue();
        attrib = node->FindAttribute("y");
        Pos.y = attrib->IntValue();
    }
    return Pos;
}
SDL_Rect  makeRect(XMLElement*xml){
    XMLElement* node=nullptr;
    const XMLAttribute* attrib=nullptr;
    node = xml->FirstChildElement("size");
    SDL_Rect Rect={0,0,0,0};
    if(node){
        attrib = node->FindAttribute("width");
        Rect.w = attrib->IntValue();
        attrib = node->FindAttribute("height");
        Rect.h = attrib->IntValue();
    }
    return Rect;
}



SDL_Color makeColor(XMLElement*xml){
    XMLElement* node=nullptr;
    const XMLAttribute* attrib=nullptr;
    node=xml->FirstChildElement("color");

    SDL_Color color={0,0,0,0xff}; 
    if(node){
        attrib = node->FindAttribute("r");
        color.r = attrib->IntValue();
        attrib = node->FindAttribute("g");
        color.g = attrib->IntValue();
        attrib = node->FindAttribute("b");
        color.b = attrib->IntValue();
    }
    return color;
}


std::string makeText(XMLElement*xml){
    XMLElement* node=nullptr;
    const XMLAttribute* attrib=nullptr;
    node=xml->FirstChildElement("text");
    std::string text;
    if(node){
        text = node->GetText();
    }
    return text;
}

