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
    initLabel();
    initPushButton();
    initSettingWidget();
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
    for(;l!=nullptr;l=l->NextSiblingElement("label")){
        p = makePosition(l);
        r = makeRect(l);
        r.x=p.x,r.y=p.y;
        c = makeColor(l);
        str = makeText(l);
        label = LabelPtr(new  Label(render,r));
        label->setFont(font);
        label->setText(str);
        label->setBackgroundColor(c);
        label->hideFrame();
        addChild(label);
    }
}

void startMenuWidget::initPushButton(){
    XMLElement *root = doc.RootElement();
    XMLElement *but = root->FirstChildElement("button");
    PushButtonPtr button;
    //跳过一个按钮
    but = but->NextSiblingElement("button");
    button = makePushButton(render,but,font);
    addChild(button);
    Action<PushButtonEvent> B(
        [&](void*)->void{
            this->setSettingWidgetState(true);
        },PushButtonEvent::ON_CLICKED
    );
    button->bindAction(B);
}

void startMenuWidget::initSettingWidget(){
    XMLElement *root = doc.RootElement();
    XMLElement *wt = root->FirstChildElement("widget");
    settingWidget = makeWidget(render,wt,font);
    //返回
    wt = wt->FirstChildElement("button");
    PushButtonPtr button=makePushButton(render,wt,font);
    Action<PushButtonEvent> act(
        [=](void*)->void{
            this->setSettingWidgetState(false);
            // std::cout<<"Go back clicked"<<std::endl;
        },PushButtonEvent::ON_RELEASED,"Go back"
    );
    button->bindAction(act);
    settingWidget->addChild(button);
    //音乐开关
    wt = wt->NextSiblingElement("button");
    button = makePushButton(render,wt,font);
    settingWidget->addChild(button);
    //音效开关
    wt = wt->NextSiblingElement("button");
    button = makePushButton(render,wt,font);
    settingWidget->addChild(button);
}

void  startMenuWidget::setSettingWidgetState(bool b){
    isSettingWidgetShow = b;
    return;
}

void startMenuWidget::draw(){
    this->Widget::draw();
    if(isSettingWidgetShow)
        settingWidget->draw();
    
}

void startMenuWidget::event_handle(SDL_Event*event){
    if(isSettingWidgetShow){
        settingWidget->event_handle(event);
    }
    else
        this->Widget::event_handle(event);
}

void startMenuWidget::initButtonStartGame(Action<PushButtonEvent> act){
    XMLElement *root = doc.RootElement();
    XMLElement *but = root->FirstChildElement("button");
    PushButtonPtr button=makePushButton(render,but,font);
    Action<PushButtonEvent> A(
        [=](void*)->void{
        },PushButtonEvent::ON_CLICKED
    );
    button->bindAction(A);
    button->bindAction(act);
    addChild(button);
}
