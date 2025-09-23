#pragma once
#include <raylib/raylib.h>

class Settings
{

private:
	bool showFPS = true;

public:
	inline void SetShowFPS(bool value) { showFPS = value; }
	void DrawFPSText();
};