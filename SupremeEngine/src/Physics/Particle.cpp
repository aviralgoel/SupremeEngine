#include "Particle.h"
#include <iostream>

Particle::Particle(Vec2 _position, float _mass) : m_position(_position), m_mass(_mass) 
{
	std::cout << "Particle constructor called!\n";
};

Particle::~Particle()
{
	std::cout << "Particle destructor called!\n";
}

