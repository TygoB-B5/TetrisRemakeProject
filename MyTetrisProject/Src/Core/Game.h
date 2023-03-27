#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"

#include "Core.h"
#include "Time.h"
#include "EventHandler.h"
#include "Renderer.h"

namespace TetrisGame
{
	class Game
	{
	public:
		void Init();

		void ShutDown();

		void Tick();

		void OnWindowEvent(SDL_Event* e);

	public:
		FEventHandler* EventHandler;
		FTime* Time;
		SDL_Window* Window;
		FRenderer* Renderer;
		bool bIsRunning;
	};
}