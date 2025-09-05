	#include "pch.h"
#include "Vector2.h"

const Vector2 Vector2::UnitX(1.0f, 0.f);
const Vector2 Vector2::UnitY(0.f, 1.f);
const Vector2 Vector2::Zero(0.f, 0.f);
const Vector2 Vector2::One(1.f, 1.f);

Vector2 Vector2::Nomalize(const Vector2& _vVec)
{
	float fSquareSum = _vVec.GetSquared();
	if (fSquareSum == 0.f)
		return Vector2::Zero;

	float mag = sqrtf(fSquareSum);
	return Vector2(_vVec.x / mag, _vVec.y / mag);
}