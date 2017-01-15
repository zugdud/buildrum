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

#include <commonTypes.hpp>
#include <actor_properties.hpp>
#include <entity_properties.hpp>
#include <media_properties.hpp>
#include <misc_properties.hpp>
#include <ui_properties.hpp>
#include <window_properties.hpp>
#include <world_properties.hpp>
#include <WeightedQueue.hpp>

#include <IEventDispatch.hpp>
#include <IEventManager.hpp>
#include <IMenuProperties.hpp>
#include <SurfacePropertiesImpl.hpp>
#include <BuildableObjectPropertiesImpl.hpp>
#include <CameraPropertiesImpl.hpp>
#include <EnvironmentMediaPropertiesImpl.hpp>

#include <FontProfilesImpl.hpp>
#include <AudioContentImpl.hpp>
#include <SpriteSheetPropertiesImpl.hpp>
#include <SpritePropertiesImpl.hpp>

#include <WindowPropertiesImpl.hpp>
#include <BaseMenuProperties.hpp>
#include <MainMenuPropertiesImpl.hpp>
#include <ActionMenuPropertiesImpl.hpp>
#include <BuildMenuPropertiesImpl.hpp>
#include <ConfigManager.hpp>
#include <Player.hpp>

#include <InputEventObservers.hpp>
#include <InputMomentum.hpp>
#include <InputEventManager.hpp>

#include <FontTextures.hpp>
#include <FontManager.hpp>
#include <AudioManager.hpp>

#include <Sprite.hpp>
#include <SpriteSheet.hpp>
#include <SpriteSheetManager.hpp>

#include <UIElement.hpp>
#include <UIButtonState.hpp>
#include <UIButton.hpp>
#include <UILabel.hpp>
#include <UIGridCell.hpp>
#include <UIMenu.hpp>
#include <MenuManager.hpp>

#include <IRenderer.hpp>

#include <CameraObserver.hpp>

#include <Viewport.hpp>
#include <Camera.hpp>
#include <ViewContext.hpp>
#include <Window.hpp>
#include <WindowManager.hpp>

#include <ITimerObserver.hpp>
#include <Timer.hpp>
#include <TimerManager.hpp>

#include <Entity.hpp>
#include <Surface.hpp>
#include <BuildableObject.hpp>
#include <Tile.hpp>
#include <World.hpp>
#include <TestWorldImpl.hpp>
#include <GenerateWorld.hpp>
#include <WorldManager.hpp>

#include <Pathfinding.hpp>

#include <BaseRenderer.hpp>
#include <MenuRenderer.hpp>
#include <WorldRenderer.hpp>
#include <MinimapRenderer.hpp>
#include <SelectedActionMenuRenderer.hpp>
#include <StatusMenuRenderer.hpp>

#include <IScene.hpp>
#include <BaseScene.hpp>
#include <StartSceneImpl.hpp>
#include <GameSceneImpl.hpp>

#include <HandleNewGame.hpp>
#include <HandleMainMenu.hpp>
#include <HandleExitGame.hpp>
#include <HandleBuildEvent.hpp>
#include <HandleMoveCamera.hpp>
#include <HandleToggleBuildMenu.hpp>
#include <EventManager.hpp>

#include <SceneManager.hpp>
#include <GameInstance.hpp>
