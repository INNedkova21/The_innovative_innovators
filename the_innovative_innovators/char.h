#pragma once
#include <raylib.h>
#include "mMenu.h"
#include <iostream>
using namespace std;

struct Character {
	bool isAlive = true;
	float speed = 3;
	float health = 100;
	float atkSpeed = 1.00;
	float dmg = 1.00;
	float hRegen = 0.50;
};
void cMovement(Character c)
{
	if (IsKeyDown(KEY_RIGHT) && charPos.x < 1810) charPos.x += c.speed;
	if (IsKeyDown(KEY_LEFT) && charPos.x > 105)charPos.x -= c.speed;
	if (IsKeyDown(KEY_UP) && charPos.y > 100) charPos.y -= c.speed;
	if (IsKeyDown(KEY_DOWN) && charPos.y < 975) charPos.y += c.speed;
}