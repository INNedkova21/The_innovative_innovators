#pragma once
#include <raylib.h>
#include <iostream>
using namespace std;

Texture2D mainBG;

void LoadTextures()
{
    Image BG = LoadImage("resources\\background1.png");
    ImageResize(&BG, 1920, 1080);
    mainBG = LoadTextureFromImage(BG);

}