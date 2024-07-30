#include <core/core.hpp>


class FPSControler{
public:
    FPSControler(uint16_t=30);
    //运行控制器
    uint64_t start();
    //停止
    uint64_t stop();
    //稳定FPS
    uint64_t tick();
private:
    bool isStart;
    uint16_t fps;
    uint64_t start_time;
    uint64_t stop_time;
    uint64_t last_time;
};