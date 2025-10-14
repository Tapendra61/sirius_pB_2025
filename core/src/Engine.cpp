#include"Engine.h"

namespace Sirius {
	Engine::Engine(const int width, const int height, const char* title, const int fps) {
		InitWindow(width, height, title);
		SetTargetFPS(fps);
		running = true;
	}

	Engine::~Engine() {
		CloseWindow();
	}

	void Engine::Run(std::function<void()> start, std::function<void()> update, std::function<void()> lateUpdate) {
		start();
		while(!WindowShouldClose()) {
			
		}
	}
}