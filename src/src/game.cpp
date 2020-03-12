#include "screen.h"

#include "raylib.h"

using namespace screen; 

namespace game
{
	Screens* screens;

	Music menuMusic;
	Music gameplayMusic;

	void init()
	{
		InitWindow(1280, 720, "BeatTheRhythm v0.5");
		InitAudioDevice();
#ifdef RELEASE_CONFIG
		ToggleFullscreen();
#endif // RELEASE_CONFIG
		menuMusic = LoadMusicStream("res/assets/Audio/Menu.ogg");
		gameplayMusic = LoadMusicStream("res/assets/Audio/Gameplay-song.ogg");
		SetMusicVolume(menuMusic, 0.2);
		SetMusicVolume(gameplayMusic, 0.2);
		screens = new Screens();
		screens->initData();
		screens->states = screens->menu;
		PlayMusicStream(menuMusic);
	}

	void update()
	{
		switch (screens->states)
		{
		case screens->menu:
			StopMusicStream(gameplayMusic);
			PlayMusicStream(menuMusic);
			UpdateMusicStream(menuMusic);
			screens->updateMenu();
			break;

		case screens->instructions:
			UpdateMusicStream(menuMusic);
			screens->updateInstructions();
			break;

		case screens->credits:
			UpdateMusicStream(menuMusic);
			screens->updateCredits();
			break;

		case screens->gameplay:
			StopMusicStream(menuMusic);
			PlayMusicStream(gameplayMusic);
			UpdateMusicStream(gameplayMusic);
			screens->updateGameplay();
			break;
		}
	}

	void draw()
	{
		switch (screens->states)
		{
		case screens->menu:
			screens->drawMenu();
			break;

		case screens->instructions:
			screens->drawInstructions();
			break;

		case screens->credits:
			screens->drawCredits();
			break;

		case screens->gameplay:
			screens->drawGameplay();
			break;
		}
	}

	void deInit()
	{
		if (screens!=NULL)
		{
			delete screens;
		}
		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameplayMusic);
	}

	void executeGame()
	{
		init();
		while (!WindowShouldClose())
		{
			update();
			BeginDrawing();
			draw();
			EndDrawing();
		}
		deInit();
	}

}

