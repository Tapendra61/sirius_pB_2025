#include <WindowManager.h>

WindowManager::WindowManager(int width, int height, const char* title, int fps)
	: sceneManager(SceneManager::GetInstance()),
	  player({400.0f, 400.0f}, {2.0f, 2.0f}) {
	windowWidth = width;
	windowHeight = height;
	windowTitle = title;
	this->fps = fps;
}

void WindowManager::Run() {
	InitWindow(windowWidth, windowHeight, windowTitle);

	if (!IsWindowReady()) {
		std::cout << "Window Creation Filed!!" << std::endl;
		CloseWindow();
	}

	SetTargetFPS(fps);
	ToggleBorderlessWindowed();
	DisableCursor();

	// Initialize game data
	Start();
	while (!WindowShouldClose()) {
		ClearBackground(RAYWHITE);
		// Update game data
		Update();

		// Render
		BeginDrawing();
		LateUpdate();
		EndDrawing();
	}
}

// Data initialization here
void WindowManager::Start() {
	LoadResources();

	player.Init();
	sceneManager.SetGameScreen(MENU);
}

// Data update tasks here
void WindowManager::Update() {
	player.Update();
	customCamera.UpdateCameraTarget(player.GetPosition());
}

// Drawing tasks here
void WindowManager::LateUpdate() {
	settings.DrawFPSText();
	sceneManager.RenderUi();

	BeginMode2D(customCamera.GetCamera());

	player.Draw();

	EndMode2D();
}

void WindowManager::LoadResources() {
	gAssetLoader.LoadTex(
		"player_idle",
		"resources/characters/the_blind_hunter/1. Idle 48 x 48.png");
	gAssetLoader.LoadTex(
		"player_run",
		"resources/characters/the_blind_hunter/2. Run 48 x 48.png");
}