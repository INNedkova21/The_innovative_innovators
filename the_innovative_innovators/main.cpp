#include <raylib.h>
#include <iostream>
#include <cmath>
#include "Textures.h"
#include "game.h"
#include "char.h"
#include <ctime>
#include "mainMenu.h"
#include "optionsMenu.h"
#include "enemy.h"
using namespace std;
int main()
{
    Character c;
    Enemy e;
    const int maxEnemies = 50;
    bool canShoot = false;
    bool shouldLevelUp = false;
    Enemy enemies[maxEnemies];
    float collisionTimer = 0;
    float ShootTimer = 0;
    float TimeSinceAnswer = 0;
    float timeSinceStarted = 0;
    for (int i = 0; i < maxEnemies; i++)
    {
        enemies[i].health = 0;
    }
    int spawnInterval = 1;
    int lastSpawnTime = GetTime();
    float screenWidth = 1920;
    float screenHeight = 1080;
    int gameState = 0;
    bool isInQuestion = false;
    int selectedBuff = 0;
    int selectorPosition = selectorPos.y;
    bool hasGeneratedQuestion = false;
    string element;
    bool answerIsCorrect = false;
    bool answerIsFalse = false;
    clock_t start;
    float duration = 0;
    start = clock();
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    LoadTextures();
    SetTargetFPS(60);
    for (int i = 0; i < maxEnemies; i++)
    {
        enemies[i].texture = randomEnemyTexture();
    }

    while (!WindowShouldClose())   // main game loop
    {
        switch (gameState)
        {
        case 0: mainMenu(); break;
        case 1: startGame(); break;
        case 2: optionsMenu(); break;
        }
        if (gameState == 0) // main menu loop
        {
            if (IsKeyPressed(KEY_DOWN))
            {
                if (selectorPos.y < 500)
                {
                    currentBtn1 = buttonUnselected;
                    while (selectorPos.y < 500)
                    {
                        selectorPos.y += 5;
                        mainMenu();
                    }
                }
                else if (selectorPos.y < 650) {
                    while (selectorPos.y < 650)
                    {
                        selectorPos.y += 5;
                        mainMenu();
                    }
                }
            }
            if (IsKeyPressed(KEY_UP))
            {
                if (selectorPos.y > 500)
                {
                    while (selectorPos.y > 500)
                    {
                        selectorPos.y -= 5;
                        mainMenu();
                    }
                }
                else if (selectorPos.y > 350) {
                    currentBtn2 = buttonUnselected;
                    while (selectorPos.y > 350)
                    {
                        selectorPos.y -= 5;
                        mainMenu();
                    }
                }
            }
        }