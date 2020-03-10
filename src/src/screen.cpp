#include "screen.h"
#include "circle.h"
#include "raylib.h"

using namespace circle;

namespace screen
{

	const int buttonLimit = 2;
	const float initialRadius = 50.0f;
	const float middleRadius = 65.0f;
	const float MaxRadius = 100.0f;
	const int maxSize = 380;
	const float maxMultiplier = 3.0f;
	const int winningHits = 36;

	Screens* screens;

	Circle* buttons[buttonLimit];
	Circle* gameplayButton;
	Circle* gameplayPointLine;
	Circle* gameplayDinamicCircle;

	Circle* pointLine[buttonLimit];

	Circle* dinamicCircle[buttonLimit];

	Texture2D menuBackground;
	Texture2D gameBackground;
	Image charT;
	Texture2D charTest;
	Texture2D title;

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

	Color changeColor;

	Color fadeScreen;

	Rectangle multiplier;
	Rectangle fade;

	enum CurrentColor
	{
		red,
		yellow,
		green,
	};

	int currentColor;

	int score;
	int colorCounter;
	float scoreMultiplier;
	bool pointGet;
	int healthPoints;
	int healthUpLimit;

	int winCounter;
	int fadeCounter;

	bool buttonRelease;
	
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
		centerCircleInst = { 1 , 116 , 10 , 255 };
		centerLineInst = { 7 , 64 , 11 , 255 };
		//-----------quit--------------
		MiddleCircleQuit = { 230 , 151 , 151 , 180 };
		BackCircleQuit = { 140 , 17 , 17 , 80 };
		centerCircleQuit = { 140 , 17 , 17 , 255 };
		centerLineQuit = { 96 , 15 , 15 , 255 };
		//-----------fade---------------
		
	}


	Screens::Screens()
	{

	}

	Screens::~Screens()
	{
		for (int i = 0; i < buttonLimit; i++)
		{
			if (buttons[i] != NULL)
			{
				delete buttons[i];
			}

			if (pointLine[i] != NULL)
			{
				delete pointLine[i];
			}

			if (dinamicCircle[i] != NULL)
			{
				delete dinamicCircle[i];
			}
		}

		if (gameplayButton != NULL)
		{
			delete gameplayButton;
		}

		if (gameplayPointLine != NULL)
		{
			delete gameplayPointLine;
		}

		if (gameplayDinamicCircle != NULL)
		{
			delete gameplayDinamicCircle;
		}

		UnloadTexture(charTest);
		UnloadTexture(title);
		UnloadTexture(gameBackground);
		UnloadImage(charT);
	}

	void Screens::initData()
	{

		buttons[0] = new Circle(initialRadius, 435, 500);
		buttons[1] = new Circle(initialRadius, 800, 500);

		pointLine[0] = new Circle(middleRadius, 435, 500);
		pointLine[1] = new Circle(middleRadius, 800, 500);

		dinamicCircle[0] = new Circle(MaxRadius, 435, 500);
		dinamicCircle[1] = new Circle(MaxRadius, 800, 500);

		gameplayButton = new Circle(initialRadius, 670, 500);
		gameplayPointLine = new Circle(middleRadius, 670, 500);
		gameplayDinamicCircle = new Circle(MaxRadius, 670, 500);

		multiplier.x = 1200;
		multiplier.y = 80;
		multiplier.width = 50;
		multiplier.height = 20;

		scoreMultiplier = 1;
		pointGet = false;

		score = 0;
		createColors();
		changeColor = YELLOW;
		colorCounter = 0;
		currentColor = yellow;
		healthPoints = 10;
		healthUpLimit = 3000;
		winCounter = 0;
		fadeCounter = 255;

		fade.x = 1;
		fade.y = 1;
		fade.x = 1280;
		fade.x = 720;

		menuBackground = LoadTexture("res/assets/colorBack.jpg");
		gameBackground = LoadTexture("res/assets/gameBack.png");
		charT = LoadImage("res/assets/test.png");
		ImageResize(&charT, 200, 200);
		charTest = LoadTextureFromImage(charT);
		title = LoadTexture("res/assets/title.png");

		buttonRelease = false;
	}

	void Screens::updateMenu() 
	{
		buttonRelease = false; 
		/*fadeCounter -= 100 * GetFrameTime();
		fadeScreen = { 0, 0, 0, fadeCounter };*/
		dinamicCircle[0]->setRadius(dinamicCircle[0]->getRadius() - (50.0f*GetFrameTime()));
		dinamicCircle[1]->setRadius(dinamicCircle[1]->getRadius() - (50.0f*GetFrameTime()));

		if (dinamicCircle[0]->getRadius() <= initialRadius)
		{
			dinamicCircle[0]->setRadius(MaxRadius);
		}

		if (dinamicCircle[1]->getRadius() <= initialRadius)
		{
			dinamicCircle[1]->setRadius(MaxRadius);
		}

		if (IsKeyPressed(KEY_A) && (dinamicCircle[0]->getRadius() <= middleRadius && dinamicCircle[0]->getRadius() > initialRadius))
		{
			states = gameplay;
		}
		if (IsGamepadButtonReleased(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) && (dinamicCircle[0]->getRadius() <= middleRadius && dinamicCircle[0]->getRadius() > initialRadius))
		{
			states = gameplay;
		}
		if (IsKeyPressed(KEY_S) && (dinamicCircle[1]->getRadius() <= middleRadius && dinamicCircle[1]->getRadius() > initialRadius))
		{
			states = instructions;
		}
		if (IsGamepadButtonReleased(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT) && (dinamicCircle[0]->getRadius() <= middleRadius && dinamicCircle[0]->getRadius() > initialRadius))
		{
			states = instructions;
		}
	}
	void Screens::drawMenu()
	{
		ClearBackground(BLACK);

		Rectangle test;
		test.x = 600;
		test.y = 250;
		test.width = 80;
		test.height = 80;
		DrawTexture(menuBackground, 1, 1, WHITE);
		DrawTexture(title, 1, -25, WHITE);
		DrawTexture(charTest, 320, 80, WHITE);
		DrawText("Play", 380, 330, 50, YELLOW);
		DrawText("Instructions", 650, 330, 50, DARKGREEN);

		DrawText("Game Designer - Delgado, Federico    Game Artists - Migliavacca, Sofia       Game Programmers - Noya, Iker", 50, 630, 20, BLACK);
		DrawText("                                                   Regues Garcia, Sofia                              Blanco, Juan Simon", 190, 660, 20, BLACK);

		//-------------------------dinamic circles-----------------------
		DrawCircleV(dinamicCircle[0]->getPos(), dinamicCircle[0]->getRadius(), BackCirclePlay);
		DrawCircleLines(dinamicCircle[0]->getX(), dinamicCircle[0]->getY(), dinamicCircle[0]->getRadius(), BLACK);

		DrawCircleV(dinamicCircle[1]->getPos(), dinamicCircle[1]->getRadius(), BackCircleInst);
		DrawCircleLines(dinamicCircle[1]->getX(), dinamicCircle[1]->getY(), dinamicCircle[1]->getRadius(), BLACK);


		//-------------------------middle circle--------------------------------------
		DrawCircleV(pointLine[0]->getPos(), pointLine[0]->getRadius(), MiddleCirclePlay);
		DrawCircleV(pointLine[1]->getPos(), pointLine[1]->getRadius(), MiddleCircleInst);


		//-------------------------center circles------------------------------
		DrawCircleV(buttons[0]->getPos(), buttons[0]->getRadius(), centerCirclePlay);
		DrawCircleLines(buttons[0]->getX(), buttons[0]->getY(), buttons[0]->getRadius(), centerLinePlay);

		DrawCircleV(buttons[1]->getPos(), buttons[1]->getRadius(), centerCircleInst);
		DrawCircleLines(buttons[1]->getX(), buttons[1]->getY(), buttons[1]->getRadius(), centerLineInst);

		//DrawRectangleRec(fade, fadeScreen);

#ifdef EXTRA_INFO
		if (GetGamepadButtonPressed() != -1)
			DrawText(FormatText("DETECTED BUTTON: %i", GetGamepadButtonPressed()), 10, 430, 10, YELLOW);
		else
			DrawText("DETECTED BUTTON: NONE", 10, 430, 10, RED);

		DrawText("v0.5", 1200, 680, 30, BLACK);
#endif //EXTRA_INFO
	}

	void Screens::updateInstructions()
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			states = menu;
			dinamicCircle[0]->setRadius(MaxRadius);
			dinamicCircle[1]->setRadius(MaxRadius);
		}
	}
	void Screens::drawInstructions()
	{
		ClearBackground(BLACK);
		DrawText("Press A when the color is yellow", 300, 200, 40, YELLOW);
		DrawText("Press S when the color is green", 300, 300, 40, GREEN);
		DrawText("Press D when the color is red", 300, 400, 40, RED);
		DrawText("press ENTER to go back", 450, 600, 30, WHITE);
	}

	void Screens::updateGameplay()
	{
		gameplayDinamicCircle->setRadius(gameplayDinamicCircle->getRadius() - (50.0f*GetFrameTime()));

		if (gameplayDinamicCircle->getRadius() <= initialRadius)
		{
			if (pointGet == false)
			{
				multiplier.height = 20.0f;
				scoreMultiplier = 1;
				healthPoints--;
			}

			gameplayDinamicCircle->setRadius(MaxRadius);
			pointGet = false;
			buttonRelease = false;
		}

		if (IsKeyPressed(KEY_A) && (gameplayDinamicCircle->getRadius() <= middleRadius && gameplayDinamicCircle->getRadius() > initialRadius) && currentColor == yellow
			|| IsKeyPressed(KEY_S) && (gameplayDinamicCircle->getRadius() <= middleRadius && gameplayDinamicCircle->getRadius() > initialRadius) && currentColor == green
			|| IsKeyPressed(KEY_D) && (gameplayDinamicCircle->getRadius() <= middleRadius && gameplayDinamicCircle->getRadius() > initialRadius) && currentColor == red)
		{
			score += 100 * scoreMultiplier;
			colorCounter++;
			multiplier.height += 47.5;
			scoreMultiplier += 0.25f;
			pointGet = true;
			winCounter++;
		}

		if (IsKeyPressed(KEY_A) && (gameplayDinamicCircle->getRadius() > middleRadius)
			|| IsKeyPressed(KEY_S) && (gameplayDinamicCircle->getRadius() > middleRadius)
			|| IsKeyPressed(KEY_D) && (gameplayDinamicCircle->getRadius() > middleRadius))
		{
			multiplier.height = 20.0f;
			scoreMultiplier = 1;
			healthPoints--;
			pointGet = true;
		}

		if (currentColor == yellow && IsKeyPressed(KEY_S) || currentColor == yellow && IsKeyPressed(KEY_D)
			|| currentColor == green && IsKeyPressed(KEY_A) || currentColor == green && IsKeyPressed(KEY_D)
			|| currentColor == red && IsKeyPressed(KEY_A) || currentColor == red && IsKeyPressed(KEY_S))
		{
			multiplier.height = 20.0f;
			scoreMultiplier = 1;
			healthPoints--;
			pointGet = true;
		}

		if (IsGamepadButtonReleased(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) && (gameplayDinamicCircle->getRadius() <= middleRadius && gameplayDinamicCircle->getRadius() > initialRadius) && currentColor == yellow && buttonRelease == false
			|| (IsGamepadButtonReleased(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT) && (gameplayDinamicCircle->getRadius() <= middleRadius && gameplayDinamicCircle->getRadius() > initialRadius) && currentColor == green && buttonRelease == false
			|| (IsGamepadButtonReleased(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_UP) && (gameplayDinamicCircle->getRadius() <= middleRadius && gameplayDinamicCircle->getRadius() > initialRadius) && currentColor == red && buttonRelease == false)))
		{
			score += 100 * scoreMultiplier;
			colorCounter++;
			multiplier.height += 47.5;
			scoreMultiplier += 0.25f;
			pointGet = true;
			winCounter++;
			buttonRelease = true;
		}

		if (multiplier.height >= maxSize)
		{
			multiplier.height = 380;
		}

		if (scoreMultiplier >= maxMultiplier)
		{
			scoreMultiplier = maxMultiplier;
		}

		if (colorCounter < 4)
		{
			changeColor = YELLOW;
			currentColor = yellow;
		}
		else if (colorCounter >= 4 && colorCounter < 8)
		{
			changeColor = GREEN;
			currentColor = green;
		}
		else if (colorCounter >= 8 && colorCounter < 12)
		{
			changeColor = RED;
			currentColor = red;
		}
		if (colorCounter >= 12)
		{
			colorCounter = 0;
		}

		if (score > healthUpLimit && healthPoints < 10)
		{
			healthPoints++;
			healthUpLimit += 3000;
		}

		if (healthPoints < 0)
		{
			states = menu;
			healthPoints = 10;
			score = 0;
			colorCounter = 0;
		}

		if (winCounter >= winningHits)
		{
			states = menu;
			winCounter = 0;
			scoreMultiplier = 1.0f;
			multiplier.height = 20;
			score = 0;
			colorCounter = 0;
		}
	}
	void Screens::drawGameplay()
	{
		ClearBackground(BLACK);

		DrawTexture(gameBackground, 1, 1, WHITE);

		//-------------------------dinamic circles-----------------------------

		DrawCircleV(gameplayDinamicCircle->getPos(), gameplayDinamicCircle->getRadius(), BackCirclePlay);
		DrawCircleLines(gameplayDinamicCircle->getPos().x, gameplayDinamicCircle->getPos().y, gameplayDinamicCircle->getRadius(), BLACK);

		//-------------------------middle circle--------------------------------------

		DrawCircleV(gameplayPointLine->getPos(), gameplayPointLine->getRadius(), MiddleCirclePlay);

		//-------------------------center circles------------------------------

		DrawCircleV(gameplayButton->getPos(), gameplayButton->getRadius(), changeColor);
		DrawCircleLines(gameplayButton->getPos().x, gameplayButton->getPos().y, gameplayButton->getRadius(), centerLinePlay);


		DrawText(TextFormat("Score: %08i", score), 350, 10, 80, BLUE);


		DrawRectangleRec(multiplier, SKYBLUE);
		DrawText(TextFormat("x %02.02f", scoreMultiplier), multiplier.x - 200, 550, 50, GREEN);

		if (healthPoints > 0)
		{
			DrawText(TextFormat("HP:  %i", healthPoints), 20, 550, 50, RED);
		}
		else
		{
			DrawText("LAST CHANCE!!!", 20, 550, 55, RED);
		}


#ifdef EXTRA_INFO
		if (GetGamepadButtonPressed() != -1)
			DrawText(FormatText("DETECTED BUTTON: %i", GetGamepadButtonPressed()), 10, 430, 10, RED);
		else
			DrawText("DETECTED BUTTON: NONE", 10, 430, 10, GRAY);
		DrawText(TextFormat("winCounter: %i", winCounter), 10, 480, 20, RED);

#endif // EXTRA_INFO


	}

	void Screens::updateResult()
	{
	
	}
	void Screens::drawResult()
	{
	
	}

	void Screens::updateCredits()
	{
	
	}
	void Screens::drawCredits()
	{
	
	}

}