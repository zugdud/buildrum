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


bool configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
               const AudioContentImpl & audioContentImpl);


void playSound(std::string soundEffectId);
void setMusicTrack(std::string musicTrackId);
void playMusic();
void stopMusic();
void pauseMusic();
void resumeMusic();
MusicPlayerState getMusicPlayerState();

void playStaticChannelSound(int channelId, std::string soundEffectId);
void stopStaticChannelSound(int channelId);

protected:

AudioManager();
AudioManager(const AudioManager&);
AudioManager& operator=(const AudioManager&);
~AudioManager();

private:

bool init();

bool loadSoundEffects(const std::string & soundEffectDirName, const std::vector<SoundEffectProperties> & soundEffectProperties);
bool loadMusicTracks(const std::string & musicTrackDirName, const std::vector<MusicTrackProperties> & musicTrackProperties);


EnvironmentMediaPropertiesImpl mEnvironmentMediaPropertiesImpl;
AudioPlayerProperties mAudioPlayerProperties;
AudioContentImpl mAudioContentImpl;

std::string mSelectedMusicTrackId;
MusicPlayerState mMusicPlayerState;

std::map<std::string, Mix_Chunk *> mSoundEffectMap;
std::map<std::string, Mix_Music *> mMusicTrackMap;
};
