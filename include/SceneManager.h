#pragma once

#include<string>
#include<print>

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

public:
	SceneManager(const SceneManager&) = delete;

	static SceneManager& GetInstance() {
		static SceneManager instance;
		return instance;
	}

	void SetGameScreen(GameScreen value);
	GameScreen GetGameScreen() const;
	std::string GetGameScreenString();

private:
	SceneManager();
};