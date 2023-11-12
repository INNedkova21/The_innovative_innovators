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
        if (gameState == 1) // game loop
        {
            timeSinceStarted += GetFrameTime();
            if (c.health == 0 && gameState == 1)
            {
                gameOver();
                if (IsKeyPressed(KEY_DOWN))
                {
                    while (selectorPos2.y < (1080.0f / 2))
                    {
                        selectorPos2.y += 0.5;
                        gameOver();
                    }
                }
                if (IsKeyPressed(KEY_UP))
                {
                    while (selectorPos2.y > (1080.0f / 2.7))
                    {
                        selectorPos2.y -= 0.5;
                        gameOver();
                    }
                }
                if (IsKeyPressed(KEY_ENTER))
                {
                    if (selectorPos2.y == (1080.0f / 2.7))
                    {
                        c.health = 100;
                        c.exp = 0;
                        c.baseDmg = 150;
                        c.dmg = 150;
                        c.atkSpeed = 0.8;
                        c.baseAtkSpeed = 0.8;
                        gameState = 0;
                        enemies->baseHealth = 100;
                        enemies->speed = 1;
                        for (int i = 0; i < maxEnemies; i++) enemies[i].health = 0;
                        charPos = { 1920.0f / 2, 1080.0f / 2 };
                    }
                    if (selectorPos2.y == (1080.0f / 2)) break;
                }
            }
            collisionTimer += GetFrameTime();
            ShootTimer += GetFrameTime();
            if (c.health != 0 && !shouldLevelUp && !isInQuestion)
            {
                duration = (clock() - start) / (double)CLOCKS_PER_SEC;
                cMovement(c);
                if (GetTime() - lastSpawnTime >= spawnInterval)
                {
                    for (int i = 0; i < maxEnemies; i++)
                    {
                        if (enemies[i].health == 0)
                        {
                            enemies[i].position.x = roundf(GetRandomValue((float)200, (float)1750));
                            enemies[i].position.y = roundf(GetRandomValue((float)120, (float)960));
                            enemies[i].speed = 1.5;
                            enemies[i].health = enemies->baseHealth;
                            lastSpawnTime = GetTime();
                            break;
                        }
                    }
                }
                for (int i = 0; i < maxEnemies; i++) {
                    if (enemies[i].health > 0) {

                        DrawTextureV(enemies[i].texture, enemies[i].position, WHITE);
                    }
                }
                int closestEnemyIndex = 0;
                float closestEnemyDistance = 1920;
                float bulletDistance = 0;
                for (int i = 0; i < maxEnemies; i++) { // find closest enemy loop
                    if (enemies[i].health > 0) {
                        float distance = sqrt(pow(enemies[i].position.x - charPos.x, 2) + pow(enemies[i].position.y - charPos.y, 2));
                        bulletDistance = sqrt(pow(enemies[i].position.x - bulletPos.x, 2) + pow(enemies[i].position.y - bulletPos.y, 2));
                        if (distance <= closestEnemyDistance) {
                            closestEnemyIndex = i;
                            closestEnemyDistance = distance;
                        }
                    }
                }
                if (closestEnemyIndex != -1 && ShootTimer >= c.atkSpeed) // shooting
                {
                    if (bulletDistance >= 0)
                    {
                        Rectangle bullet = { bulletPos.x, bulletPos.y, 10, 10 };
                        Rectangle closestEnemy = { enemies[closestEnemyIndex].position.x, enemies[closestEnemyIndex].position.y, 50, 50 };
                        if (bulletPos.x > enemies[closestEnemyIndex].position.x) bulletPos.x = roundf(bulletPos.x - 5);
                        else if (bulletPos.x < enemies[closestEnemyIndex].position.x) bulletPos.x = roundf(bulletPos.x + 5);
                        if (bulletPos.y > enemies[closestEnemyIndex].position.y) bulletPos.y = roundf(bulletPos.y - 5);
                        else if (bulletPos.y < enemies[closestEnemyIndex].position.y) bulletPos.y = roundf(bulletPos.y + 5);
                        if (CheckCollisionRecs(bullet, closestEnemy)) {
                            ShootTimer = 0;
                            bulletPos.x = charPos.x;
                            bulletPos.y = charPos.y;
                            bulletPos.x = roundf(bulletPos.x);
                            bulletPos.y = roundf(bulletPos.y);
                            enemies[closestEnemyIndex].health -= c.dmg;
                            c.exp += 10;
                            canShoot = false;
                        }
                        if (!CheckCollisionRecs(bullet, closestEnemy))
                        {
                            if (!canShoot) bulletPos = charPos;
                            DrawTextureV(whiteBloodCell, bulletPos, RAYWHITE);
                            canShoot = true;
                        }
                    }
                }
                for (int i = 0; i < maxEnemies; i++)
                {
                    if (enemies[i].position.x > charPos.x) enemies[i].position.x = roundf(enemies[i].position.x - enemies[i].speed);

                    else if (enemies[i].position.x < charPos.x) enemies[i].position.x = roundf(enemies[i].position.x + enemies[i].speed);
                    if (enemies[i].position.y > charPos.y) enemies[i].position.y = roundf(enemies[i].position.y - enemies[i].speed);
                    else if (enemies[i].position.y < charPos.y) enemies[i].position.y = roundf(enemies[i].position.y + enemies[i].speed);
                }
                for (int i = 0; i < maxEnemies; i++)
                {
                    for (int j = i + 1; j < maxEnemies; j++)
                    {
                        Rectangle enemy1 = { enemies[i].position.x, enemies[i].position.y, 50,50 };
                        Rectangle enemy2 = { enemies[j].position.x, enemies[j].position.y, 50, 50 };
                        Rectangle player = { charPos.x, charPos.y, 70, 70 };
                        if (CheckCollisionRecs(enemy1, enemy2))
                        {

                            float dx = enemies[i].position.x - enemies[j].position.x;
                            float dy = enemies[i].position.y - enemies[j].position.y;
                            float length = sqrt(dx * dx + dy * dy);
                            dx /= length;
                            dy /= length;
                            enemies[i].position.x += dx * 0.49f;
                            enemies[i].position.y += dy * 0.49f;
                            enemies[j].position.x -= dx * 0.49f;
                            enemies[j].position.y -= dy * 0.49f;
                        }
                        if (CheckCollisionRecs(player, enemy1) && collisionTimer >= 1.5)
                        {
                            c.health -= 10;
                            collisionTimer = 0;
                        }
                    }
                }
            }
            if (c.exp >= 100) //level up
            {
                c.exp = 0;
                shouldLevelUp = true;
            }
            if (shouldLevelUp)  // buff select
            {
                levelUp();
                if (IsKeyPressed(KEY_DOWN)) {
                    if (selectorPos3.y < 535) while (selectorPos3.y < 535) selectorPos3.y += 0.5;
                    else if (selectorPos3.y < 620) while (selectorPos3.y < 620) selectorPos3.y += 0.5;
                }
                if (IsKeyPressed(KEY_UP)) {
                    if (selectorPos3.y > 535) while (selectorPos3.y > 535) selectorPos3.y -= 0.5;
                    else if (selectorPos3.y > 450) while (selectorPos3.y > 450) selectorPos3.y -= 0.5;
                }
                if (IsKeyPressed(KEY_ENTER))
                {
                    if (selectorPos3.y == 450)
                    {
                        selectedBuff = 1;
                        shouldLevelUp = false;
                        isInQuestion = true;
                    }
                    if (selectorPos3.y == 535)
                    {
                        selectedBuff = 2;
                        shouldLevelUp = false;
                        isInQuestion = true;
                    }
                    if (selectorPos3.y == 620)
                    {
                        selectedBuff = 3;
                        shouldLevelUp = false;
                        isInQuestion = true;
                    }
                }
            }
            if (!hasGeneratedQuestion) // generate a question
            {
                int random = GetRandomValue(0, 19);
                int correctAnswerIndex = 0;
                element = elementNames[random];
                GetAnswer(random);
                for (int i = 0; i < 20; i++)
                {
                    if (correctAnswer == chemicalFormulas[i]) correctAnswerIndex = i;
                }
                int randomCorrectButton = GetRandomValue(1, 3);
                int randomAnswer1 = GetRandomValueExcluding(0, 19, correctAnswerIndex);
                int randomAnswer2 = GetRandomValueExcluding(0, 19, correctAnswerIndex, randomAnswer1);
                switch (randomCorrectButton)
                {
                case 1: text1 = correctAnswer; text2 = chemicalFormulas[randomAnswer1]; text3 = chemicalFormulas[randomAnswer2]; break;
                case 2: text2 = correctAnswer; text1 = chemicalFormulas[randomAnswer1]; text3 = chemicalFormulas[randomAnswer2]; break;
                case 3: text3 = correctAnswer; text1 = chemicalFormulas[randomAnswer1]; text2 = chemicalFormulas[randomAnswer2]; break;
                }
                hasGeneratedQuestion = true;
            }
            if (isInQuestion) // level up question
            {
                question(element);
                if (IsKeyPressed(KEY_DOWN)) {
                    if (selectorPos4.y < 491) while (selectorPos4.y < 491) selectorPos4.y += 0.5;
                    else if (selectorPos4.y < 635) while (selectorPos4.y < 635) selectorPos4.y += 0.5;
                }
                if (IsKeyPressed(KEY_UP)) {
                    if (selectorPos4.y > 491) while (selectorPos4.y > 491) selectorPos4.y -= 0.5;
                    else if (selectorPos4.y > 350) while (selectorPos4.y > 350) selectorPos4.y -= 0.5;
                }
                if (IsKeyPressed(KEY_SPACE))
                {
                    if (selectorPos4.y < 349)
                    {
                        hasGeneratedQuestion = false;
                        if (correctAnswer == text1)
                        {
                            answerIsCorrect = true;
                            isInQuestion = false;
                        }
                        else {
                            answerIsFalse = true;
                            isInQuestion = false;
                        }
                    }
                    else if (selectorPos4.y < 492)
                    {
                        hasGeneratedQuestion = false;
                        if (correctAnswer == text2)
                        {
                            answerIsCorrect = true;
                            isInQuestion = false;
                        }
                        else
                        {
                            answerIsFalse = true;
                            isInQuestion = false;
                        }
                    }
                    else if (selectorPos4.y < 636)
                    {
                        hasGeneratedQuestion = false;
                        if (correctAnswer == text3)
                        {
                            answerIsCorrect = true;
                            isInQuestion = false;
                        }
                        else
                        {
                            answerIsFalse = true;
                            isInQuestion = false;
                        }
                    }
                }
            }
            if (answerIsCorrect && !isInQuestion)    // correctly answered question
            {
                switch (selectedBuff)
                {
                case 1: c.baseHealth += 10; c.health = c.baseHealth; break;
                case 2: c.baseAtkSpeed += 0.1; c.atkSpeed = c.baseAtkSpeed; break;
                case 3: c.baseDmg += 25; c.dmg = c.baseDmg; break;
                }
                answerIsCorrect = false;
            }
            if (timeSinceStarted >= 60)
            {
                enemies->baseHealth += 10;
                enemies->speed += 0.1;
                timeSinceStarted = 0;
            }

            DrawText(TextFormat("Survived: %.1fs", duration), screenWidth / 2.28f, 30, 30, WHITE);
            DrawText(TextFormat("Health: %.0f", c.health), screenWidth / 8, 30, 30, WHITE);
            DrawText(TextFormat("EXP: %.0f/100", c.exp), screenWidth / 4, 30, 30, WHITE);
            EndDrawing();
        }