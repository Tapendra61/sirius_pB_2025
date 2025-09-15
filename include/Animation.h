#pragma once

#include <iostream>
#include <string>

#include "raylib/raylib.h"

class Animation {
   private:
	Texture2D texture;	// The whole texture
	int sizePerSlice;	// Size of a single sprite to render
	int totalSlices;	// Total number of slices in a texture (Auto calculated
						// depending upon the size per slice)

   public:
	Animation(const std::string& texturePath, int sizePerSlice);

	~Animation();

	void Play();
};