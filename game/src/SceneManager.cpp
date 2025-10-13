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
		return "No Game Screen";
		break;
	}
}

void SceneManager::RenderUi() {
	switch (gameScreen) {
	case MENU:
		RenderMainMenu();
		break;
	case GAMEPLAY:
		RenderGameUi();
		RenderGame();
	default:
		std::cout << "Defult Case Invoked!" << std::endl;
		break;
	}
}

void SceneManager::RenderMainMenu() {
	
}

void SceneManager::RenderGameUi() {

}

void SceneManager::RenderGame() {

}

void SceneManager::RenderPausedMenu() {

}

void SceneManager::RenderGameOverMenu() {

}