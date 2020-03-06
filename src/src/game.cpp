#include "screen.h"

#include "raylib.h"

using namespace screen; 

namespace game
{
	Screens* screens;

	void init()
	{
		InitWindow(1280, 720, "BeatTheRhythm v0.4");
		ToggleFullscreen();
		screens = new Screens();
		screens->initData();
		screens->states = screens->instructions;


	}

	void update()
	{
		switch (screens->states)
		{
		case screens->menu:
			screens->updateMenu();
			break;

		case screens->instructions:
			screens->updateInstructions();
			break;

		case screens->gameplay:
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

