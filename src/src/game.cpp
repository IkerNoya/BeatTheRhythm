#include "player.h"
#include "circle.h"
#include "screen.h"

#include "raylib.h"

using namespace screen; 
using namespace circle;
using namespace player;

namespace game
{
	const int buttonLimit = 3;

	Screens* screens;
	Circle* buttons[buttonLimit];
	Circle* gameplayButton;
	Player* player;

	Texture menuBackground;

	void init()
	{
		InitWindow(1280, 720, "BeatTheRhythm v0.1");

		screens = new Screens();

		buttons[0] = new Circle(50, 250, 500);
		buttons[1] = new Circle(50, 640, 400);
		buttons[2] = new Circle(50, 1005, 500);

		gameplayButton = new Circle(70, 640, 360);

		menuBackground = LoadTexture("res/raw/menuPNG.png");

	}

	void update()
	{
		screens->states = screens->menu;
		switch (screens->states)
		{
		case screens->menu:
			break;
		case screens->gameplay:
			break;
		}
	}

	void draw()
	{
		switch (screens->states)
		{
		case screens->menu:

			DrawTexture(menuBackground, 1, 1, WHITE);

			DrawText("Beat The Rhythm", 300, 70, 80, DARKGREEN);
			DrawText("Play", 200, 360, 50, YELLOW);
			DrawText("Instructions", 480, 270, 50, DARKBLUE);
			DrawText("Quit", 950, 360, 50, RED);

			DrawCircleV(buttons[0]->getPos(), buttons[0]->getRadius(), YELLOW);
			DrawCircleV(buttons[1]->getPos(), buttons[1]->getRadius(), DARKBLUE);
			DrawCircleV(buttons[2]->getPos(), buttons[2]->getRadius(), RED);

			DrawText("v0.1", 1200, 680, 30, BLACK);

			break;
		case screens->gameplay:

			ClearBackground(BLACK);

			DrawCircleV(gameplayButton->getPos(), gameplayButton->getRadius(), BLUE);

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
			ClearBackground(BLACK);

			draw();
			
			EndDrawing();
		}
		deInit();
	}

}

