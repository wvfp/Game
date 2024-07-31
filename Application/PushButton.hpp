#ifndef _PUSHBUTTON_
#define _PUSHBUTTON_

#include "Widget.hpp"
#include "Texture.hpp"
#include "tools.hpp"
//响应函数类,用于PushButton类,传入bindAction()函数
template<typename EventType>
class Action{
public:
    Action(std::function<void(void*)> f,EventType t,std::string name=std::string()){
        fun = f;
        et = t;
        _name = name;
        Action_Size++;
        identify_number = Action_Size;
    }
    Action() = delete;
    Action<EventType>& operator=(const Action<EventType>& rhs){
        fun = rhs.fun;
        et  = rhs.et;
        _name = rhs._name;
        identify_number = rhs.identify_number;
        return *this;
    }
    ~Action(){};
    void operator()(void*data=nullptr){
        fun(data);
        return;
    }
    EventType getEventType(){
        return et;
    }
    void reSetFunction(std::function<void(void*)> f){
        f = fun;
    }
    void setName(std::string s){
        _name = s;
    }
private:
    EventType et;
    std::function<void(void*)> fun;
    std::string _name;
    static std::size_t Action_Size;
    unsigned int identify_number;
};

template<typename EventType>
std::size_t Action<EventType>::Action_Size = 0;


//按钮事件枚举(PushButtonEvent)
enum PushButtonEvent
{
    ON_NONE    = 0,    //Button default state
    ON_CLICKED = 1,    //Button on clicked
    ON_PRESSED = 2,    //Button on pressed
    ON_CLICKED_AND_PRESSED = 3,//Button on clicked and pressed
    ON_RELEASED = 4,   //Button on released
    ON_SELECTED = 8,   //Button on selected

};

class PushButton:public Widget{
public:
    PushButton(RendererPtr r,SDL_Rect rt={0,0,50,15});
    //按钮事件处理
    void event_handle(SDL_Event*);
    //获取当前按钮状态
    const PushButtonEvent getState()const;
    //绑定响应函数
    void bindAction(Action<PushButtonEvent>& action){
        Action_List.push_back(action);
    }
    //按钮绘制
    void draw();
    //状态更新
    void updata();
    //判断是否执行后执行响应函数
    void actAction();
    //设置图标
    void setIcon(TexturePtr);
    void setIcon(std::string);
    //设置文本
    void setText(std::string,SDL_Color={0,0,0,0xff});
    void setTextRect(const SDL_Rect&);
    //设置颜色
    void setTextColor(SDL_Color);
    void addChild(WidgetPtr)=delete;
private:
    std::vector<Action<PushButtonEvent>> Action_List;
    PushButtonEvent PBEvent;
    TexturePtr icon;
    TexturePtr text;
    SDL_Rect text_rect;
    std::string text_content;
    SDL_Color text_Color;
    static Action<PushButtonEvent> defaultAction;
    bool changed = false;
};

using PushButtonPtr = std::shared_ptr<PushButton>;

#endif
