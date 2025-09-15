#pragma once

#include <iostream>
#include <string>

#include "raylib/raylib.h"
#include"AssetLoader.h"

class Animation {
   private:
   std::string textureKey;
	Texture2D texture;	// The whole texture
	int sizePerSlice;	// Size of a single sprite to render
	int totalSlices;	// Total number of slices in a texture (Auto calculated
						// depending upon the size per slice)

   public:
	Animation( const std::string& texKey, int sizePerSlice);

	~Animation();

	void Init();
	void Play();
};