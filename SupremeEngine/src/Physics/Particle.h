#pragma once
#include "Vec2.h"

class Particle
{

public:
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_acceleration;
	float m_mass;
	Particle() = default;
	Particle(Vec2 _position, float _mass);
	~Particle();

	// getter and setter
};

