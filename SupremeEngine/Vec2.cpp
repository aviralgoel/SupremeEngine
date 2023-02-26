#include "Vec2.h"
#include <cmath>
#include <cassert>
void Vec2::Add(const Vec2& v)
{
	x += v.x;
	y += v.y;
}

void Vec2::Sub(const Vec2& v)
{
	x -= v.x;
	y -= v.y;
}

void Vec2::Scale(const float& n)
{
	x *= n;
	y *= n;
}
Vec2 Vec2::Rotate(const float& angle) const
{
	Vec2 result(0.0f, 0.0f);
	result.x = x * cos(angle) - y * sin(angle);
	result.y = x * sin(angle) + y * cos(angle);

	return result;

}

float Vec2::Magnitude() const
{
	float result = std::sqrtf((x * x) + (y * y));
	return result;
}

float Vec2::MagnitudeSquared() const
{
	float result = (x * x) + (y * y);
	return result;
}

void Vec2::Normalize()
{
	float length = Magnitude();
	assert(length!=0);
	x = x / length;
	y = y / length;
}

Vec2 Vec2::UnitVector() const
{
	Vec2 result(0.0f, 0.0f);
	float length = Magnitude();
	result.x = x / length;
	result.y = y / length;
	result.Normalize();
	return result;
}

Vec2 Vec2::Normal() const
{	
	Vec2 result(y, -1.0*x );
	return result;
}

float Vec2::Dot(const Vec2& v) const
{
	float result = 0.0f;
	result = ((x * v.x) + (y * v.y));
	return result;
}

float Vec2::Cross(const Vec2& v) const
{
	float result = 0;
	result = ((x * v.x) - (y * v.y));
	return result;
}





