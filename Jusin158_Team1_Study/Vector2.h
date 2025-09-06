#pragma once
#include <cmath>

typedef struct Vector2
{
public:
	Vector2() : x(0.f), y(0.f) { };
	Vector2(const int& _x, const int& _y) : x((float)_x), y((float)_y) { };
	Vector2(const float& _x, const float& _y) : x(_x), y(_y) { };
	Vector2(const Vector2& _rhs)
	{
		x = _rhs.x;
		y = _rhs.y;
	}
	Vector2& operator=(const Vector2& _rhs)				// this = 벡터인수 | 반환값 : this
	{
		x = _rhs.x;
		y = _rhs.y;
		return *this;
	}
	Vector2 operator+(const Vector2& _vVec)				// this + 벡터 | 반환값 : 값 벡터
	{
		return Vector2(x + _vVec.x, y + _vVec.y);
	}
	Vector2 operator-(const Vector2& _vVec)				// this - 벡터 | 반환값 : 값 벡터
	{
		return Vector2(x - _vVec.x, y - _vVec.y);
	}
	Vector2 operator*(const int& _scalar)				// this * 정수 | 반환값 : 값 벡터
	{
		return Vector2( x * _scalar, y* _scalar );
	}
	Vector2 operator*(const float& _scalar)				// this * 실수 | 반환값 : 값 벡터
	{
		return Vector2( x * _scalar, y * _scalar );
	}
	Vector2& operator*=(const int& _scalar)				// this *= 정수 | 반환값 : this
	{
		x *= _scalar;
		y *= _scalar;
		return *this;
	}
	Vector2& operator*=(const float& _scalar)			// this *= 실수 | 반환값 : this
	{
		x *= _scalar;
		y *= _scalar;
		return *this;
	}
	Vector2& operator-=(const Vector2& _vVec)			// this -= 벡터 | 반환값 : this
	{
		x -= _vVec.x;
		y -= _vVec.y;
		return *this;
	}
	Vector2& operator+=(const Vector2& _vVec)			// this += 벡터 | 반환값 : this
	{
		x += _vVec.x;
		y += _vVec.y;
		return *this;
	}
	
	const float GetSquared() const						// this Vec2 x제곱, y제곱 | 반환 
	{
		return x * x + y * y;
	}
	Vector2 GetNomalized() const						// this의 x, y에 대함 피타고라스 식을 수행
	{													// x, y의 대각선(빗변)을 구해줌
		return Nomalize(*this);
	}
	Vector2& Rotate(const float& _fDegree)
	{
		float fRad = _fDegree * 3.14159f / 180.f * -1.f;
		float fCosx = cosf(fRad);
		float fSiny = sinf(fRad);

		float fHypot = sqrtf(GetSquared());
		x = fCosx * fHypot;
		y = fSiny * fHypot;
		return *this;
	}

	static Vector2 Nomalize(const Vector2& _vVec);		// _vVec에 대한 대각선 반환(정적 함수)

public:
	float x;
	float y;

	static const Vector2 UnitX;							// (1.f, 0.f)
	static const Vector2 UnitY;							// (0.f, 1.f)
	static const Vector2 Zero;							// (0.f, 0.f)
	static const Vector2 One;							// (1.f, 1.f)
};


