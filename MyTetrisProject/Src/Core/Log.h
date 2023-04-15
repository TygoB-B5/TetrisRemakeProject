#pragma once
#include "Core.h"
#include <sstream>
#include <iostream>

namespace TetrisGame
{
	/// <summary>
	/// FLog class used for logging messages.
	/// </summary>
	struct FLog
	{
#ifdef _DEBUG
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
				std::stringstream ss;
				ss << "ASSERT: " << message << std::endl;
				throw std::exception(ss.str().c_str());
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