#include "config/include.h"

AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{
    destroy();
}

bool AudioManager::init()
{
    bool success = false;

    // Initialize SDL_mixer
    if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 )
    {
        SDL_Log("SDL_mixer could not initialize!  SDL_mixer Error: %s \n", Mix_GetError() );
        success = false;
    }

    success = loadAllMedia();
    mMusicState = STOPPED;
    mAudioState = ENABLED;

    return success;
}

void AudioManager::destroy()
{
    // TODO
    // Mix_FreeChunk();
    // Mix_FreeMusic();
    // Mix_Quit();
}

void AudioManager::playSound(SoundEffectId soundEffectId)
{
    if (mAudioState == ENABLED)
    {
        Mix_PlayChannel(-1, mSoundEffectMap[soundEffectId], 0);
    }
}

void AudioManager::setActiveMusicLoop(MusicTrackId musicTrackId)
{
    if (mAudioState == ENABLED)
    {
        mMusicState = PLAYING;
        Mix_PlayMusic(mMusicTrackMap[musicTrackId], -1);
    }
}

void AudioManager::stopActiveMusic()
{
    if (mAudioState == ENABLED)
    {
        Mix_HaltMusic();
    }
}

void AudioManager::togglePausePlayMusic()
{
    if (mAudioState == ENABLED)
    {
        if ( mMusicState == PAUSED )
        {
            Mix_ResumeMusic();
            mMusicState = PLAYING;
        }
        else
        {
            Mix_PauseMusic();
        }
    }
}

bool AudioManager::loadAllMedia()
{

    bool success = false;

    success = loadMediaSoundEffect(PROJECTILE_FIRE, "files/projectile_fire.wav");
    success = loadMediaSoundEffect(PROJECTILE_HIT, "files/projectile_hit.wav");
    success = loadMediaSoundEffect(GRUNT_DESTROY, "files/grunt_destroy.wav");

    success = loadMediaMusicTrack(MUSIC_TRACK_1, "files/music_track_1.mp3");

    return success;
}


bool AudioManager::loadMediaSoundEffect(SoundEffectId soundEffectId, std::string filePath)
{
    bool success = true;

    Mix_Chunk *loadedWav = Mix_LoadWAV(filePath.c_str());

    if ( loadedWav == NULL )
    {
        SDL_Log("Failed to sound effect -- filePath: %s SDL_mixer Error: %s \n", filePath.c_str(), Mix_GetError());
        success = false;
    }
    else
    {
        // load success, map it
        mSoundEffectMap[soundEffectId] = loadedWav;
    }
    return success;
}

bool AudioManager::loadMediaMusicTrack(MusicTrackId musicTrackId, std::string filePath)
{
    bool success = true;

    Mix_Music *loadedMusic = Mix_LoadMUS(filePath.c_str());

    if ( loadedMusic == NULL )
    {
        SDL_Log("Failed to music track -- filePath: %s SDL_mixer Error: %s \n", filePath.c_str(), Mix_GetError());
        success = false;
    }
    else
    {
        // load success, map it
        mMusicTrackMap[musicTrackId] = loadedMusic;
    }
    return success;
}
