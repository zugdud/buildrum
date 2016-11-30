
enum SoundEffectId {
  PROJECTILE_FIRE,
  PROJECTILE_HIT,
  GRUNT_DESTROY
};

enum MusicTrackId {
  MUSIC_TRACK_1
};

enum MusicState {
  PLAYING,
  STOPPED,
  PAUSED
};

enum AudioState {
  ENABLED,
  DISABLED
};

class AudioManager
{
public:
        AudioManager();
        ~AudioManager();
        bool init();
        void destroy();

        void playSound(SoundEffectId soundEffectId);
        void setActiveMusicLoop(MusicTrackId musicTrackId);
        void stopActiveMusic();
        void togglePausePlayMusic();
private:
  bool loadMediaMusicTrack(MusicTrackId musicTrackId, std::string filePath);
  bool loadMediaSoundEffect(SoundEffectId soundEffectId, std::string filePath);
  bool loadAllMedia();

  MusicTrackId mActiveMusicTrackId;
  MusicState mMusicState;
  AudioState mAudioState;
  
  std::map<SoundEffectId, Mix_Chunk *> mSoundEffectMap;
  std::map<MusicTrackId, Mix_Music *> mMusicTrackMap;
};
