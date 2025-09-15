#include "Animation.h"

Animation::Animation(const std::string& texturePath, int sizePerSlice) {
	texture = LoadTexture(texturePath.c_str());
	if (!IsTextureValid(texture)) {
		std::cout << "Texture load failed! Possible invalid texture path!"
				  << std::endl;
	}

	this->sizePerSlice = sizePerSlice;
	totalSlices = texture.width / sizePerSlice;
}

void Animation::Play() {
	for (int i = 0; i < totalSlices; i++) {
		float x = (static_cast<float>(i) / totalSlices) * texture.width;
		float y = 0;

		DrawTexturePro(texture, {x, y, (float)sizePerSlice, (float)sizePerSlice}, {20, 20, 100, 100}, {0, 0}, 0.0f, WHITE);
	}
}

Animation::~Animation() {
	UnloadTexture(texture);
}