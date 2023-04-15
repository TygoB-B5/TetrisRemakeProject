#pragma once

#include <vector>
#include "SDL.h"
#include "Core/Primitives.h"
#include "GridRenderer.h"
#include "Block.h"

namespace TetrisGame
{
	/// <summary>
	/// FTetris main gameplay class.
	/// </summary>
	class FTetris
	{
	public:
		void Init();
		void Update(float deltaTime);

	private:
		std::vector<FBlock> Blocks;
	};
}