#include "Animation.h"

namespace Sirius {
	Animation::Animation(const std::string& texKey, int sizePerSlice, float animationSpeed, AnimationType type,
						 Vector2& drawDestination, Vector2& drawSize)
		: texture(gAssetLoader.GetTexture(texKey)), textureKey(texKey), sizePerSlice(sizePerSlice),
		  speed(animationSpeed), animationType(type), drawDestination(drawDestination), drawSize(drawSize) {}

	void Animation::Init() {
		totalSlices = texture.width / sizePerSlice;
		firstIndex = 0;
		currentIndex = 0;
		lastIndex = totalSlices - 1;
		duration = speed;
	}

	void Animation::Play(bool flipped) {
		// Testing for One Shot animations
		if (IsKeyPressed(KEY_SPACE)) {
			currentIndex = firstIndex;
			duration = 0.0f;
		}

		deltaTime = GetFrameTime();

		float x = ((currentIndex) % totalSlices) * sizePerSlice;
		float y = (currentIndex / totalSlices) * sizePerSlice;

		Rectangle src{x, y, (float) sizePerSlice, (float) sizePerSlice};
		Rectangle dest{drawDestination.x, drawDestination.y, sizePerSlice * drawSize.x, sizePerSlice * drawSize.y};

		if (flipped) {
			src.width = -src.width;
		}

		DrawTexturePro(texture, src, dest, {dest.width / 2.0f, dest.height / 2.0f}, 0.0f, WHITE);

		if (duration > 0.0f) {
			duration -= deltaTime;
			return;
		}
		duration = speed;

		switch (animationType) {
		case REPEATING:
			currentIndex++;
			if (currentIndex > lastIndex) {
				currentIndex = firstIndex;
			}
			break;
		case ONESHOT:
			if (currentIndex < lastIndex) {
				currentIndex++;
			} else if (!completed) {
				completed = true;
				if (onCompleteCallback) {
					onCompleteCallback();
				}
			}
			break;
		}
	}

	void Animation::SetOnComplete(std::function<void()> callback) {
		onCompleteCallback = std::move(callback);
	}

	void Animation::Reset() {
		currentIndex = firstIndex;
		duration = 0.0f;
		completed = false;
	}
} // namespace Sirius