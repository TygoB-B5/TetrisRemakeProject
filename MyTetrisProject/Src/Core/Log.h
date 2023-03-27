#pragma once
#include "Core.h"
#include <iostream>

namespace TetrisGame
{
#ifdef _DEBUG

	struct FLog
	{
		template<typename T> 
		static FORCEINLINE void Message(const T& message)
		{
			std::cout << "MESSAGE: " << message << std::endl;
		}

		template<typename T>
		static FORCEINLINE void Warn(const T& message)
		{
			std::cout << "WARNING: " << message << std::endl;
		}

		template<typename T>
		static FORCEINLINE void Error(const T& message)
		{
			std::cout << "ERROR: " << message << std::endl;
		}

		template<typename T>
		static FORCEINLINE void Assert(bool condition, const T& message)
		{
			if (!condition)
			{
				std::cout << "ASSERT: " << message << std::endl;
				throw std::exception("Assert has been called");
			}
		}

#else

	template<typename T>
	static FORCEINLINE void Message(const T& message)
	{}

	template<typename T>
	static FORCEINLINE void Warn(const T& message)
	{}

	template<typename T>
	static FORCEINLINE void Error(const T& message)
	{}

	template<typename T>
	static FORCEINLINE void Assert(bool condition, const T& message)
	{}

#endif
	};
}