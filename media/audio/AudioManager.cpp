#include "include/global.hpp"

AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{
    // TODO
    // Mix_FreeChunk();
    // Mix_FreeMusic();
    // Mix_Quit();
}

void AudioManager::configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
                             const AudioPlayerProperties & audioPlayerProperties)
{
    mEnvironmentMediaPropertiesImpl = environmentMediaPropertiesImpl;
    mAudioPlayerProperties = audioPlayerProperties;
    mSelectedMusicTrackId = mAudioPlayerProperties.defaultMusicTrackId;
    mMusicPlayerState = STOPPED;
}

bool AudioManager::init()
{
    SDL_Log("----------------------------------------------------\n");
    SDL_Log("AudioManager::init starting... \n");
    // Initialize SDL_mixer
    bool initSuccess = Mix_OpenAudio(mAudioPlayerProperties.frequency,
                                     MIX_DEFAULT_FORMAT,
                                     mAudioPlayerProperties.channels,
                                     mAudioPlayerProperties.chunksize);

    if (initSuccess)
    {
        SDL_Log("SDL_mixer could not initialize!  SDL_mixer Error: %s \n", Mix_GetError() );
        initSuccess = false;
    }

    SDL_Log("----------------------------------------------------\n");
    return initSuccess;
}


void AudioManager::playSound(std::string soundEffectId)
{
    Mix_PlayChannel(-1, mSoundEffectMap[soundEffectId], 0);
}


void stopMusic();
void pauseMusic();

void AudioManager::setMusicTrack(std::string musicTrackId)
{
    mSelectedMusicTrackId = musicTrackId;
}

void AudioManager::playMusic()
{
    Mix_PlayMusic(mMusicTrackMap[mSelectedMusicTrackId], -1);
    mMusicPlayerState = PLAYING;
}

void AudioManager::stopMusic()
{
    Mix_HaltMusic();
    mMusicPlayerState = STOPPED;
}

void AudioManager::pauseMusic()
{
    Mix_PauseMusic();
    mMusicPlayerState = PAUSED;
}

void AudioManager::resumeMusic()
{
    Mix_ResumeMusic();
    mMusicPlayerState = PLAYING;
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
