#pragma once
#include"raylib/raylib.h"
#include"raylib/raymath.h"

// TODO: Transforms in work
class Transform {
	private:
	Vector2 position{0.0f, 0.0f};
	float rotation = 0.0f;
	Vector2 scale{1.0f, 1.0f};
};