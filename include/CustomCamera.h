#pragma once

#include "raylib/raylib.h"

class CustomCamera {
   private:
	Camera2D cam;

   public:
	CustomCamera(Vector2 cameraTarget = {0.0f, 0.0f}, Vector2 targetOffset = {0.0f, 0.0f}, float rotation = 0.0f, float zoom = 1.0f);
	Camera2D& GetCamera();
};