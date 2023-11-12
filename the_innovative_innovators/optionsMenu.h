#pragma once
#include <iostream>
#include <raylib.h>
#include "Textures.h"
#include "tchar.h"
#include "mainMenu.h"
using namespace std;
void optionsMenu()
{
	BeginDrawing();
	ClearBackground(WHITE);
	DrawTexture(optionsBackground, 0, 0, WHITE);
	DrawTexture(Fullscreen, 820, 350, WHITE);
	DrawTexture(SourceCode, 820, 550, WHITE);
	DrawTexture(BackToMenu, 820, 750, WHITE);
	DrawTextureV(Selector, selectorPos, WHITE);
	EndDrawing();
}