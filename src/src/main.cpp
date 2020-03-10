#include "game.h"

int main()
{
	game::executeGame();
	return 0;
}
//#include "raylib.h"
//int main()
//{
//	InitWindow(1920, 1080, "Prueba ANIM");
//	Image A = LoadImage("res/assets/backAnim.png");
//	ImageResize(&A, 2000, 200);
//	Texture2D B = LoadTextureFromImage(A);
//	Vector2 pos = { 0, 50 };
//	Rectangle rec = { 10, 0, B.width / 6, B.height };
//	int timerA = 0;
//	int timerB = 0;
//	int frameSpeed = 8;
//	SetTargetFPS(60);
//	while (!WindowShouldClose())
//	{
//		timerA++;
//		if (timerA >= (60 / 8))
//		{
//			timerA = 0;
//			timerB++;
//
//			rec.x += static_cast<float>(timerB * rec.width/6);
//		}
//		BeginDrawing();
//		ClearBackground(RAYWHITE);
//		DrawTextureRec(B, rec, pos, WHITE);
//		EndDrawing();
//	}
//	UnloadTexture(B);
//	UnloadImage(A);
//	return 0;
//}