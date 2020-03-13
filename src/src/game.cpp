#include "screen.h"

#include "raylib.h"

using namespace screen; 

namespace game
{
	Screens* screens;

	Music menuMusic;
	Music gameplayMusic;
	Music win;
	int timer;

	void init()
	{
		InitWindow(1280, 720, "Beat The Rhythm v0.7");
		InitAudioDevice();
#ifdef RELEASE_CONFIG
		ToggleFullscreen();
#endif // RELEASE_CONFIG
		SetTargetFPS(120);
		timer = 0;
		menuMusic = LoadMusicStream("res/assets/Audio/Menu.ogg");
		gameplayMusic = LoadMusicStream("res/assets/Audio/Gameplay-song.ogg");
		win = LoadMusicStream("res/assets/Audio/win.ogg");

		SetMusicVolume(menuMusic, 0.2);
		SetMusicVolume(gameplayMusic, 0.2);
		SetMusicVolume(win, 0.2);

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
			timer = 0;
			StopMusicStream(gameplayMusic);
			StopMusicStream(win);
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

		case screens->result:
			timer++;
			StopMusicStream(gameplayMusic);
			PlayMusicStream(win);
			UpdateMusicStream(win);
			screens->updateResult();
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

		case screens->result:
			screens->drawResult();
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

