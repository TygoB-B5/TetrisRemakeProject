#pragma once

#include "Core.h"
#include "Math.h"
#include "Primitives.h"
#include "SDL.h"

namespace TetrisGame
{
	/// <summary>
	/// FRenderer used to render graphics.
	/// </summary>
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

			Vec2 screenPosition = { position.x * Resolution.x,
									position.y * Resolution.y};

			SDL_SetRenderDrawColor(Renderer, (Uint8)(color.x * 225.0f), (Uint8)(color.y * 225.0f), (Uint8)(color.z * 225.0f), 225);

			SDL_Rect rect({ (int)screenPosition.x, (int)screenPosition.y, (int)screenSize.x, (int)screenSize.y });
			SDL_RenderFillRect(Renderer, &rect);

		}

		void DrawRect(const Rect& rect) const
		{
			DrawRect(rect.Position, rect.Size, rect.Color);
		}

		void Clear(const Vec3& color = { 0.01f, 0.01f, 0.02f }) const
		{
			SDL_SetRenderDrawColor(Renderer, (Uint8)(color.x * 225.0f), (Uint8)(color.y * 225.0f), (Uint8)(color.z * 225.0f), 225);
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