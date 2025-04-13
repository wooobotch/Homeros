#include "audio_manager.hpp"
#include <iostream>

AudioManager::AudioManager() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Error inicializando SDL_mixer: " << Mix_GetError() << std::endl;
    }
}

AudioManager::~AudioManager() {
    clear();
    Mix_CloseAudio();
}

bool AudioManager::loadMusic(const std::string& id, const std::string& path) {
    Mix_Music* music = Mix_LoadMUS(path.c_str());
    if (!music) {
        std::cerr << "No se pudo cargar música: " << Mix_GetError() << std::endl;
        return false;
    }
    musics[id] = music;
    return true;
}

bool AudioManager::loadSound(const std::string& id, const std::string& path) {
    Mix_Chunk* chunk = Mix_LoadWAV(path.c_str());
    if (!chunk) {
        std::cerr << "No se pudo cargar sonido: " << Mix_GetError() << std::endl;
        return false;
    }
    sounds[id] = chunk;
    return true;
}

void AudioManager::playMusic(const std::string& id, int loops) {
    auto it = musics.find(id);
    if (it != musics.end()) {
        Mix_PlayMusic(it->second, loops);
    }
}

void AudioManager::playSound(const std::string& id, int loops) {
    auto it = sounds.find(id);
    if (it != sounds.end()) {
        Mix_VolumeChunk(it->second, sfxVolume);
        Mix_PlayChannel(-1, it->second, loops);
    }
}

void AudioManager::stopMusic() {
    Mix_HaltMusic();
}

void AudioManager::pauseMusic() {
    if (Mix_PlayingMusic()) Mix_PauseMusic();
}

void AudioManager::resumeMusic() {
    if (Mix_PausedMusic()) Mix_ResumeMusic();
}

void AudioManager::setMasterVolume(int volume) {
    Mix_Volume(-1, volume);
    Mix_VolumeMusic(volume);
}

void AudioManager::setMusicVolume(int volume) {
    Mix_VolumeMusic(volume);
}

void AudioManager::setSFXVolume(int volume) {
    sfxVolume = volume;
}

void AudioManager::clear() {
    for (auto& pair : musics) Mix_FreeMusic(pair.second);
    for (auto& pair : sounds) Mix_FreeChunk(pair.second);
    musics.clear();
    sounds.clear();
}
