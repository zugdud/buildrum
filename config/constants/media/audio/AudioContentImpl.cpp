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
    audioPlayerProperties.defaultMusicTrackId = "Casual-friday_electronic-beat-music";
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
    SoundEffectProperties effect1;
    SoundEffectProperties effect2;
    SoundEffectProperties effect3;

    effect1.soundEffectId = "pop_1";
    effect1.fileName = "pop_1.wav";

    effect2.soundEffectId = "punch_1";
    effect2.fileName = "punch_1.wav";

    effect3.soundEffectId = "woosh_1";
    effect3.fileName = "woosh_1.wav";

    mSoundEffects.push_back(effect1);
    mSoundEffects.push_back(effect2);
    mSoundEffects.push_back(effect3);

}
void AudioContentImpl::setMusicTracks()
{
    MusicTrackProperties track1;
    MusicTrackProperties track2;
    MusicTrackProperties track3;
    MusicTrackProperties track4;

    track1.musicTrackId = "Electro-punk-action-background-music";
    track1.fileName = "Electro-punk-action-background-music.mp3";

    track2.musicTrackId = "Terra-incognita-instrumental-background-music";
    track2.fileName = "Terra-incognita-instrumental-background-music.mp3";

    track3.musicTrackId = "Psychedelic-trip-electronic-music-beat";
    track3.fileName = "Psychedelic-trip-electronic-music-beat.mp3";

    track4.musicTrackId = "Casual-friday_electronic-beat-music";
    track4.fileName = "Casual-friday_electronic-beat-music.mp3";

    mMusicTracks.push_back(track1);
    mMusicTracks.push_back(track2);
    mMusicTracks.push_back(track3);
    mMusicTracks.push_back(track4);
}
