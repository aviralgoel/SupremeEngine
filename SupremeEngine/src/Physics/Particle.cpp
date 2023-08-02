#include "Particle.h"
#include <iostream>

Particle::Particle(Vec2 _position, float _mass, float _radius) : m_position(_position), m_mass(_mass), m_radius (_radius)
{
	std::cout << "Particle constructor called!\n";
}
Particle::Particle(float _x, float _y, float _mass, float _radius) : m_position(Vec2(_x, _y)), m_mass(_mass), m_radius(_radius) 
{
	std::cout << "Particle constructor called!\n";
}

Particle::~Particle()
{
	std::cout << "Particle destructor called!\n";
}

