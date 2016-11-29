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

#include "types/commonTypes.hpp"
#include "types/properties.hpp"

#include "config/containers/MenuPropertiesContainer.hpp"
#include "config/constants/menus/IMenuProperties.hpp"
#include "config/constants/gameinstance/GameInstanceProperties.hpp"
#include "config/constants/menus/impl/MainMenuPropertiesImpl.hpp"
#include "config/ConfigManager.hpp"

#include "core/window/Viewport.hpp"
#include "core/window/Window.hpp"
#include "core/window/WindowManager.hpp"

#include "input/InputEventTypeObserver.hpp"
#include "input/InputEventTypeHandler.hpp"

#include "UI/UIElement.hpp"
#include "UI/UIButtonState.hpp"
#include "UI/UIButton.hpp"
#include "UI/UILabel.hpp"
#include "UI/UIMenu.hpp"

#include "core/GameInstance.hpp"
