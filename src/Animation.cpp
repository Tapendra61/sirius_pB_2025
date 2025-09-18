#include "Animation.h"

Animation::Animation(const std::string& texKey, int sizePerSlice,
					 float animationSpeed, AnimationType type) {
	textureKey = texKey;
	this->sizePerSlice = sizePerSlice;
	speed = animationSpeed;
	animationType = type;
}

void Animation::Init() {
	texture = gAssetLoader.GetTexture(textureKey);
	totalSlices = texture.width / sizePerSlice;
	firstIndex = 0;
	currentIndex = 0;
	lastIndex = totalSlices - 1;
}

void Animation::Play() {
	// Testing for One Shot animations
	// if (IsKeyPressed(KEY_SPACE)) {
	// 	currentIndex = firstIndex;
	// 	duration = 0.0f;
	// }

	deltaTime = GetFrameTime();

	float x = ((currentIndex) % totalSlices) * sizePerSlice;
	float y = (currentIndex / totalSlices) * sizePerSlice;

	DrawTexturePro(texture, {x, y, (float)sizePerSlice, (float)sizePerSlice},
				   {30, 30, 100, 100}, {0, 0}, 0.0f, WHITE);

	if (duration > 0.0f) {
		duration -= deltaTime;
		return;
	}
	duration = speed;

	switch (animationType) {
		case REPEATING:
			currentIndex++;
			if(currentIndex > lastIndex) {
				currentIndex = firstIndex;
			}
			break;
		case ONESHOT:
			if(currentIndex < lastIndex) {
				currentIndex++;
			}
			break;
	}
}

Animation::~Animation() { UnloadTexture(texture); }