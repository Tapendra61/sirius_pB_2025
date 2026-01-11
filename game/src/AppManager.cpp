#include <AppManager.h>

AppManager::AppManager(int width, int height, const char* title, int fps)
	: engine(sr::Engine::Instance(width, height, title, fps)), sceneManager(SceneManager::GetInstance()) {
	windowWidth = width;
	windowHeight = height;
	windowTitle = title;
	this->fps = fps;
}

void AppManager::Run() {
	engine.Run(std::bind(&AppManager::Start, this), std::bind(&AppManager::Update, this),
			   std::bind(&AppManager::LateUpdate, this));
}

// Data initialization here
void AppManager::Start() {
	LoadResources();
	player = std::make_unique<Player>(Vector2{400.0f, 400.0f}, Vector2{2.5f, 2.5f});
	player->Init();
	sceneManager.SetGameScreen(MENU);
}

// Data update tasks here
void AppManager::Update() {
	player->Update();
	// customCamera.UpdateCameraTarget(player.GetTransform2D().Position());
}

// Drawing tasks here
void AppManager::LateUpdate() {
	settings.DrawFPSText();
	sceneManager.RenderUi();

	player->Draw();
}

void AppManager::LoadResources() {
	sr::gAssetLoader.LoadTex("player_idle", "../../resources/characters/the_blind_hunter/1. Idle 48 x 48.png");
	sr::gAssetLoader.LoadTex("player_run", "../../resources/characters/the_blind_hunter/2. Run 48 x 48.png");
}

AppManager::~AppManager() {}