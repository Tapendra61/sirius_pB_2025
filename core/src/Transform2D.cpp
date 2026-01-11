#include "Transform2D.h"
#include "raylib/raymath.h"

namespace sr {
	void Transform2D::Translate(Vector2 value) {
		position = Vector2Add(position, value);
	}

	void Transform2D::Translate(float dx, float dy) {
		position.x += dx;
		position.y += dy;
	}
} // namespace sr
