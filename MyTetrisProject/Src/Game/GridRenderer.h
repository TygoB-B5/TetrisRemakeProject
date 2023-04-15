#pragma once

#include "Core/Core.h"
#include "Core/Primitives.h"
#include "SDL.h"

namespace TetrisGame
{
	/// <summary>
	/// FGridRenderer class used to create renderable rects in a grid to fill the screen.
	/// </summary>
	struct FGridRenderer
	{
		static FORCEINLINE Rect CreateRect(int xGridSize, int yGridSize, int x, int y)
		{

			Vec2 pos = { (float)x / (float)xGridSize, (float)y / (float)yGridSize };
			Vec2 size = { 1.0f / xGridSize, 1.0f / yGridSize };
			return Rect{ pos, size };
		}
	};
}