#include "Tetris.h"
#include "Core/Game.h"
namespace TetrisGame
{
	void FTetris::Init()
	{

	}

	void FTetris::Update(float deltaTime)
	{
		Rect a = FGridRenderer::CreateRect(40, 40, 20, 20);
		a.Color = { 0, 1, 1 };
		Game::Get()->Renderer->DrawRect(a);
	}
}