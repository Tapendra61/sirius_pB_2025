#pragma once

#include <functional>
#include <memory>

#include <raylib/raylib.h>

#include "CustomCamera.h"
#include "EntityManager.h"
#include "AssetLoader.h"

namespace sr {
	class Engine {
	private:
		bool running_ = false;
		Color background_clear_color_ = RAYWHITE;

		// Dependencies
		std::unique_ptr<AssetLoader> asset_loader_ = nullptr;
		std::shared_ptr<CustomCamera> default_camera_ = nullptr;

	private:
		Engine(const int width, const int height, const char* title, const int fps);
		~Engine();

		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
		Engine(Engine&&) = delete;
		Engine& operator=(Engine&&) = delete;

	public:
		static Engine& Instance(const int width = 1280, const int height = 720, const char* title = "Sirius Engine",
								const int fps = 120);
		AssetLoader& GetAssetLoader() { return *asset_loader_; }
		
		void Run(std::function<void()> start, std::function<void()> update, std::function<void()> late_update);
		void SetBackgroundClearColor(const Color clear_color);
		
	private:
		void Init();
		void InitDefaultCamera();
		void InitAssetLoader();
	};
} // namespace sr
