#pragma once
#include "Vec2.h"

class Particle
{	
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_acceleration;
	float m_mass;
public:

	Particle() = default;
	Particle(Vec2 _position, float _mass);
	~Particle();

	// getter and setter
	Vec2 getPosition() const { return m_position; }
	void setPosition(Vec2 _position) { m_position = _position; }
	Vec2 getVelocity() const { return m_velocity; }
	void setVelocity(Vec2 _velocity) { m_velocity = _velocity; }
	Vec2 getAcceleration() const { return m_acceleration; }
	void setAcceleration(Vec2 _acceleration) { m_acceleration = _acceleration; }
	float getMass() const { return m_mass; }
	void setMass(float _mass) { m_mass = _mass; }



};

