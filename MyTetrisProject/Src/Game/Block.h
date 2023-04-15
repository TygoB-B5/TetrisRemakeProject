#pragma once

#include <array>
#include "Core/Math.h"
#include "Core/Primitives.h"

namespace TetrisGame
{
	struct FBlock
	{
		std::array<Vec2, 4> BlockPositions;
		std::array<Rect, 4> Renderables;
		Vec3 Color;
	};


	FBlock CreateBlockOfType(int type)
	{
	}
}