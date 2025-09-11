#pragma once

#include<string>
#include<iostream>
#include<raylib/raylib.h>

enum GameScreen{
	LOGO,
	MENU,
	GAMEPLAY,
	PAUSE,
	GAMEOVER
};

class SceneManager {
private:
	GameScreen gameScreen;
	int menuIndex = 0;

public:
	SceneManager(const SceneManager&) = delete;

	static SceneManager& GetInstance() {
		static SceneManager instance;
		return instance;
	}

	void SetGameScreen(GameScreen value);
	GameScreen GetGameScreen() const;
	std::string GetGameScreenString();
	void RenderUi();

private:
	SceneManager();

	void RenderMainMenu();
	void RenderGameUi();
	void RenderGame();
	void RenderPausedMenu();
	void RenderGameOverMenu();
};