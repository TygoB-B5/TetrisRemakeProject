#pragma once

#include "SDL.h"
#include <functional>
#include <vector>

namespace TetrisGame
{
	class FEventHandler

	{
	public:
		typedef std::function<void(SDL_Event*)> EventDelegateCallback;

		void HandleEvents()
		{
			for (auto& callback : Callbacks)
			{
				SDL_Event e;
				while (SDL_PollEvent(&e))
				{
					// Run callback function if type matches.
					if (e.type == callback.second)
					{
						callback.first(&e);
					}
				}
			}
		}

		
#define AddEventDelegate(func, eventType) _AddEventDelegate(std::bind(func, this, std::placeholders::_1), eventType)

		void _AddEventDelegate(EventDelegateCallback delegate, SDL_EventType eventType)
		{
			Callbacks.push_back({ delegate, eventType });
		}

	private:
		std::vector<std::pair<EventDelegateCallback, SDL_EventType>> Callbacks;
	};
}