/*
	@file WindowManager.h
	@author Tapendra Shahi
	@date 2025-07-31
	@brief Defines window management functions for Raylib Window
*/

#pragma once

#include <SceneManager.h>

#include <iostream>
#include <memory>
#include <print>
#include <raylib/raylib.h>

#include"Engine.h"
#include "CustomCamera.h"
#include "Player.h"
#include "Settings.h"

class AppManager {
  private:
	int windowWidth;
	int windowHeight;
	int fps;
	const char* windowTitle;

	// Dependenceis
	Sirius::Engine& engine;
	SceneManager& sceneManager;
	Settings settings;

	// Camera
	Sirius::CustomCamera customCamera;

	// Player in game
	std::unique_ptr<Player> player;

  public:
	AppManager(int width, int height, const char* title, int fps);
	AppManager(AppManager&) = delete;
	~AppManager();

	void Run();

  private:
	void Start();
	void Update();
	void LateUpdate();
	void LoadResources();
};