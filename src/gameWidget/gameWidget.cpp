#include "gameWidget.hpp"


gameWidget::gameWidget(RendererPtr r,SDL_Rect r_t):Widget(r,r_t){
    std::string xml_path="res/xml/Widgets/gameWidget.xml";
    if(doc.LoadFile(xml_path.c_str())!=XML_SUCCESS){
        std::cerr<<"ERROR: can't load file "<<xml_path<<"\n error in gameWidget initialize"<<std::endl;
        std::abort();
    }
    stopping = false;
}

void gameWidget::initGameWidget(){
    XMLElement *root = doc.RootElement();
    XMLElement *but = root->FirstChildElement("button");
    PushButtonPtr button = makePushButton(render,but,font);
    TexturePtr tex = makeImage(render,but); 
    but = but->FirstChildElement("img");
    std::string str=but->GetText();
    button->setIcon(str);
    addChild(button);
    Action<PushButtonEvent> act{
        [=](void*)->void{
            setState(true);
        },PushButtonEvent::ON_CLICKED
    };
    button->bindAction(act);
    initStopWidget();
}

void gameWidget::initStopWidget(){
    XMLElement* root = doc.RootElement();
    XMLElement* wt = root->FirstChildElement("widget");
    stopWidget = makeWidget(render,wt,font);
    // addChild(stopWidget);
}
void gameWidget::initStopWidgetPushButton(Action<PushButtonEvent> act_gb){
    XMLElement* root = doc.RootElement();
    XMLElement* but = root->FirstChildElement("widget")->FirstChildElement("button");
    PushButtonPtr button = makePushButton(render,but,font);
    Action<PushButtonEvent> act{
        [=](void*)->void{
            setState(false);
        },PushButtonEvent::ON_CLICKED
    };
    button->bindAction(act);
    stopWidget->addChild(button);
    but = but->NextSiblingElement("button");
    button = makePushButton(render,but,font);
    button->bindAction(act_gb);
    act = Action<PushButtonEvent>(
        [=](void*)->void{
            setState(false);
        },PushButtonEvent::ON_CLICKED
    );
    button -> bindAction(act);
    stopWidget->addChild(button);
}

void gameWidget::draw(){
    drawBase();
    for(auto i:ChildWidgetList)
        i->draw();
    if(level)
        level->draw();
    if(stopping)
        stopWidget->draw();
}
void gameWidget::event_handle(SDL_Event *event){
    if(stopping)
        stopWidget->event_handle(event);
    else{
        for(auto i:ChildWidgetList)
            i->event_handle(event);
        if(level)
            level->event_handle(event);
    }
}

void gameWidget::setState(bool s){
    stopping = s;
}


void gameWidget::releaseLevel(){
    level->clearObject();
}

void gameWidget::initLevel(int l){
    level = LevelPtr(new Level(render));
    level->initLevel(l);
}

void gameWidget::update(){
    level->update();
}