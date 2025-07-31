#include<WindowManager.h>

WindowManager::WindowManager(int width, int height, const char* title, int fps) {
	windowWidth = width;
	windowHeight = height;
	windowTitle = title;
	this->fps = fps;
}

void WindowManager::Run() {
	InitWindow(windowWidth, windowHeight, windowTitle);
	
	if (!IsWindowReady()) {
		std::println(stderr, "Window creation failed!");
		CloseWindow();
	}
	
	SetTargetFPS(fps);
	ToggleFullscreen();

	//Initialize game data
	Start();
	while (!WindowShouldClose()) {
		//Update game data
		Update();

		//Render
		BeginDrawing();
		LateUpdate();
		EndDrawing();
	}
}

void WindowManager::Start() {
	SceneManager::GetInstance().SetGameScreen(MENU);
}

void WindowManager::Update() {

}

void WindowManager::LateUpdate() {

}