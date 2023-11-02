#pragma once
namespace math
{
	static float DegToRad(float _degrees)
	{
		return _degrees * (3.141f / 180);
	}

	static float RadToDeg(float _radians)
	{
		return _radians * (180.f / 3.141f);
	}
}