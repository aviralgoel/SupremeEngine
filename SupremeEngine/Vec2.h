#pragma once

class Vec2 {

public:
	float x{ 0.0f };
	float y{ 0.0f };

	// constructors & destructors
	Vec2() : x(0.0f), y(0.0f) {};
	Vec2(float _x, float _y)
		: x(_x), y(_y) {}
	~Vec2() = default;

	// methods
	void Add(const Vec2& v);
	void Sub(const Vec2& v);
	void Scale(const float& n);
	Vec2 Rotate(const float& angle) const;

	float Magnitude() const;
	float MagnitudeSquared() const;

	void Normalize();
	Vec2 UnitVector() const;
	Vec2 Normal() const;

	float Dot(const Vec2& v) const;
	float Cross(const Vec2& v) const;

};