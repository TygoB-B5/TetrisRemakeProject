#pragma once

#include "Math.h"
#include "SDL.h"

namespace TetrisGame
{
	class FRenderer
	{
	public:

		FRenderer()
		{
			SDL_Init(SDL_INIT_VIDEO);
			Window = SDL_CreateWindow("MyWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WindowFlags::SDL_WINDOW_VULKAN);

			Renderer = SDL_CreateRenderer(Window, 0, 0);
			Surface = SDL_GetWindowSurface(Window);
			Resolution.x = (float)Surface->w;
			Resolution.y = (float)Surface->h;
		}

		~FRenderer()
		{
			SDL_DestroyWindow(Window);
		}

		const Vec2& GetResolution() const
		{
			return Resolution;
		}

		void DrawRect(const Vec2& position, const Vec2& size, const Vec3& color) const
		{
			Vec2 screenSize = { size.x * Resolution.x,
								size.y * Resolution.y };

			Vec2 screenPosition = { position.x * Resolution.x - screenSize.x * 0.5f,
									position.y * Resolution.y - screenSize.y * 0.5f };

			SDL_SetRenderDrawColor(Renderer, color.x, color.y, color.z, 225);

			SDL_Rect rect({ (int)screenPosition.x, (int)screenPosition.y, (int)screenSize.x, (int)screenSize.y });
			SDL_RenderFillRect(Renderer, &rect);

		}

		void Clear(const Vec3& color = { 10, 10, 14 }) const
		{
			SDL_SetRenderDrawColor(Renderer, color.x, color.y, color.z, 225);
			SDL_RenderClear(Renderer);
		}

		void Display() const
		{
			SDL_RenderPresent(Renderer);
		}

	private:
		SDL_Renderer* Renderer;
		SDL_Window* Window;
		SDL_Surface* Surface;
		Vec2 Resolution;
	};
}