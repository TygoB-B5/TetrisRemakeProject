#include "Game.h"
#include "Math.h"
#include "Game/GridRenderer.h"

namespace TetrisGame
{
	Game* Game::Instance = nullptr;

	Game::Game()
	{
		bIsRunning = true;

		// Initialize components.
		Instance = this;
		Time = new FTime();
		EventHandler = new FEventHandler();
		Renderer = new FRenderer();
		Tetris = new FTetris();

		EventHandler->AddEventDelegate(&Game::OnWindowEvent, SDL_WINDOWEVENT);

		Tetris->Init();
	}

	Game::~Game()
	{
		SDL_Quit();
		delete Time;
		delete EventHandler;
		delete Renderer;
		delete Tetris;
	}

	void Game::ShutDown()
	{
		bIsRunning = false;
	}

	void Game::Tick()
	{
		Time->Tick();
		Tetris->Update((float)Time->GetTimeDelta());

		Renderer->Display();
		Renderer->Clear();
		
		EventHandler->HandleEvents();
	}

	void Game::OnWindowEvent(SDL_Event* e)
	{
			switch (e->window.event)
			{

			case SDL_WINDOWEVENT_CLOSE:
				ShutDown();
				break;
			}
	}
}