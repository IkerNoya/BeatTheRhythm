#include "player.h"

#include "raylib.h"

namespace game 
{

	void init()
	{
		InitWindow(1280, 720, "BeatTheRhythm v0.1");
	}

	void update()
	{

	}

	void draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("PRUEBA", 560, 300, 50, DARKGREEN);
		EndDrawing();
	}

	void executeGame()
	{
		init();
		while (!WindowShouldClose())
		{
			update();
			draw();
		}
	}

}

