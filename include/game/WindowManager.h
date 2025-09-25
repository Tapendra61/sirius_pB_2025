/*
	@file WindowManager.h
	@author Tapendra Shahi
	@date 2025-07-31
	@brief Defines window management functions for Raylib Window
*/

#pragma once

#include <game/SceneManager.h>
#include <raylib/raylib.h>

#include <iostream>

#include "CustomCamera.h"
#include "Player.h"
#include "Settings.h"

class WindowManager {
   private:
	int windowWidth;
	int windowHeight;
	int fps;
	const char* windowTitle;

	// Dependenceis
	SceneManager& sceneManager;
	Settings settings;

	// Camera
	CustomCamera customCamera;

	// Player in game
	std::unique_ptr<Player> player;

   public:
	WindowManager(int width, int height, const char* title, int fps);
	WindowManager(WindowManager&) = delete;
	~WindowManager();

	void Run();

   private:
	void Start();
	void Update();
	void LateUpdate();
	void LoadResources();
};