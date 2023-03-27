#pragma once

#include "Core.h"

namespace TetrisGame
{
	class FTime
	{
	public:
		typedef double TimePoint;

		TimePoint GetTimeDelta()
		{
			return TimeDelta;
		}

		TimePoint GetTimeSinceStartup()
		{
			return TimeSinceStartup;
		}

		friend class Game;

	private:

		void Tick()
		{
			double tickTime = (double)SDL_GetTicks() / 1000.0f;
			TimeDelta = (double)(tickTime - TimeSinceStartup);
			TimeSinceStartup = tickTime;
		}

	private:
		double TimeDelta;
		double TimeSinceStartup;
	};
}