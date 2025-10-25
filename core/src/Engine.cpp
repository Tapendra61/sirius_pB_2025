#include "Engine.h"

namespace Sirius {
	Engine::Engine(const int width, const int height, const char* title, const int fps) {
		InitWindow(width, height, title);
		SetTargetFPS(fps);
		ToggleBorderlessWindowed();
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

	void Engine::Run(std::function<void()> start, std::function<void()> update, std::function<void()> lateUpdate) {
		running = true;
		start();
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(backgroundClearColor);

			update();

			BeginMode2D(defaultCamera->GetCamera());
			lateUpdate();
			EndMode2D();

			EndDrawing();
		}
	}

	void Engine::InitDefaultCamera() {
		defaultCamera = std::make_shared<CustomCamera>();
	}
} // namespace Sirius