/*
	@file WindowManager.h
	@author Tapendra Shahi
	@date 2025-07-31
	@brief Defines window management functions for Raylib Window
*/

#pragma once

#include<raylib/raylib.h>
#include<print>
#include<SceneManager.h>

class WindowManager {
private:
	int windowWidth;
	int windowHeight;
	int fps;
	const char* windowTitle;
	SceneManager& sceneManager;

public:
	WindowManager(int width, int height, const char* title, int fps);
	WindowManager(WindowManager&) = delete;

	void Run();

private:
	void Start();
	void Update();
	void LateUpdate();
};