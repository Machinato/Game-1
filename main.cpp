#include "Header.h"

int main()
{

	InitWindow(1920, 1080, "StudentsVSViruses");
	SetWindowState(FLAG_VSYNC_HINT);

	Image ImageFon = LoadImage("./resources/Sprite 1/Fon/Fon1.png");
	ImageResize(&ImageFon, 1920, 1080); // можно изменить ее размеры(отмасштабировать)
	Texture textureFon = LoadTextureFromImage(ImageFon); //Загрузка текстуры

	Image Anim1 = LoadImage("./resources/Sprite 1/Student 5/Anim 1/Anim1.png");
	ImageResize(&Anim1, 750, 150); // можно изменить ее размеры(отмасштабировать)
	Texture texture = LoadTextureFromImage(Anim1); //Загрузка текстуры

	int QFrame = (texture.width / texture.height);
	float FrameWidth = (float)(texture.width / QFrame);

	float timer = 0.0f;
	int Frame = 0;
	int key1 = 0;
	int key2 = 0;
	int x, y;
	int u = 0;
	int x_draw;
	int y_draw;
	int n = 1;
	s_student* Student1 = new s_student[n];


	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(GREEN);

		int x_start = 480;
		int y_start = 375;
		timer += GetFrameTime();

		if (timer >= 0.5) {
			timer = 0;
			Frame ++;
		}
		Frame = Frame % QFrame;
		DrawTexture(textureFon, 0, 0, WHITE);
		DrawFPS(30, 30);

		if (IsKeyDown(KEY_ONE)) {
			key1 = 1; 
		}
		else if (key1 == 1 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			key2 = 1;
		}

		else if (key1 == 1 && key2 == 1){
			int mx = GetMouseX();
			int my = GetMouseY();
			x = mx;
			y = my;
			

			for (int i = 0; i < 5; i++){
				for (int j = 0; j < 9; j++) {
					if (x > x_start && x < (x_start + 160) && y > y_start && y < y_start + 135) {
						Student1[n].x = x_start;
						Student1[n].y = y_start - 75;
						Student1[n].HP = 10;
						Student1[n].price = 150;
						n++;
						break;
					}
					x_start += 160;
				}
				x_start = 480;
				y_start += 135;
			}
			key1 = 0;
			key2 = 0;
			mx = 0;
			my = 0;
		}
		DrawText(TextFormat("key1 =: %i", key1), 100, 150, 20, WHITE);
		DrawText(TextFormat("key2 =: %i", key2), 100, 200, 20, WHITE);
		DrawText(TextFormat("n =: %i", n), 100, 250, 20, WHITE);

		for (int i = 0; i < n; i++) {
			DrawTextureRec(
				texture,
				Rectangle{ FrameWidth * Frame, 0, 150, 150 },
				Vector2{ (float)Student1[i].x, (float)Student1[i].y},
				WHITE);
		}
		
		EndDrawing();
	}

	UnloadTexture(texture);

	CloseWindow();

	return 0;

}