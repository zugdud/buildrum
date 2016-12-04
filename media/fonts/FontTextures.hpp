class FontTextures
{
public:

FontTextures();
~FontTextures();

void addTexture(const std::string & text, const SDL_Rect & rect, SDL_Texture *texture);

bool textureExists(const std::string & text) const;
SDL_Texture * getTexture(const std::string & text);
const SDL_Rect & getRect(const std::string & text);

private:

std::map<std::string, SDL_Rect> mRects;   // text string ->rect
std::map<std::string, SDL_Texture * > mTextures;   // text string ->texture

};
