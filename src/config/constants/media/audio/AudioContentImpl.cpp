#include "include/global.hpp"

AudioContentImpl::AudioContentImpl()
{

}

AudioContentImpl::~AudioContentImpl()
{

}

void AudioContentImpl::loadAll()
{
    SDL_Log("AudioContentImpl::loadAll -- loading configuration ...\n");

    AudioPlayerProperties audioPlayerProperties;

    audioPlayerProperties.frequency = 44100;
    audioPlayerProperties.channels = 2;
    audioPlayerProperties.chunksize = 2048;
    audioPlayerProperties.defaultMusicTrackId = "MainMenu";
    mAudioPlayerProperties = audioPlayerProperties;

    setSoundEffects();
    setMusicTracks();
}

const AudioPlayerProperties & AudioContentImpl::getAudioPlayerProperties()
{
    return mAudioPlayerProperties;
}

const std::vector<SoundEffectProperties> & AudioContentImpl::getSoundEffects()
{
    return mSoundEffects;
}
const std::vector<MusicTrackProperties> & AudioContentImpl::getMusicTracks()
{
    return mMusicTracks;
}

void AudioContentImpl::setSoundEffects()
{
    addSoundEffect("pop_1.wav");
    addSoundEffect("punch_1.wav");
    addSoundEffect("woosh_1.wav");
    addSoundEffect("building_1.wav");
    addSoundEffect("build_complete_1.wav");
}

void AudioContentImpl::addSoundEffect(const std::string & fileName)
{
    // trim .wav for the id string
    const std::string soundEffectId = fileName.substr(0, fileName.length() - 4);

    SoundEffectProperties effect;

    effect.soundEffectId = soundEffectId;
    effect.fileName = fileName;
    mSoundEffects.push_back(effect);
}

void AudioContentImpl::setMusicTracks()
{
    MusicTrackProperties track1;
    MusicTrackProperties track2;
    MusicTrackProperties track3;
    MusicTrackProperties track4;

    track1.musicTrackId = "GameScene1";
    track1.fileName = "Electro-punk-action-background-music.mp3";

    track2.musicTrackId = "GameScene2";
    track2.fileName = "Terra-incognita-instrumental-background-music.mp3";

    track3.musicTrackId = "GameScene3";
    track3.fileName = "Psychedelic-trip-electronic-music-beat.mp3";

    track4.musicTrackId = "MainMenu";
    track4.fileName = "Casual-friday_electronic-beat-music.mp3";

    mMusicTracks.push_back(track1);
    mMusicTracks.push_back(track2);
    mMusicTracks.push_back(track3);
    mMusicTracks.push_back(track4);
}
