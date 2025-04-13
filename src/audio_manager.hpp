#pragma once
#include <string>
#include <unordered_map>
#include <SDL2/SDL_mixer.h>

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    bool loadMusic(const std::string& id, const std::string& path);
    bool loadSound(const std::string& id, const std::string& path);

    void playMusic(const std::string& id, int loops = -1);
    void playSound(const std::string& id, int loops = 0);

    void stopMusic();
    void pauseMusic();
    void resumeMusic();

    void setMasterVolume(int volume); // 0-128
    void setMusicVolume(int volume);
    void setSFXVolume(int volume);

    void clear();

private:
    std::unordered_map<std::string, Mix_Music*> musics;
    std::unordered_map<std::string, Mix_Chunk*> sounds;

    int sfxVolume = MIX_MAX_VOLUME;
};
