#pragma once
#include <iostream>
#include <raylib.h>
#include "char.h"
#include "Textures.h"
#include "mainMenu.h"
using namespace std;
string correctAnswer;
string elementN;
Vector2 selectorPos2 = { 1920 / 3, 1080 / 2.7 };
Color customColor = { 148, 0, 0, 255 };
Vector2 selectorPos3 = { 1920 / 3.45, 1080 / 2.4 };
Vector2 selectorPos4 = { 1920 / 3, 1080 / 3.1 };
string text1, text2, text3;

string elementNames[20] = {
    "Hydrogen", "Oxygen", "Carbon", "Nitrogen", "Magnesium", "Sulfur", "Iron", "Aluminum", "Calcium", "Sodium",
    "Potassium", "Nickel", "Chlorine", "Titanium", "Phosphorus", "Fluorine", "Zinc", "Copper", "Lithium", "Iodine"
};
string chemicalFormulas[20] = {
    "H2", "O2", "C", "N2", "Mg", "S", "Fe", "Al", "Ca", "Na",
    "K", "Ni", "Cl2", "Ti", "P", "F2", "Zn", "Cu", "Li", "I2" };
void startGame() // start game Function
{
    {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        DrawTexture(mainBG, 0, 0, WHITE);
        DrawTextureV(Char, charPos, WHITE);

    }
}
void gameOver() // game over function
{
    DrawTexture(container, 1920 / 4.2, 1080 / 5, GRAY);
    DrawText("GAME OVER", 1920 / 4, 1080 / 5, 100, WHITE);
    DrawTexture(BackToMenu, 1920 / 2.5, 1080 / 2.8, WHITE);
    DrawTexture(exitButton, 1920 / 2.7, 1080 / 2 - 50, WHITE);
    DrawTextureV(Selector, selectorPos2, WHITE);
}
void levelUp() // level up function
{
    DrawTexture(container, 1920 / 4.2, 1080 / 5, GRAY);
    DrawText("You Have Leveled Up!", 1920 / 3.3, 1080 / 5, 70, WHITE);
    DrawText("Choose An Upgrade:", 1920 / 2.8, 1080 / 3.5, 55, WHITE);
    DrawText("1. Upgrade Player's health", 1920 / 3, 1080 / 2.3, 45, WHITE);
    DrawText("2. Upgrade Player's attack speed", 1920 / 3, 1080 / 1.95, 45, WHITE);
    DrawText("3. Upgrade Player's damage", 1920 / 3, 1080 / 1.7, 45, WHITE);
    DrawTextureV(Selector2, selectorPos3, WHITE);

}
void question(string element) // question function
{
    DrawTexture(container, 1920 / 4.2, 1080 / 5, GRAY);
    DrawText("Match The Name With The Formula Correctly", 1920 / 3.9, 1080 / 5, 40, WHITE);
    DrawText("To Obtain The Selected Upgrade", 1920 / 3, 1080 / 3.8, 40, WHITE);
    DrawTexture(buttonUnselected, 1920 / 2.6, 1080 / 3.1, WHITE);
    DrawText(text1.c_str(), 1920 / 2.1, 1080 / 2.9, 75, BLACK);
    DrawTexture(buttonUnselected, 1920 / 2.6, 1080 / 2.2, WHITE);
    DrawText(text2.c_str(), 1920 / 2.1, 1080 / 2.1, 75, BLACK);
    DrawTexture(buttonUnselected, 1920 / 2.6, 1080 / 1.7, WHITE);
    DrawText(text3.c_str(), 1920 / 2.1, 1080 / 1.63, 75, BLACK);
    DrawTextureV(Selector, selectorPos4, WHITE);
    DrawText(TextFormat("%s %s", "Element's Name: ", element.c_str()), 1920 / 2.7, 1080 / 1.4, 40, WHITE);
    ;

}
int GetRandomValueExcluding(int min, int max, int exception1, int exception2 = -10) // random values excluding
{
    int randomValue;

    do {
        randomValue = GetRandomValue(min, max);
    } while (randomValue == exception1 || randomValue == exception2);

    return randomValue;
}
void GetAnswer(int index) // answer
{
    switch (index)
    {
    case 0: correctAnswer = "H2"; break;
    case 1: correctAnswer = "O2"; break;
    case 2: correctAnswer = "C"; break;
    case 3: correctAnswer = "N2"; break;
    case 4: correctAnswer = "Mg"; break;
    case 5: correctAnswer = "S"; break;
    case 6: correctAnswer = "Fe"; break;
    case 7: correctAnswer = "Al"; break;
    case 8: correctAnswer = "Ca"; break;
    case 9: correctAnswer = "Na"; break;
    case 10: correctAnswer = "K"; break;
    case 11: correctAnswer = "Ni"; break;
    case 12: correctAnswer = "Cl2"; break;
    case 13: correctAnswer = "Ti"; break;
    case 14: correctAnswer = "P"; break;
    case 15: correctAnswer = "F2"; break;
    case 16: correctAnswer = "Zn"; break;
    case 17: correctAnswer = "Cu"; break;
    case 18: correctAnswer = "Li"; break;
    case 19: correctAnswer = "I2"; break;

    }
}

