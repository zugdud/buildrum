#define LINUX_BUILD_TARGET

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_log.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_thread.h>
#include <SDL_timer.h>

#include "types/commonTypes.hpp"

#include "types/actor_properties.hpp"
#include "types/entity_properties.hpp"
#include "types/media_properties.hpp"
#include "types/misc_properties.hpp"
#include "types/ui_properties.hpp"
#include "types/window_properties.hpp"
#include "types/world_properties.hpp"

#include "events/IEventDispatch.hpp"
#include "events/IEventManager.hpp"

#include "config/constants/menus/IMenuProperties.hpp"

#include "config/constants/entities/SurfacePropertiesImpl.hpp"
#include "config/constants/entities/BuildableObjectPropertiesImpl.hpp"

#include "config/constants/actors/CameraPropertiesImpl.hpp"
#include "config/constants/media/environment/EnvironmentMediaPropertiesImpl.hpp"
#include "config/constants/media/fonts/FontProfilesImpl.hpp"
#include "config/constants/media/audio/AudioContentImpl.hpp"
#include "config/constants/media/sprites/SpriteSheetPropertiesImpl.hpp"
#include "config/constants/media/sprites/SpritePropertiesImpl.hpp"

#include "config/constants/window/WindowPropertiesImpl.hpp"
#include "config/constants/menus/BaseMenuProperties.hpp"
#include "config/constants/menus/impl/MainMenuPropertiesImpl.hpp"
#include "config/constants/menus/impl/ActionMenuPropertiesImpl.hpp"
#include "config/constants/menus/impl/BuildMenuPropertiesImpl.hpp"
#include "config/ConfigManager.hpp"

#include "actors/player.hpp"

#include "input/InputEventObservers.hpp"
#include "input/InputMomentum.hpp"
#include "input/InputEventManager.hpp"

#include "media/fonts/FontTextures.hpp"
#include "media/fonts/FontManager.hpp"
#include "media/audio/AudioManager.hpp"

#include "media/sprites/Sprite.hpp"
#include "media/sprites/SpriteSheet.hpp"
#include "media/sprites/SpriteSheetManager.hpp"

#include "UI/elements/UIElement.hpp"
#include "UI/elements/UIButtonState.hpp"
#include "UI/elements/UIButton.hpp"
#include "UI/elements/UILabel.hpp"
#include "UI/elements/UIGridCell.hpp"
#include "UI/elements/UIMenu.hpp"
#include "UI/MenuManager.hpp"

#include "renderers/IRenderer.hpp"

#include "window/CameraObserver.hpp"

#include "window/Viewport.hpp"
#include "window/Camera.hpp"
#include "window/ViewContext.hpp"
#include "window/Window.hpp"
#include "window/WindowManager.hpp"

#include "world/entities/Entity.hpp"
#include "world/entities/Surface.hpp"
#include "world/Tile.hpp"
#include "world/World.hpp"
#include "world/generator/impl/TestWorldImpl.hpp"
#include "world/generator/GenerateWorld.hpp"
#include "world/WorldManager.hpp"

#include "renderers/MenuRenderer.hpp"
#include "renderers/WorldRenderer.hpp"
#include "renderers/MinimapRenderer.hpp"
#include "renderers/SelectedActionMenuRenderer.hpp"
#include "renderers/StatusMenuRenderer.hpp"

#include "core/scenes/IScene.hpp"
#include "core/scenes/BaseScene.hpp"
#include "core/scenes/StartSceneImpl.hpp"
#include "core/scenes/GameSceneImpl.hpp"

#include "events/handlers/HandleNewGame.hpp"
#include "events/handlers/HandleMainMenu.hpp"
#include "events/handlers/HandleExitGame.hpp"
#include "events/handlers/HandleBuildEvent.hpp"
#include "events/EventManager.hpp"

#include "core/SceneManager.hpp"
#include "core/GameInstance.hpp"
