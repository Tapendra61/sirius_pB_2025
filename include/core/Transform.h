#pragma once
#include "raylib/raylib.h"
#include "raylib/raymath.h"

// TODO: Transforms in work
class Transform2D {
   private:
	Vector2 position{0.0f, 0.0f};
	float rotation = 0.0f;
	Vector2 scale{1.0f, 1.0f};

   public:
	inline Vector2& Position() { return position; }
	inline float& Rotation() { return rotation; }
	inline Vector2 Scale() { return scale; }
	void Translate(Vector2 value);
	
};