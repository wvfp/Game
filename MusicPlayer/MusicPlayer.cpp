#include "MusicPlayer.hpp"
void MusicPlayer::play(){
    if(music==nullptr){
        std::cout<<"music do't be load"<<std::endl;
        return;
    }

    // 如果没有音乐在播放
    if (Mix_PlayingMusic() == 0)
    {
        // 播放音乐
        Mix_PlayMusic(music, -1);
    }    // 如果音乐已进入播放状态
    else
    {
        // 如果音乐被暂停了
        if (Mix_PausedMusic() == 1)
        {
            // 恢复播放
            Mix_ResumeMusic();
        }
    }
}

void MusicPlayer::pause(){
    if(Mix_PlayingMusic()==1)
        Mix_PauseMusic();
}

void MusicPlayer::loadMusic(std::string path){
    music = Mix_LoadMUS(path.c_str());
    return;
}

MusicPlayer::MusicPlayer(){
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
}