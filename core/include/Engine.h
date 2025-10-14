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

	public:
		Engine(const int width, const int height, const char *title, const int fps);
		~Engine();

		void Run(std::function<void()> start, std::function<void()> update, std::function<void()> lateUpdate);
	};
}