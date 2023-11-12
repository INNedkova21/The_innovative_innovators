#pragma once
#include <iostream>
#include <raylib.h>
#include "Textures.h"
#include "char.h"
using namespace std;
Vector2 enemyPos = { 1920.0f / 5, 1080.0f / 2 };

struct Enemy {
	Vector2 position = { 0,0 };
	float speed = 2;
	float health = 100;
	float baseHealth = 100;
	Texture2D texture = virus1;
};

