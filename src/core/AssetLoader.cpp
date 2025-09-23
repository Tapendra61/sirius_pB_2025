#include "core/AssetLoader.h"

void AssetLoader::LoadTex(const std::string& key, const std::string& path) {
	if (textureMap.find(key) != textureMap.end()) {
		std::cerr << "Texture already loaded with key: " << key << std::endl;
		return;
	}

	Texture2D tex = LoadTexture(path.c_str());
	if (tex.id == 0) {
		std::cerr << "Failed to load the texture from path: " << path
				  << std::endl;
		return;
	}

	textureMap[key] = tex;
	std::cout << "Loaded Texture: " << path << std::endl;
}

Texture2D& AssetLoader::GetTexture(const std::string& key) {
	auto tex = textureMap.find(key);
	
	if(tex == textureMap.end()) {
		std::cerr << "Texture of key: " << key << " not found!" << std::endl;
		static Texture2D dummy = {0};
		return dummy;
	}

	return tex->second;
}

void AssetLoader::UnloadAll() {
	for(auto& [key, tex] : textureMap) {
		UnloadTexture(tex);
	}

	textureMap.clear();
}

void AssetLoader::PrintAllTextureKeys() {
	for(auto& [key, tex] : textureMap) {
		std::cout << "Key: " << key << std::endl;
	}
}

AssetLoader gAssetLoader;