#pragma once

#include <iostream>
#include <functional>

#include <raylib/raylib.h>

namespace Sirius
{
	class Engine
	{
	private:
		bool running = false;

	private:
		Engine(const int width, const int height, const char *title, const int fps);
		~Engine();

		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
		Engine(Engine&&)=delete;
		Engine& operator=(Engine&&) = delete;

	public:
		static Engine& Instance(const int width = 1280, const int height = 720, const char* title = "Sirius Engine", const int fps=120);
		void Run(std::function<void()> start, std::function<void()> update, std::function<void()> lateUpdate);
	};
}