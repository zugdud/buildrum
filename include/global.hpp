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

#include "include/constants.hpp"

#include "window/ViewportObserver.hpp"

#include "config/constants/menus/IMenuProperties.hpp"

#include "config/constants/media/environment/EnvironmentMediaPropertiesImpl.hpp"
#include "config/constants/media/fonts/FontProfilesImpl.hpp"

#include "config/constants/window/WindowPropertiesImpl.hpp"
#include "config/constants/menus/impl/MainMenuPropertiesImpl.hpp"
#include "config/ConfigManager.hpp"

#include "input/InputEventObservers.hpp"
#include "input/InputEventHandler.hpp"

#include "media/fonts/FontTextures.hpp"
#include "media/fonts/FontManager.hpp"

#include "UI/elements/UIElement.hpp"
#include "UI/elements/UIButtonState.hpp"
#include "UI/elements/UIButton.hpp"
#include "UI/elements/UILabel.hpp"
#include "UI/elements/UIGridCell.hpp"
#include "UI/elements/UIMenu.hpp"
#include "UI/MenuManager.hpp"

#include "renderers/IRenderer.hpp"

#include "window/Viewport.hpp"
#include "window/ViewContext.hpp"
#include "window/Window.hpp"
#include "window/WindowManager.hpp"

#include "renderers/MenuRenderer.hpp"

#include "core/GameInstance.hpp"
