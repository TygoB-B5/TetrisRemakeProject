#include "Game.h"
#include <iostream>
#include "Math.h"

namespace TetrisGame
{
	void Game::Init()
	{
		bIsRunning = true;

		Time = new FTime();
		EventHandler = new FEventHandler();
		Renderer = new FRenderer();

		EventHandler->AddEventDelegate(&Game::OnWindowEvent, SDL_WINDOWEVENT);

		Vec2 n{ 1, 1 };
		Vec2 a{ 10, 10 };

		FLog::Message(n + a);
	}

	void Game::ShutDown()
	{
		SDL_Quit();

		delete Time;
		delete EventHandler;
		delete Renderer;

		bIsRunning = false;
	}

	void Game::Tick()
	{
		Time->Tick();
		
		Renderer->DrawRect({ FMath::Cos(Time->GetTimeSinceStartup()) * 0.5f + 0.5f,
							 FMath::Sin(Time->GetTimeSinceStartup()) * 0.5f + 0.5f },
							{0.1f, 0.1f}, {225, 225, 0});

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