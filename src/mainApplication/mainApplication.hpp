#include <Application.hpp>
#include <Texture.hpp>
#include <Widget.hpp>
#include <iostream>
#include <PushButton.hpp>
#include <Label.hpp>
class mainApplication:public Application {
public:
    using Application::render;
    mainApplication(std::string name,SDL_Rect P_S):Application(name,P_S){
        init();
    }
    void draw();
    void init();
    void event_handle(SDL_Event *);
    void drawWidgets();

private:
    WidgetPtrList widgets;
};
