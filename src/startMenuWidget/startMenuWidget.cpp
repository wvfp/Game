#include "startMenuWidget.hpp"

startMenuWidget::startMenuWidget(RendererPtr r,SDL_Rect r_t)
:Widget(r,r_t){
    std::string xml_path="res/xml/Widgets/startMenuWidget.xml";
    if(doc.LoadFile(xml_path.c_str())!=XML_SUCCESS){
        std::cerr<<"ERROR: can't load file "<<xml_path<<"\n error in startMenuWidget initialize"<<std::endl;
        std::abort();
    }

}
void startMenuWidget::init(){
    XMLElement *root = doc.RootElement();
    bg_color = makeColor(root);
    initLabel();
    initPushButton();
    return;
}

void startMenuWidget::updata(){

}  
void startMenuWidget::initLabel(){
    XMLElement *root = doc.RootElement();
    XMLElement *l = root->FirstChildElement("label");
    SDL_Point p;
    SDL_Rect r;
    SDL_Color c;
    std::string str;
    LabelPtr label;
    for(;l!=nullptr;l=l->NextSiblingElement()){
        p = makePosition(l);
        r = makeRect(l);
        r.x=p.x,r.y=p.y;
        c = makeColor(l);
        str = makeText(l);
        label = LabelPtr(new  Label(render,r));
        label->setFont(font);
        label->setText(str);
        label->setBackgroundColor(c);
        addChild(label);
    }
}

void startMenuWidget::initPushButton(){

}