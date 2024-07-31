#include "gameWidget.hpp"


gameWidget::gameWidget(RendererPtr r,SDL_Rect r_t):Widget(r,r_t){
    std::string xml_path="res/xml/Widgets/gameWidget.xml";
    if(doc.LoadFile(xml_path.c_str())!=XML_SUCCESS){
        std::cerr<<"ERROR: can't load file "<<xml_path<<"\n error in gameWidget initialize"<<std::endl;
        std::abort();
    }
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
}
void gameWidget::initPushButton(){}
void gameWidget::initStopWidget(){}
void gameWidget::initStopWidgetPushButton(Action<PushButtonEvent>){}
void gameWidget::initLevel(int){}
void gameWidget::releaseLevel(){}
void gameWidget::draw(){
    // if(!isHide()){
    //     SDL_Rect preRect;
    //     if(parent){
    //         SDL_RenderGetViewport(render.get(),&preRect);
    //         SDL_Rect nowRect = getPrimaryRect();
    //         SDL_Rect edge=nowRect;
    //         edge.w=std::min(preRect.w+preRect.x,nowRect.w+nowRect.x)-nowRect.x;
    //         edge.h=std::min(preRect.h+preRect.y,nowRect.h+nowRect.y)-nowRect.y;
    //         SDL_RenderSetViewport(render.get(),&edge);
    //     }
    //     drawBase();
    //     //绘制子widget
    //     drawChild();
    //     if(parent){
    //         SDL_RenderSetViewport(render.get(),&preRect);
    //     }
    // }
    drawBase();
    for(auto i:ChildWidgetList)
        i->draw();
}
void gameWidget::event_handle(SDL_Event *event){
    for(auto i:ChildWidgetList)
        i->event_handle(event);
}