#include<SceneManager.h>

SceneManager::SceneManager() {
	gameScreen = MENU;
}

void SceneManager::SetGameScreen(GameScreen value) {
	gameScreen = value;
}

std::string SceneManager::GetGameScreen(GameScreen value) {
	switch (value) {
	case GameScreen::MENU:
		return "MENU";
		break;
	case GameScreen::GAMEPLAY:
		return "GAMEPLAY";
		break;
	case GameScreen::PAUSE:
		return "PAUSE";
		break;
	case GameScreen::GAMEOVER:
		return "GAMEOVER";
		break;
	default:
		std::printf("Might add some shit later!");
		break;
	}
}