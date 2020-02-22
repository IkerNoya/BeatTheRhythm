#include "raylib.h"

using namespace std;

int main()
{
	InitWindow(1280, 720, "BeatTheRhythm v0.1");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("PRUEBA", 560, 300, 50, DARKGREEN);
		EndDrawing();
	}
	return 0;
}