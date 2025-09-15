#include "Animation.h"

Animation::Animation(const std::string& texKey, int sizePerSlice) {
	textureKey = texKey;
	this->sizePerSlice = sizePerSlice;
}

void Animation::Init() {
	texture = gAssetLoader.GetTexture(textureKey);
	totalSlices = texture.width / sizePerSlice;
	std::cout << "Texture id: " << texture.id << std::endl;
}

void Animation::Play() {
	for (int i = 0; i < totalSlices; i++) {
		float x = (static_cast<float>(i) / totalSlices) * texture.width;
		float y = 0;

		DrawTexturePro(texture,
					   {x, y, (float)sizePerSlice, (float)sizePerSlice},
					   {20, 20, 100, 100}, {0, 0}, 0.0f, WHITE);
	}
}

Animation::~Animation() { UnloadTexture(texture); }