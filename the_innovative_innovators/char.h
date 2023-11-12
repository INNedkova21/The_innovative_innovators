#pragma once
#include <raylib.h>
#include <iostream>
using namespace std;

Vector2 charPos = { 1920.0f / 2, 1080.0f / 2 };
Vector2 bulletPos = { charPos.x, charPos.y };
struct Character // character
{
	float speed = 3;
	float health = 100;
	float atkSpeed = 0.8;
	float dmg = 150;
	float exp = 0;
	float baseHealth = 100;
	float baseAtkSpeed = 0.8;
	float baseDmg = 150;

};

void cMovement(Character c) // character movement
{
	if (IsKeyDown(KEY_RIGHT) && charPos.x < 1810) charPos.x += c.speed;
	if (IsKeyDown(KEY_LEFT) && charPos.x > 105)charPos.x -= c.speed;
	if (IsKeyDown(KEY_UP) && charPos.y > 100) charPos.y -= c.speed;
	if (IsKeyDown(KEY_DOWN) && charPos.y < 975) charPos.y += c.speed;
}