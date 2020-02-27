#include "player.h"
#include "screen.h"

#include "raylib.h"

using namespace screen;

namespace game
{

	Screens* screens;
	void init()
	{
		InitWindow(1920, 1080, "BeatTheRhythm v0.1");
		screens = new Screens();
	}

	void update()
	{
	/*	screens->states = screens->menu;
		switch (screens->states)
		{
		case screens->menu:
			break;
		case screens->gameplay:
			break;
		}*/
	}

	void draw()
	{
	/*	switch (screens->states)
		{
		case screens->menu:
			DrawText("PRUEBA", 940, 500, 50, MAROON);
			break;
		case screens->gameplay:
			break;
		}*/
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
			ClearBackground(BLACK);

			draw();
			
			EndDrawing();
		}
		deInit();
	}

}

