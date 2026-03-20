#pragma once

#include <functional>
#include <string>

#include "Component.h"
#include "raylib/raylib.h"

namespace sr {
	enum AnimationType {
		REPEATING = 0,
		ONESHOT = 1,
	};

	class Animation : public Component {
	  private:
		std::string textureKey;
		Texture2D& texture; // The whole texture
		int sizePerSlice;	// Size of a single sprite to render
		int totalSlices;	// Total number of slices in a texture (Auto calculated
							// depending upon the size per slice)
		int currentIndex;	// The index of current frame beging rendered
		int firstIndex;		// The index of first frame in the sprite
		int lastIndex;		// The index of last frame in the sprite
		float deltaTime;	// The time between current and last frame (get through
							// raylib)
		float speed;		// The speed at which the animation plays
		float duration;		// Time remaining to play the next frame
		AnimationType animationType;
		bool completed = false;
		std::function<void()> onCompleteCallback;

		Vector2& drawDestination;
		Vector2& drawSize;

	  public:
		Animation(const std::string& texKey, int sizePerSlice, float animationSpeed, AnimationType type,
				  Vector2& drawDestination, Vector2& drawSize);

		void Init();
		inline bool IsCompleted() {
			return completed;
		}
		void Play(bool flipped);
		void SetOnComplete(std::function<void()> callback);
		void Reset();
	};
} // namespace sr