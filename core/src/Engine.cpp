#include"Engine.h"

namespace Sirius {
	Engine::Engine(const int width, const int height, const char* title, const int fps) {
		InitWindow(width, height, title);
		SetTargetFPS(fps);
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
		while(!WindowShouldClose()) {
			BeginDrawing();
			update();

			BeginMode2D();
			lateUpdate();
			EndMode2D();
			
			EndDrawing();
		}
	}
}