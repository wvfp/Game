
#include <Application.hpp>
#include <Texture.hpp>
#include <Widget.hpp>
#include <iostream>
#include <PushButton.hpp>
#include <Label.hpp>
#include "../startMenuWidget/startMenuWidget.hpp"
#include "../levelSelectWidget/levelSelectWidget.hpp"
#include "../gameWidget/gameWidget.hpp"
#include <WidgetMaker.hpp>
#include "../../MusicPlayer/MusicPlayer.hpp"
class mainApplication : public Application
{
public:
    using Application::render;
    mainApplication(std::string name, SDL_Rect P_S) : Application(name, P_S)
    {
        init();
        running = true;
        W_State = STARTMENUWIDGET;
        mus.loadMusic("./res/Sounds/background_music.mp3");
        mus.play();
    }
    void draw();
    void init();
    void event_handle(SDL_Event *);
    void drawWidgets();
    void initStartMenuWidget();
    void initLevelSelectWidget();
    void initGameWidget();
    void update();
    // 当前处于的窗口的枚举
    enum WidgetState
    {
        STARTMENUWIDGET = 0,
        LEVELSELECTWIDGET = 1,
        GAMEWIDGET = 2,
    };
    // 现在是那个窗口
    WidgetState W_State;

    // 更改当前活动窗口
    void ChangeWidget(WidgetState);

private:
    std::vector<WidgetPtr> widgets;
    // 游戏是否运行
    bool running;
    MusicPlayer mus;
};
