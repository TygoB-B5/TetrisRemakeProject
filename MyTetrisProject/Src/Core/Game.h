#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"

#include "Core.h"
#include "Time.h"
#include "EventHandler.h"
#include "Renderer.h"
#include "Game/Tetris.h"

namespace TetrisGame
{
	/// <summary>
	/// Main game instance class.
	/// </summary>
	class Game
	{
	public:
		Game();
		~Game();

		static Game* Get()
		{
			return Instance;
		}

		void ShutDown();

		void Tick();

		void OnWindowEvent(SDL_Event* e);

	public:
		FTetris* Tetris;
		FEventHandler* EventHandler;
		FTime* Time;
		FRenderer* Renderer;
		bool bIsRunning;

	private:
		static Game* Instance;
	};
}