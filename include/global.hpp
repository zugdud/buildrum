#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_log.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_thread.h>
#include <SDL_timer.h>

#include "types/commonTypes.hpp"
#include "types/properties.hpp"

#include "config/containers/MenuPropertiesContainer.hpp"
#include "config/constants/menus/IMenuProperties.hpp"

#include "config/constants/media/environment/EnvironmentMediaPropertiesImpl.hpp"
#include "config/constants/media/fonts/FontProfilesImpl.hpp"

#include "config/constants/window/WindowPropertiesImpl.hpp"
#include "config/constants/menus/impl/MainMenuPropertiesImpl.hpp"
#include "config/ConfigManager.hpp"

#include "core/window/Viewport.hpp"
#include "core/window/WindowEventObserver.hpp"
#include "core/window/Window.hpp"
#include "core/window/WindowManager.hpp"

#include "input/InputEventTypeObserver.hpp"
#include "input/InputEventTypeHandler.hpp"

#include "media/fonts/FontTextures.hpp"
#include "media/fonts/FontManager.hpp"

#include "UI/elements/UIElement.hpp"
#include "UI/elements/UIButtonState.hpp"
#include "UI/elements/UIButton.hpp"
#include "UI/elements/UILabel.hpp"
#include "UI/elements/UIMenu.hpp"
#include "UI/MenuManager.hpp"

#include "renderers/MenuRenderer.hpp"

#include "core/GameInstance.hpp"
