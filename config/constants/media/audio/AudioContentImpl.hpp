class AudioContentImpl
{
public:

AudioContentImpl();
~AudioContentImpl();

void load();

const std::vector<std::string> & getSoundEffects();
const std::vector<std::string> & getMusicTracks();

private:

void setSoundEffects();
void setMusicTracks();

std::vector<SoundEffectProperties> mSoundEffects;
std::vector<MusicTrackProperties> mMusicTracks;



};
