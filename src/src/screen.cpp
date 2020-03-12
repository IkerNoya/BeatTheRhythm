#include "screen.h"
#include "circle.h"
#include "raylib.h"

using namespace circle;

namespace screen
{

	const int buttonLimit = 3;
	const float initialRadius = 50.0f;
	const float middleRadius = 65.0f;
	const float MaxRadius = 100.0f;
	const int maxSize = 380;
	const float maxMultiplier = 3.0f;
	const int winningHits = 26;

	Screens* screens;

	Circle* buttons[buttonLimit];
	Circle* gameplayButton;
	Circle* gameplayPointLine;
	Circle* gameplayDinamicCircle;

	Circle* pointLine[buttonLimit];

	Circle* dinamicCircle[buttonLimit];

	Image background;
	Texture2D menuBackground;
	Texture2D gameBackground;
	Image charT;
	Image redPointCircleImage;
	Image greenPointCircleImage;
	Image yellowPointCircleImage;
	Texture2D redPointCircle;
	Texture2D greenPointCircle;
	Texture2D yellowPointCircle;
	Image redButtonImage;
	Image greenButtonImage;
	Image yellowButtonImage;
	Texture2D redButton;
	Texture2D greenButton;
	Texture2D yellowButton;
	Texture2D charTest;
	Texture2D title;
	Image iLogo;
	Texture2D imageLogo;
	Image sLabLogo;
	Texture2D summerLabLogo;

	Color MiddleCirclePlay;
	Color BackCirclePlay;
	Color centerCirclePlay;
	Color centerLinePlay;

	Color MiddleCircleInst;
	Color BackCircleInst;
	Color centerCircleInst;
	Color centerLineInst;

	Color MiddleCircleCred;
	Color BackCircleCred;
	Color centerCircleCred;
	Color centerLineCred;

	Color changeColor;

	Color fadeScreen;

	Rectangle multiplier;
	Rectangle fade;

	Sound hit;

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
		//-----------Credits--------------
		MiddleCircleCred = { 230 , 151 , 151 , 180 };
		BackCircleCred = { 140 , 17 , 17 , 80 };
		centerCircleCred = { 140 , 17 , 17 , 255 };
		centerLineCred = { 96 , 15 , 15 , 255 };
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
		UnloadTexture(imageLogo);
		UnloadTexture(summerLabLogo);
		UnloadTexture(gameBackground);
		UnloadImage(charT);
		UnloadImage(background);
		UnloadImage(sLabLogo);
		UnloadImage(iLogo);
		UnloadSound(hit);
	}

	void Screens::initData()
	{

		buttons[0] = new Circle(initialRadius, 670, 500);
		buttons[1] = new Circle(initialRadius, 353, 447);
		buttons[2] = new Circle(initialRadius, 989, 447);

		pointLine[0] = new Circle(middleRadius, 670, 500);
		pointLine[1] = new Circle(middleRadius, 353, 447);
		pointLine[2] = new Circle(middleRadius, 989, 447);

		dinamicCircle[0] = new Circle(MaxRadius, 670, 500);
		dinamicCircle[1] = new Circle(MaxRadius, 353, 447);
		dinamicCircle[2] = new Circle(MaxRadius, 989, 447);

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

		background = LoadImage("res/assets/colorBack.png");
		ImageResize(&background, 1280, 720);
		menuBackground = LoadTextureFromImage(background);
		gameBackground = LoadTextureFromImage(background);
		charT = LoadImage("res/assets/test.png");
		ImageResize(&charT, 200, 200);
		charTest = LoadTextureFromImage(charT);
		title = LoadTexture("res/assets/title.png");
		iLogo = LoadImage("res/assets/image.png");
		ImageResize(&iLogo, 324, 162);
		imageLogo = LoadTextureFromImage(iLogo);
		sLabLogo = LoadImage("res/assets/lab.png");
		ImageResize(&sLabLogo, 150, 150);
		summerLabLogo = LoadTextureFromImage(sLabLogo);

		redButtonImage = LoadImage("res/assets/buttonRedNormal.png");
		ImageResize(&redButtonImage, 268, 157);
		redButton = LoadTextureFromImage(redButtonImage);

		greenButtonImage = LoadImage("res/assets/buttongreenNormal.png");
		ImageResize(&greenButtonImage, 268, 157);
		greenButton = LoadTextureFromImage(greenButtonImage);

		yellowButtonImage = LoadImage("res/assets/buttonyellowNormal.png");
		ImageResize(&yellowButtonImage, 268, 157);
		yellowButton = LoadTextureFromImage(yellowButtonImage);

		yellowPointCircleImage = LoadImage("res/assets/pointCircleYellow.png");
		ImageResize(&yellowPointCircleImage, 278, 167);
		yellowPointCircle = LoadTextureFromImage(yellowPointCircleImage);

		redPointCircleImage = LoadImage("res/assets/pointCircleRed.png");
		ImageResize(&redPointCircleImage, 278, 167);
		redPointCircle = LoadTextureFromImage(redPointCircleImage);

		greenPointCircleImage = LoadImage("res/assets/pointCircleGreen.png");
		ImageResize(&greenPointCircleImage, 278, 167);
		greenPointCircle = LoadTextureFromImage(greenPointCircleImage);

		hit = LoadSound("res/assets/Audio/Hit.ogg");
		SetSoundVolume(hit, 0.15f);

		buttonRelease = false;
	}

	void Screens::updateMenu() 
	{
		buttonRelease = false; 
		/*fadeCounter -= 100 * GetFrameTime();
		fadeScreen = { 0, 0, 0, fadeCounter };*/
		dinamicCircle[0]->setRadius(dinamicCircle[0]->getRadius() - (50.0f*GetFrameTime()));
		dinamicCircle[1]->setRadius(dinamicCircle[1]->getRadius() - (50.0f*GetFrameTime()));
		dinamicCircle[2]->setRadius(dinamicCircle[2]->getRadius() - (50.0f*GetFrameTime()));

		if (dinamicCircle[0]->getRadius() <= initialRadius)
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

		if (IsKeyPressed(KEY_S) && (dinamicCircle[0]->getRadius() <= middleRadius && dinamicCircle[0]->getRadius() > initialRadius))
		{
			states = gameplay;
		}
		if (IsGamepadButtonReleased(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) && (dinamicCircle[0]->getRadius() <= middleRadius && dinamicCircle[0]->getRadius() > initialRadius))
		{
			states = gameplay;
		}
		if (IsKeyPressed(KEY_A) && (dinamicCircle[1]->getRadius() <= middleRadius && dinamicCircle[1]->getRadius() > initialRadius))
		{
			states = instructions;
		}
		if (IsGamepadButtonReleased(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT) && (dinamicCircle[0]->getRadius() <= middleRadius && dinamicCircle[0]->getRadius() > initialRadius))
		{
			states = instructions;
		}
		if (IsKeyPressed(KEY_D) && (dinamicCircle[1]->getRadius() <= middleRadius && dinamicCircle[1]->getRadius() > initialRadius))
		{
			states = credits;
		}
		if (IsGamepadButtonReleased(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_UP) && (dinamicCircle[2]->getRadius() <= middleRadius && dinamicCircle[2]->getRadius() > initialRadius))
		{
			states = credits;
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
		DrawTexture(imageLogo, 300, 570, WHITE);
		DrawTexture(summerLabLogo, 800, 560, WHITE);
		DrawText("Play", 630, 330, 50, YELLOW);
		DrawText("Instructions", 200, 310, 50, DARKGREEN);
		DrawText("Credits", 900, 310, 50, RED);

		//-------------------------dinamic circles-----------------------
		DrawCircleV(dinamicCircle[0]->getPos(), dinamicCircle[0]->getRadius(), BackCirclePlay);
		DrawCircleLines(dinamicCircle[0]->getX(), dinamicCircle[0]->getY(), dinamicCircle[0]->getRadius(), BLACK);

		DrawCircleV(dinamicCircle[1]->getPos(), dinamicCircle[1]->getRadius(), BackCircleInst);
		DrawCircleLines(dinamicCircle[1]->getX(), dinamicCircle[1]->getY(), dinamicCircle[1]->getRadius(), BLACK);

		DrawCircleV(dinamicCircle[2]->getPos(), dinamicCircle[2]->getRadius(), BackCircleCred);
		DrawCircleLines(dinamicCircle[2]->getX(), dinamicCircle[2]->getY(), dinamicCircle[2]->getRadius(), BLACK);

		//-------------------------middle circle--------------------------------------
		DrawCircleV(pointLine[0]->getPos(), pointLine[0]->getRadius(), MiddleCirclePlay);
		DrawCircleV(pointLine[1]->getPos(), pointLine[1]->getRadius(), MiddleCircleInst);
		DrawCircleV(pointLine[2]->getPos(), pointLine[1]->getRadius(), MiddleCircleCred);


		//-------------------------center circles------------------------------
		DrawCircleV(buttons[0]->getPos(), buttons[0]->getRadius(), centerCirclePlay);
		DrawCircleLines(buttons[0]->getX(), buttons[0]->getY(), buttons[0]->getRadius(), centerLinePlay);

		DrawCircleV(buttons[1]->getPos(), buttons[1]->getRadius(), centerCircleInst);
		DrawCircleLines(buttons[1]->getX(), buttons[1]->getY(), buttons[1]->getRadius(), centerLineInst);

		DrawCircleV(buttons[2]->getPos(), buttons[2]->getRadius(), centerCircleCred);
		DrawCircleLines(buttons[2]->getX(), buttons[2]->getY(), buttons[2]->getRadius(), centerLineCred);

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
			dinamicCircle[2]->setRadius(MaxRadius);
		}
	}
	void Screens::drawInstructions()
	{
		ClearBackground(BLACK);
		DrawTexture(menuBackground, 1, 1, WHITE);
		DrawText("Press S when the color is yellow", 300, 200, 40, YELLOW);
		DrawText("Press A when the color is green", 300, 300, 40, GREEN);
		DrawText("Press D when the color is red", 300, 400, 40, RED);
		DrawText("press ENTER to go back", 450, 600, 30, WHITE);
	}

	void Screens::updateGameplay()
	{
		if (gameplayDinamicCircle->getRadius() <= initialRadius)
		{
			if (pointGet == false)
			{
				multiplier.height = 20.0f;
				scoreMultiplier = 1;
				healthPoints--;
				winCounter++;
			}

			gameplayDinamicCircle->setRadius(MaxRadius);
			pointGet = false;
			buttonRelease = false;
			colorCounter++;
		}

		if (IsKeyPressed(KEY_S) && (gameplayDinamicCircle->getRadius() <= middleRadius + 5 && gameplayDinamicCircle->getRadius() > initialRadius) && currentColor == yellow
			|| IsKeyPressed(KEY_A) && (gameplayDinamicCircle->getRadius() <= middleRadius + 5 && gameplayDinamicCircle->getRadius() > initialRadius) && currentColor == green
			|| IsKeyPressed(KEY_D) && (gameplayDinamicCircle->getRadius() <= middleRadius + 5 && gameplayDinamicCircle->getRadius() > initialRadius) && currentColor == red)
		{
			score += 100 * scoreMultiplier;
			multiplier.height += 47.5;
			scoreMultiplier += 0.25f;
			pointGet = true;
			colorCounter++;
			winCounter++;
			PlaySound(hit);
		}

		if (IsKeyPressed(KEY_S) && (gameplayDinamicCircle->getRadius() > middleRadius)
			|| IsKeyPressed(KEY_A) && (gameplayDinamicCircle->getRadius() > middleRadius)
			|| IsKeyPressed(KEY_D) && (gameplayDinamicCircle->getRadius() > middleRadius))
		{
			multiplier.height = 20.0f;
			scoreMultiplier = 1;
			healthPoints--;
			pointGet = true;
		}

		if (currentColor == yellow && IsKeyPressed(KEY_A) || currentColor == yellow && IsKeyPressed(KEY_D)
			|| currentColor == green && IsKeyPressed(KEY_S) || currentColor == green && IsKeyPressed(KEY_D)
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
			multiplier.height += 47.5;
			scoreMultiplier += 0.25f;
			pointGet = true;
			winCounter++;
			buttonRelease = true;
			PlaySound(hit);
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
			winCounter = 0;
		}

		if (winCounter>=winningHits-1)
		{
			gameplayDinamicCircle->setRadius(gameplayDinamicCircle->getRadius() - (25.0f*GetFrameTime()));
		}
		else
		{
			gameplayDinamicCircle->setRadius(gameplayDinamicCircle->getRadius() - (55.0f*GetFrameTime()));
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

		
		if (currentColor == yellow)
		{
			DrawCircleV(gameplayDinamicCircle->getPos(), gameplayDinamicCircle->getRadius(), BackCirclePlay);
			DrawCircleLines(gameplayDinamicCircle->getPos().x, gameplayDinamicCircle->getPos().y, gameplayDinamicCircle->getRadius(), BLACK);
		}
		if (currentColor == green)
		{
			DrawCircle(gameplayDinamicCircle->getPos().x - 317, gameplayDinamicCircle->getPos().y - 53, gameplayDinamicCircle->getRadius(), BackCircleInst);
			DrawCircleLines(gameplayDinamicCircle->getPos().x - 317, gameplayDinamicCircle->getPos().y - 53, gameplayDinamicCircle->getRadius(), BLACK);
		}
		if (currentColor == red)
		{
			DrawCircle(gameplayDinamicCircle->getPos().x + 319, gameplayDinamicCircle->getPos().y - 53, gameplayDinamicCircle->getRadius(), BackCircleCred);
			DrawCircleLines(gameplayDinamicCircle->getPos().x + 319, gameplayDinamicCircle->getPos().y - 53, gameplayDinamicCircle->getRadius(), BLACK);
		}
		
		//-------------------------middle circle--------------------------------------

		DrawCircleV(gameplayPointLine->getPos(), gameplayPointLine->getRadius(), MiddleCirclePlay);

		DrawTexture(yellowPointCircle, gameplayButton->getPos().x - 138, gameplayButton->getPos().y - 88, WHITE);
		DrawCircleLines(gameplayButton->getPos().x, gameplayButton->getPos().y, gameplayPointLine->getRadius(), BLACK);

		DrawTexture(greenPointCircle, gameplayButton->getPos().x - (320 + 136), gameplayButton->getPos().y - 140, WHITE);
		DrawCircleLines(gameplayButton->getPos().x - 318, gameplayButton->getPos().y - 53, gameplayPointLine->getRadius(), BLACK);

		DrawTexture(redPointCircle, (gameplayButton->getPos().x + 320) - 140, gameplayButton->getPos().y - 140, WHITE);
		DrawCircleLines(gameplayButton->getPos().x + 318, gameplayButton->getPos().y - 53, gameplayPointLine->getRadius(), BLACK);

		//-------------------------center circles------------------------------

		DrawCircleV(gameplayButton->getPos(), gameplayButton->getRadius(), changeColor);
		DrawCircleLines(gameplayButton->getPos().x, gameplayButton->getPos().y, gameplayButton->getRadius(), centerLinePlay);

		DrawTexture(yellowButton, gameplayButton->getPos().x -133 , gameplayButton->getPos().y - 83, WHITE);
		DrawCircleLines(gameplayButton->getPos().x, gameplayButton->getPos().y, gameplayButton->getRadius()+2, BLACK);

		DrawTexture(greenButton, gameplayButton->getPos().x - (320 + 131), gameplayButton->getPos().y - 135, WHITE);
		DrawCircleLines(gameplayButton->getPos().x - 318, gameplayButton->getPos().y - 53, gameplayButton->getRadius()+2, BLACK);

		DrawTexture(redButton, (gameplayButton->getPos().x + 320) - 135, gameplayButton->getPos().y - 135, WHITE);
		DrawCircleLines(gameplayButton->getPos().x + 318, gameplayButton->getPos().y - 53, gameplayButton->getRadius()+2, BLACK);

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
		if (IsKeyPressed(KEY_ENTER))
		{
			states = menu;
			dinamicCircle[0]->setRadius(MaxRadius);
			dinamicCircle[1]->setRadius(MaxRadius);
			dinamicCircle[2]->setRadius(MaxRadius);
		}
	}
	void Screens::drawCredits()
	{
		ClearBackground(BLACK);
		DrawTexture(menuBackground, 1, 1, WHITE);
		DrawText("Game Designer           Federico Delgado", 50, 200, 30, YELLOW);
		DrawText("Game Artists            Sofia Migliavacca", 50, 300, 30, YELLOW);
		DrawText("                            Sofia Regues Garcia", 55, 350, 30, YELLOW);
		DrawText("Audio                     Leonel Suarez ", 50, 450, 30, YELLOW);
		DrawText("Programmers          Juan Simon Blanco ", 50, 550, 30, YELLOW);
		DrawText("                           Iker Arturo Noya Linares", 50, 600, 30, YELLOW);

	}

}