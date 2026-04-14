#pragma once
#include "Component.h"
#include "raylib.h"

namespace sr {
	// TODO: Transforms in work
	class Transform2D : public Component {
	  private:
		Vector2 position{0.0f, 0.0f};
		float rotation = 0.0f;
		Vector2 scale{1.0f, 1.0f};

	  public:
		Transform2D(Vector2 pos = {0.0f, 0.0f}, float rot = 0.0f, Vector2 scl = {1.0f, 1.0f})
			: position(pos), rotation(rot), scale(scl) {}
		inline Vector2& Position() {
			return position;
		}
		inline float& Rotation() {
			return rotation;
		}
		inline Vector2& Scale() {
			return scale;
		}
		void Translate(Vector2 value);
		void Translate(float dx, float dy);
	};
} // namespace sr