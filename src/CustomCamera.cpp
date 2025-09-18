#include "CustomCamera.h"

CustomCamera::CustomCamera(Vector2 cameraTarget, Vector2 targetOffset,
						   float rotation, float zoom)
	: cam{targetOffset, cameraTarget, rotation, zoom} {}

Camera2D& CustomCamera::GetCamera() { return cam; }