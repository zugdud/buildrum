class AudioContentImpl
{
public:

AudioContentImpl();
~AudioContentImpl();

void loadAll();

const std::vector<SoundEffectProperties> & getSoundEffects();
const std::vector<MusicTrackProperties> & getMusicTracks();
const AudioPlayerProperties & getAudioPlayerProperties();

private:

void addSoundEffect(const std::string & fileName);
void setSoundEffects();
void setMusicTracks();

std::vector<SoundEffectProperties> mSoundEffects;
std::vector<MusicTrackProperties> mMusicTracks;

AudioPlayerProperties mAudioPlayerProperties;

};
