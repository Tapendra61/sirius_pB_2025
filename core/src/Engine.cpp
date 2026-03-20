#include "Engine.h"

namespace sr {
	Engine::Engine(const int width, const int height, const char* title, const int fps) {
		InitWindow(width, height, title);
		SetTargetFPS(fps);
		//ToggleBorderlessWindowed();
		DisableCursor();
		InitDefaultCamera();
	}

	Engine::~Engine() {
		CloseWindow();
	}

	Engine& Engine::Instance(const int width, const int height, const char* title, const int fps) {
		static Engine instance(width, height, title, fps);
		return instance;
	}

	void Engine::Run(std::function<void()> start, std::function<void()> update, std::function<void()> late_update) {
		running = true;
		start();
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(background_clear_color_);

			update();

			BeginMode2D(default_camera_->GetCamera());
			late_update();
			EndMode2D();

			EndDrawing();
		}
	}

	void Engine::InitDefaultCamera() {
		default_camera_ = std::make_shared<CustomCamera>();
	}
	
	void Engine::SetBackgroundClearColor(const Color clear_color) {
		background_clear_color_ = clear_color;
	}
} // namespace sr
