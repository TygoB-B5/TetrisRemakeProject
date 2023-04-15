#pragma once

#include "Core.h"

namespace TetrisGame
{
	/// <summary>
	/// FTime class to manage in-game time.
	/// </summary>
	class FTime
	{
	public:
		typedef double TimePoint;

		FORCEINLINE TimePoint GetTimeDelta()
		{
			return TimeDelta;
		}

		FORCEINLINE TimePoint GetTimeSinceStartup()
		{
			return TimeSinceStartup;
		}

		friend class Game;

	private:

		FORCEINLINE void Tick()
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