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
	const float initialRadius = 50.0f;
	const float middleRadius = 65.0f;
	const float MaxRadius = 100.0f;

	Screens* screens;

	Circle* buttons[buttonLimit];
	Circle* gameplayButton;
	Circle* pointLine[buttonLimit];

	Circle* dinamicCircle[buttonLimit];

	Player* player;

	Texture menuBackground;

	Color MiddleCirclePlay;
	Color BackCirclePlay;
	Color centerCirclePlay;
	Color centerLinePlay;

	Color MiddleCircleInst;
	Color BackCircleInst;
	Color centerCircleInst;
	Color centerLineInst;

	Color MiddleCircleQuit;
	Color BackCircleQuit;
	Color centerCircleQuit;
	Color centerLineQuit;

	void createColors()
	{
		//---------play---------------------
		MiddleCirclePlay = { 233 , 238 , 194 , 180 };
		BackCirclePlay = { 225 , 249 , 41 , 80 };
		centerCirclePlay = { 202 , 219 , 70, 255 };
		centerLinePlay = { 105 , 117 , 20 , 255 };
		//-----------instructions------------
		MiddleCircleInst = { 131 , 184 , 136 , 180 };
		BackCircleInst = { 1 , 116 , 10 , 80 };
		centerCircleInst = { 1 , 116 , 10 , 255};
		centerLineInst = { 7 , 64 , 11 , 255 };
		//-----------quit--------------
		MiddleCircleQuit = { 230 , 151 , 151 , 180 };
		BackCircleQuit = { 140 , 17 , 17 , 80 };
		centerCircleQuit = { 140 , 17 , 17 , 255 };
		centerLineQuit = { 96 , 15 , 15 , 255 };
	}

	void init()
	{
		InitWindow(1280, 720, "BeatTheRhythm v0.1");

		screens = new Screens();
		screens->states = screens->menu;

		buttons[0] = new Circle(initialRadius, 250, 530);
		buttons[1] = new Circle(initialRadius, 640, 430);
		buttons[2] = new Circle(initialRadius, 1005, 530);

		pointLine[0] = new Circle(middleRadius, 250, 530);
		pointLine[1] = new Circle(middleRadius, 640, 430);
		pointLine[2] = new Circle(middleRadius, 1005, 530);

		dinamicCircle[0] = new Circle(MaxRadius, 250, 530);
		dinamicCircle[1] = new Circle(MaxRadius, 640, 430);
		dinamicCircle[2] = new Circle(MaxRadius, 1005, 530);

		gameplayButton = new Circle(70, 640, 360);

		createColors();

		menuBackground = LoadTexture("res/raw/menuPNG.png");

	}

	void update()
	{
		switch (screens->states)
		{
		case screens->menu:

			dinamicCircle[0]->setRadius(dinamicCircle[0]->getRadius() - (50.0f*GetFrameTime()));
			dinamicCircle[1]->setRadius(dinamicCircle[1]->getRadius() - (50.0f*GetFrameTime()));
			dinamicCircle[2]->setRadius(dinamicCircle[2]->getRadius() - (50.0f*GetFrameTime()));

			if (dinamicCircle[0]->getRadius()<=initialRadius)
			{
				dinamicCircle[0]->setRadius(MaxRadius);
			}

			if (dinamicCircle[1]->getRadius() <= initialRadius)
			{
				dinamicCircle[1]->setRadius(MaxRadius);
			}

			if (dinamicCircle[2]->getRadius() <= initialRadius)
			{
				dinamicCircle[2]->setRadius(MaxRadius);
			}

			if (IsKeyPressed(KEY_A) && (dinamicCircle[0]->getRadius() <= middleRadius && dinamicCircle[0]->getRadius() > initialRadius))
			{
				screens->states = screens->gameplay;
			}
			if (IsKeyPressed(KEY_D) && (dinamicCircle[2]->getRadius() <= middleRadius && dinamicCircle[2]->getRadius() > initialRadius))
			{
				CloseWindow();
			}
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
			ClearBackground(BLACK);

			DrawTexture(menuBackground, 1, 1, WHITE);

			DrawText("Beat The Rhythm", 300, 70, 80, DARKBLUE);
			DrawText("Play", 200, 360, 50, YELLOW);
			DrawText("Instructions", 480, 270, 50, DARKGREEN);
			DrawText("Quit", 950, 360, 50, RED);
			

			//-------------------------dinamic circles-----------------------
			DrawCircleV(dinamicCircle[0]->getPos(), dinamicCircle[0]->getRadius(), BackCirclePlay);
			DrawCircleLines(dinamicCircle[0]->getX(), dinamicCircle[0]->getY(), dinamicCircle[0]->getRadius(), BLACK);

			DrawCircleV(dinamicCircle[1]->getPos(), dinamicCircle[1]->getRadius(), BackCircleInst);
			DrawCircleLines(dinamicCircle[1]->getX(), dinamicCircle[1]->getY(), dinamicCircle[1]->getRadius(), BLACK);

			DrawCircleV(dinamicCircle[2]->getPos(), dinamicCircle[2]->getRadius(), BackCircleQuit);
			DrawCircleLines(dinamicCircle[2]->getX(), dinamicCircle[2]->getY(), dinamicCircle[2]->getRadius(), BLACK);


			//-------------------------middle circle--------------------------------------
			DrawCircleV(pointLine[0]->getPos(), pointLine[0]->getRadius(), MiddleCirclePlay);
			DrawCircleV(pointLine[1]->getPos(), pointLine[1]->getRadius(), MiddleCircleInst);
			DrawCircleV(pointLine[2]->getPos(), pointLine[2]->getRadius(), MiddleCircleQuit);
			

			//-------------------------center circles------------------------------
			DrawCircleV(buttons[0]->getPos(), buttons[0]->getRadius(), centerCirclePlay);
			DrawCircleLines(buttons[0]->getX(), buttons[0]->getY(), buttons[0]->getRadius(), centerLinePlay);
			
			DrawCircleV(buttons[1]->getPos(), buttons[1]->getRadius(), centerCircleInst);
			DrawCircleLines(buttons[1]->getX(), buttons[1]->getY(), buttons[1]->getRadius(), centerLineInst);
			
			DrawCircleV(buttons[2]->getPos(), buttons[2]->getRadius(), RED);
			DrawCircleLines(buttons[2]->getX(), buttons[2]->getY(), buttons[2]->getRadius(), centerLineQuit);


			DrawText("v0.1", 1200, 680, 30, BLACK);

			break;
		case screens->gameplay:

			ClearBackground(BLACK);

			DrawCircleV(gameplayButton->getPos(), gameplayButton->getRadius(), BLUE);

			
			DrawText("Prueba pantalla B", 550, 360, 50, GREEN);
			
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

