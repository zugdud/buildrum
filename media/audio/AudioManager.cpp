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

bool AudioManager::configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
                             const AudioContentImpl & audioContentImpl)
{
    mEnvironmentMediaPropertiesImpl = environmentMediaPropertiesImpl;
    mAudioContentImpl = audioContentImpl;
    mSelectedMusicTrackId = mAudioPlayerProperties.defaultMusicTrackId;
    mMusicPlayerState = STOPPED;

    bool initResult = init();
    return initResult;
}

bool AudioManager::init()
{
    SDL_Log("----------------------------------------------------\n");
    SDL_Log("AudioManager::init starting... \n");
    bool initSuccess = true;
    // Initialize SDL_mixer
    if ( Mix_OpenAudio(mAudioContentImpl.getAudioPlayerProperties().frequency,
                       MIX_DEFAULT_FORMAT,
                       mAudioContentImpl.getAudioPlayerProperties().channels,
                       mAudioContentImpl.getAudioPlayerProperties().chunksize) < 0)
    {
        SDL_Log("AudioManager::init -- ERROR: SDL_mixer could not initialize!  SDL_mixer Error: %s \n", Mix_GetError() );
        initSuccess = false;
    }

    if (!loadSoundEffects(mEnvironmentMediaPropertiesImpl.getEnvironmentMediaProperties().soundEffectDirName, mAudioContentImpl.getSoundEffects()))
    {
        SDL_Log("AudioManager::init -- ERROR: Failed to load one or more sound effects! \n");
        initSuccess = false;
    }

    if (!loadMusicTracks(mEnvironmentMediaPropertiesImpl.getEnvironmentMediaProperties().musicTrackDirName, mAudioContentImpl.getMusicTracks()))
    {
        SDL_Log("AudioManager::init -- ERROR: Failed to load one or more music tracks! \n");
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
    SDL_Log("AudioManager::setMusicTrack -- setMusicTrack: %s \n", musicTrackId.c_str());
    mSelectedMusicTrackId = musicTrackId;
}

MusicPlayerState AudioManager::getMusicPlayerState()
{
    if (mMusicPlayerState != PAUSED)
    {
        if (Mix_PlayingMusic() == 1)
        {
            mMusicPlayerState = PLAYING;
        }
        if (Mix_PlayingMusic() == 0)
        {
            mMusicPlayerState = STOPPED;
        }
    }
    return mMusicPlayerState;
}

void AudioManager::playMusic()
{
    SDL_Log("AudioManager::playMusic -- mSelectedMusicTrackId: %s \n", mSelectedMusicTrackId.c_str());
    Mix_PlayMusic(mMusicTrackMap[mSelectedMusicTrackId], 0);
}

void AudioManager::stopMusic()
{
    Mix_HaltMusic();
}

void AudioManager::pauseMusic()
{
    Mix_PauseMusic();
    mMusicPlayerState = PAUSED;
}

void AudioManager::resumeMusic()
{
    Mix_ResumeMusic();
}

bool AudioManager::loadSoundEffects(const std::string & soundEffectDirName, const std::vector<SoundEffectProperties> & soundEffectProperties)
{
    SDL_Log("AudioManager::loadSoundEffects -- num soundTracks: %zu \n", soundEffectProperties.size());
    bool success = true;

    for (size_t i = 0; i < soundEffectProperties.size(); i++)
    {
        const std::string filePath = soundEffectDirName + soundEffectProperties[i].fileName;
        Mix_Chunk *loadedWav = Mix_LoadWAV(filePath.c_str());
        if ( loadedWav == NULL )
        {
            SDL_Log("AudioManager::loadSoundEffects -- ERROR: Failed to load soundEffectId: [%s] filePath: %s SDL_mixer Error: %s \n",
                    soundEffectProperties[i].soundEffectId.c_str(),
                    filePath.c_str(),
                    Mix_GetError());
            success = false;
        }
        else
        {
            SDL_Log("AudioManager::loadSoundEffects -- loaded soundEffectId: [%s] filePath: %s \n",
                    soundEffectProperties[i].soundEffectId.c_str(),
                    filePath.c_str());
            mSoundEffectMap[soundEffectProperties[i].soundEffectId] = loadedWav;
        }
    }

    return success;
}

bool AudioManager::loadMusicTracks(const std::string & musicTrackDirName, const std::vector<MusicTrackProperties> & musicTrackProperties)
{
    SDL_Log("AudioManager::loadMusicTracks -- num musicTracks: %zu \n", musicTrackProperties.size());
    bool success = true;

    for (size_t i = 0; i < musicTrackProperties.size(); i++)
    {
        const std::string filePath = musicTrackDirName + musicTrackProperties[i].fileName;
        Mix_Music *loadedMusic = Mix_LoadMUS(filePath.c_str());
        if ( loadedMusic == NULL )
        {
            SDL_Log("AudioManager::loadMediaMusicTrack -- ERROR: Failed to load musicTrackId: %s filePath: %s SDL_mixer Error: %s \n",
                    musicTrackProperties[i].musicTrackId.c_str(),
                    filePath.c_str(),
                    Mix_GetError());
            success = false;
        }
        else
        {
            SDL_Log("AudioManager::loadMediaMusicTrack -- loaded musicTrackId: [%s] filePath: %s \n",
                    musicTrackProperties[i].musicTrackId.c_str(),
                    filePath.c_str());
            mMusicTrackMap[musicTrackProperties[i].musicTrackId] = loadedMusic;
        }
    }

    return success;
}
