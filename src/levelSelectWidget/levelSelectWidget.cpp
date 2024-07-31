#include "levelSelectWidget.hpp"

levelSelectWidget::levelSelectWidget(RendererPtr r,SDL_Rect r_t):Widget(r,r_t){
    std::string xml_path="res/xml/Widgets/levelSelectWidget.xml";
    if(doc.LoadFile(xml_path.c_str())!=XML_SUCCESS){
        std::cerr<<"ERROR: can't load file "<<xml_path<<"\n error in startMenuWidget initialize"<<std::endl;
        std::abort();
    }
    level=0;
}
void levelSelectWidget::init(){   
    initLabel();
    initPushButton();
}
void levelSelectWidget::initLabel(){
    XMLElement *xml = doc.RootElement();
    XMLElement *l = xml->FirstChildElement("label");
    LabelPtr label;
    for(;l!=nullptr;l=l->NextSiblingElement("label")) {
        label = makeLabel(render,l,font);
        label->hideFrame();
        addChild(label);
    }
    return;
}
void levelSelectWidget::initPushButton(){
    XMLElement *xml = doc.RootElement();
    XMLElement *but = xml->FirstChildElement("button");
    const XMLAttribute *id ;
    //跳过第一个button
    but = but->NextSiblingElement("button");
    PushButtonPtr button;
    int level_id=0;
    for(;but!=nullptr;but=but->NextSiblingElement("button")){
        button = makePushButton(render,but,font);
        id = but->FirstChildElement("level")->FindAttribute("id");
        level_id = id->IntValue();
        Action<PushButtonEvent> a(
            [=](void*)->void{
                this->setLevelValue(level_id);
                std::cout<<"level selected: "<<getLevel()<<std::endl;
                return;
            },PushButtonEvent::ON_RELEASED,id->Name()
        );
        button->bindAction(a);
        addChild(button); 
    }
    
}
int  levelSelectWidget::getLevel(){
    return level;
}
void levelSelectWidget::setLevelValue(int v){
    level=v;
}

void levelSelectWidget::initButtonGoBack(Action<PushButtonEvent> act){
    XMLElement *xml = doc.RootElement();
    XMLElement *but = xml->FirstChildElement("button");
    PushButtonPtr button = makePushButton(render,but,font);
    button->bindAction(act);
    addChild(button);
}

