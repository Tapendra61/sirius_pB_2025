#pragma once

#include<raylib/raylib.h>

class WindowManager {
private:
	int windowWidth;
	int windowHeight;
	int fps;
	const char* windowTitle;

public:
	WindowManager(int width, int height, const char* title, int fps);
	WindowManager(WindowManager&) = delete;

	void Run();

private:
	void Start();
	void Update();
	void LateUpdate();
};