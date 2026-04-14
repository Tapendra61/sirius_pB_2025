#pragma once

#include <string>
#include <unordered_map>

#include "raylib.h"

namespace sr {

	class AssetLoader {
	  private:
		std::unordered_map<std::string, Texture2D> texture_map;

	  public:
		void LoadTex(const std::string& key, const std::string& path);
		Texture2D& GetTexture(const std::string& key);

		void UnloadAll();
		void PrintAllTextureKeys();
	};

	extern AssetLoader gAssetLoader;
} // namespace sr