#include<SceneManager.h>

SceneManager::SceneManager() {
	gameScreen = MENU;
}

void SceneManager::SetGameScreen(GameScreen value) {
	gameScreen = value;
}

GameScreen SceneManager::GetGameScreen() const {
	return gameScreen;
}

std::string SceneManager::GetGameScreenString() {
	switch (gameScreen) {
	case GameScreen::LOGO:
		return "LOGO";
		break;
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