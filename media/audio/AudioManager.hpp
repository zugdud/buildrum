enum MusicPlayerState
{
    PLAYING,
    STOPPED,
    PAUSED
};

class AudioManager
{
public:

static AudioManager& Instance()
{
    static AudioManager instance;

    return instance;
}


bool configure();

void playSound(std::string soundEffectId);
void setMusicTrack(std::string musicTrackId);
void playMusic();
void stopMusic();
void pauseMusic();

protected:

AudioManager();
AudioManager(const AudioManager&);
AudioManager& operator=(const AudioManager&);
~AudioManager();

private:

bool loadMediaMusicTrack(SoundEffectProperties soundEffectProperties);
bool loadMediaSoundEffect(MusicTrackProperties musicTrackProperties);
bool loadAllMedia();

EnvironmentMediaPropertiesImpl mEnvironmentMediaPropertiesImpl;
AudioPlayerProperties mAudioPlayerProperties;
AudioContentImpl mAudioContentImpl;

std::string mSelectedMusicTrackId;
MusicPlayerState mMusicPlayerState;

std::map<SoundEffectId, Mix_Chunk *> mSoundEffectMap;
std::map<MusicTrackId, Mix_Music *> mMusicTrackMap;
};
