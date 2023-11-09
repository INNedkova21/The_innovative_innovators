#include <raylib.h>
#include <iostream>
#include <cmath>
#include "Textures.h"
#include "mMenu.h"
#include "char.h"
#include <ctime>

using namespace std;

int main()
{
    Character c;
    float screenWidth = 1920;
    float screenHeight = 1080;

    clock_t start;
    float duration;
    start = clock();

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    LoadTextures();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        duration = (clock() - start) / (double)CLOCKS_PER_SEC;
        BeginDrawing();
        startGame();
        cMovement(c);
        spawnEnemy();

        if (enemyPos.x > charPos.x) enemyPos.x -= 1.5;
        else if (enemyPos.x < charPos.x) enemyPos.x += 1.5;
        if (enemyPos.y > charPos.y) enemyPos.y -= 1.5;
        else if (enemyPos.y < charPos.y) enemyPos.y += 1.5;

        DrawText(TextFormat("Survived: %.1f", duration), screenWidth / 2.28f, 30, 30, WHITE);
        EndDrawing();
    }
    CloseWindow();
}
