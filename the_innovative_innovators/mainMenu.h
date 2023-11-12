#pragma once
#include <iostream>
#include <raylib.h>
#include "char.h"
#include "Textures.h"
Vector2 selectorPos = { 1920 / 3.15, 350 };
Texture2D currentBtn1;
Texture2D currentBtn2;
Texture2D currentBtn3;
void mainMenu()
{
    BeginDrawing();
    DrawTexture(menuBackground, 0, 0, WHITE);
    DrawText("Welcome To Cell Adventure", 1920.0f / 7.5, 100, 100, BLACK);
    DrawTexture(startButton, 1920.0f / 2.6f, 300, WHITE);
    DrawTexture(optionsButton, 1920.0f / 2.6f, 450, WHITE);
    DrawTexture(exitButton, 1920.0f / 2.6f, 600, WHITE);
    DrawTextureV(Selector, selectorPos, WHITE);
    EndDrawing();
}
