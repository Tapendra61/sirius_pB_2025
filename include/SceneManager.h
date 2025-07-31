#pragma once

#include<string>
#include<print>

enum GameScreen{
	MENU,
	GAMEPLAY,
	PAUSE,
	GAMEOVER
};

class SceneManager {
public:
	GameScreen gameScreen;

public:
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

	static SceneManager& GetInstance() {
		static SceneManager instance;
		return instance;
	}

	void SetGameScreen(GameScreen value);
	std::string GetGameScreen(GameScreen value);

private:
	SceneManager();
};