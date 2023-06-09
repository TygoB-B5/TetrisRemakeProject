#define SDL_MAIN_HANDLED
#include "SDL.h"

#include "Core.h"

#include "Game.h"
#include <exception>

int main()
{
	TetrisGame::Game* game = nullptr;

	try
	{
		game = new TetrisGame::Game();

		while (game->bIsRunning)
		{
			game->Tick();
		}
	}
	catch (const std::exception& e)
	{
		TetrisGame::FLog::Assert(false, e.what());
	}
	
	delete game;
	return 0;
}