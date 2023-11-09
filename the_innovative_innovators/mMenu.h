#pragma once
#include <iostream>
#include <raylib.h>
#include "Textures.h"

using namespace std;
Vector2 charPos = { 1920.0f / 2, 1080.0f / 2 };
Vector2 enemyPos = { 1920.0f / 5, 1080.0f / 2 };

void startGame() // Start Game Function
{
    {

        ClearBackground(LIGHTGRAY);
        DrawTexture(mainBG, 0, 0, WHITE);
        DrawCircleV(charPos, 40, BLUE);
    }
}
void spawnEnemy() // Spawn Enemy Function
{
    DrawCircleV(enemyPos, 40, RED);
}