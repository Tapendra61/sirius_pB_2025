#pragma once

#include <functional>
#include <memory>

#include "CustomCamera.h"
#include "EntityManager.h"
#include <raylib/raylib.h>

namespace sr {
	class Engine {
	  private:
		bool running = false;
		Color background_clear_color_ = RAYWHITE;

		// Dependencies
		std::shared_ptr<CustomCamera> default_camera_;
		EntityManager entity_manager_;

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
		void Run(std::function<void()> start, std::function<void()> update, std::function<void()> late_update);
		void SetBackgroundClearColor(const Color clear_color);
		void InitDefaultCamera();

		EntityManager& GetEntityManager();
		const EntityManager& GetEntityManager() const;
	};
} // namespace sr