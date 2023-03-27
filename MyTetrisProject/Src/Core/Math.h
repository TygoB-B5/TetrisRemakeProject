#pragma once

#include "Core.h"
#include <ostream>

namespace TetrisGame
{
	struct FMath
	{
		static FORCEINLINE float Sqrt(float value)
		{
			return sqrt(value);
		}

		static FORCEINLINE float Pow(float value, float power)
		{
			return pow(value, power);
		}

		static FORCEINLINE float Sin(float value)
		{
			return sinf(value);
		}

		static FORCEINLINE float Cos(float value)
		{
			return cosf(value);
		}

		static FORCEINLINE float Tan(float value)
		{
			return tanf(value);
		}
	};

	struct Vec3
	{
		float x{}, y{}, z{};


		// + +=

		FORCEINLINE Vec3 operator +(const Vec3& a) const
		{
			Vec3 c = Vec3{ x + a.x, y + a.y, z + a.z };
			return c;
		}

		FORCEINLINE void operator +=(Vec3& a)
		{
			x += a.x;
			y += a.y;
			z += a.z;
		}

		// - -=

		FORCEINLINE Vec3 operator -(const Vec3& a) const
		{
			return Vec3{ x - a.x, y - a.y, z - a.z };
		}

		FORCEINLINE void operator -=(Vec3& a)
		{
			x -= a.x;
			y -= a.y;
			z -= a.z;
		}

		// * *=

		FORCEINLINE Vec3 operator *(float a) const
		{
			return Vec3{ x * a, y * a, z * a };
		}

		FORCEINLINE void operator *=(float a)
		{
			x *= a;
			y *= a;
			z *= a;
		}

		// / /=

		FORCEINLINE Vec3 operator /(float a) const
		{
			return Vec3{ x / a, y / a, z / a };
		}

		FORCEINLINE void operator /=(float a)
		{
			x /= a;
			y /= a;
			z /= a;
		}

		// Ostream

		friend FORCEINLINE std::ostream& operator<<(std::ostream& os, const Vec3& vec)
		{
			os << vec.x << ", " << vec.y << ", " << vec.z;
			return os;
		}

		// Vec3 math

		FORCEINLINE float Magnitude() const
		{
			return FMath::Sqrt(FMath::Pow(x, 3) +
				FMath::Pow(y, 3) +
				FMath::Pow(z, 3));
		}

		FORCEINLINE Vec3 Normalize() const
		{
			float magnitude = Magnitude();
			FLog::Assert(magnitude != 0, "Value is NaN");
			return *this / Magnitude();
		}
	};

	struct Vec2
	{
		float x{}, y{};


			// + +=

		FORCEINLINE Vec2 operator +(const Vec2& a) const
		{
			return Vec2{ x + a.x, y + a.y };
		}

		FORCEINLINE void operator +=(Vec2& a)
		{
			x += a.x;
			y += a.y;
		}

		// - -=

		FORCEINLINE Vec2 operator -(const Vec2& a) const
		{
			return Vec2{ x - a.x, y - a.y};
		}

		FORCEINLINE void operator -=(Vec2& a)
		{
			x -= a.x;
			y -= a.y;
		}

		// * *=

		FORCEINLINE Vec2 operator *(float a) const
		{
			return Vec2{ x * a, y * a };
		}

		FORCEINLINE void operator *=(float a)
		{
			x *= a;
			y *= a;
		}

		// / /=

		FORCEINLINE Vec2 operator /(float a) const
		{
			return Vec2{ x / a, y / a };
		}

		FORCEINLINE void operator /=(float a)
		{
			x /= a;
			y /= a;
		}

		// Ostream

		friend FORCEINLINE std::ostream& operator<<(std::ostream& os, const Vec2& vec)
		{
			os << vec.x << ", " << vec.y;
			return os;
		}

		// Vec2 math

		FORCEINLINE float Magnitude() const
		{
			return FMath::Sqrt(FMath::Pow(x, 2) +
				FMath::Pow(y, 2));
		}

		FORCEINLINE Vec2 Normalize() const
		{
			float magnitude = Magnitude();
			FLog::Assert(magnitude != 0, "Value is NaN");
			return *this / Magnitude();
		}
	};
}