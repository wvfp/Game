#ifndef _MUSICPLAYER_
#define _MUSICPLAYER_
#include <SDL2/SDL_mixer.h>
#include <core/core.hpp>

class MusicPlayer{
public:
    void play();
    void pause();
    void loadMusic(std::string);
    MusicPlayer();
private:
    Mix_Music* music;
};


#endif //_MUSICPLAYER_