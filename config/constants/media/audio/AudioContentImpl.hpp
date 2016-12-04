class AudioContentImpl
{
public:

AudioContentImpl();
~AudioContentImpl();

void load();

const std::vector<SoundEffectProperties> & getSoundEffects();
const std::vector<MusicTrackProperties> & getMusicTracks();
const AudioPlayerProperties & getAudioPlayerProperties();

private:

void setSoundEffects();
void setMusicTracks();

std::vector<SoundEffectProperties> mSoundEffects;
std::vector<MusicTrackProperties> mMusicTracks;

AudioPlayerProperties mAudioPlayerProperties;

};
