#pragma once
#include <raylib.h>
#include <iostream>
using namespace std;


Texture2D mainBG;
Texture2D menuBackground;
Texture2D buttonUnselected;
Texture2D buttonSelected;
Texture2D Selector;
Texture2D Selector2;
Texture2D mainBG1;
Texture2D Char;
Texture2D virus1, virus2, virus3, virus4;
Texture2D gameOverBG;
Texture2D whiteBloodCell;
Texture2D buttonUnselected2;
Texture2D exitButton, startButton, optionsButton;
Texture2D container;
Texture2D optionsBackground;
Texture2D Fullscreen;
Texture2D BackToMenu;
Texture2D SourceCode;
void LoadTextures()
{
    Image BG = LoadImage("resources\\background1.png");
    Image optionsBG = LoadImage("resources\\options_background.png");
    Image containerBox = LoadImage("resources\\backgroundBox.png");
    Image buttonUn = LoadImage("resources\\buttonUnselected.png");
    Image buttonSel = LoadImage("resources\\buttonSelected.png");
    Image btnSelector = LoadImage("resources\\selector.png");
    Image BC = LoadImage("resources\\BloodCell.png");
    Image v1 = LoadImage("resources\\v1.png");
    Image v2 = LoadImage("resources\\v2.png");
    Image v3 = LoadImage("resources\\v3.png");
    Image v4 = LoadImage("resources\\v4.png");
    Image WBC = LoadImage("resources\\WhiteBloodCell.png");
    Image gameOverbg = LoadImage("resources\\gameOverMenuBG.png");
    Image btnSelector2 = LoadImage("resources\\selector.png");
    Image startBtn = LoadImage("resources\\StartButton.png");
    Image ToggleFullscreenButton = LoadImage("resources\\ToggleFullscreen Button.png");
    Image BackToMenuButton = LoadImage("resources\\BackToMenu Button.png");
    Image SourceCodeButton = LoadImage("resources\\SourceCode Button.png");
    Image optionsBtn = LoadImage("resources\\OptionsButton.png");
    Image exitBtn = LoadImage("resources\\ExitButton.png");
    Image menuBG = LoadImage("resources\\menuBackground.png");
    ImageResize(&BC, 100, 80);
    ImageResize(&v1, 70, 70);
    ImageResize(&v2, 70, 70);
    ImageResize(&v3, 70, 70);
    ImageResize(&v4, 70, 70);
    ImageResize(&startBtn, 500, 250);
    ImageResize(&optionsBtn, 500, 250);
    ImageResize(&exitBtn, 500, 250);
    ImageResize(&BG, 1920, 1080);
    ImageResize(&WBC, 50, 50);
    ImageResize(&btnSelector2, 70, 70);
    ImageResize(&ToggleFullscreenButton, 300, 150);
    ImageResize(&BackToMenuButton, 300, 150);
    ImageResize(&SourceCodeButton, 300, 150);
    // ImageResize(&buttonUn, 400, 120);
    container = LoadTextureFromImage(containerBox);
    Char = LoadTextureFromImage(BC);
    mainBG = LoadTextureFromImage(BG);
    buttonUnselected = LoadTextureFromImage(buttonUn);
    buttonSelected = LoadTextureFromImage(buttonSel);
    Selector = LoadTextureFromImage(btnSelector);
    gameOverBG = LoadTextureFromImage(gameOverbg);
    virus1 = LoadTextureFromImage(v1);
    virus2 = LoadTextureFromImage(v2);
    virus3 = LoadTextureFromImage(v3);
    virus4 = LoadTextureFromImage(v4);
    whiteBloodCell = LoadTextureFromImage(WBC);
    Selector2 = LoadTextureFromImage(btnSelector2);
    startButton = LoadTextureFromImage(startBtn);
    exitButton = LoadTextureFromImage(exitBtn);
    optionsButton = LoadTextureFromImage(optionsBtn);
    menuBackground = LoadTextureFromImage(menuBG);
    optionsBackground = LoadTextureFromImage(optionsBG);
    Fullscreen = LoadTextureFromImage(ToggleFullscreenButton);
    BackToMenu = LoadTextureFromImage(BackToMenuButton);
    SourceCode = LoadTextureFromImage(SourceCodeButton);
}

Texture2D randomEnemyTexture()
{
    int randomNum = GetRandomValue(0, 3);
    switch (randomNum)
    {
    case 0: return virus1; break;
    case 1: return virus2; break;
    case 2: return virus3; break;
    case 3: return virus4; break;
    default: return virus1; break;
    }
}