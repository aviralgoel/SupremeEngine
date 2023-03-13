#include "Vec2.h"
#include <math.h>

Vec2::Vec2(): m_x(0.0), m_y(0.0) { }

Vec2::Vec2(float _x, float _y): m_x(_x), m_y(_y) { }

void Vec2::Add(const Vec2& _v) {
	m_x += _v.m_x;
	m_y += _v.m_y;
}

void Vec2::Sub(const Vec2& _v) {
	m_x -= _v.m_x;
	m_y -= _v.m_y;
}

void Vec2::Scale(const float _n) {
	m_x *= _n;
	m_y *= _n;
}

Vec2 Vec2::Rotate(const float _angle) const {
	Vec2 result;
	result.m_x = m_x * cos(_angle) - m_y * sin(_angle);
	result.m_y = m_x * sin(_angle) + m_y * cos(_angle);
	return result;
}

float Vec2::Magnitude() const {
	return sqrtf(m_x * m_x + m_y * m_y);
}

float Vec2::MagnitudeSquared() const {
	return (m_x * m_x + m_y * m_y);
}

void Vec2::Normalize() {
	float length = Magnitude();
	if (length != 0.0) {
		m_x /= length;
		m_y /= length;
	}
}

Vec2 Vec2::UnitVector() const {
	Vec2 result = Vec2(0, 0);
	float length = Magnitude();
	if (length != 0.0) {
		result.m_x = m_x / length;
		result.m_y = m_y / length;
	}
    return result;
}

Vec2 Vec2::Normal() const {
	Vec2 result = Vec2(m_y, -m_x);
	result.Normalize();
	return result;
}

float Vec2::Dot(const Vec2& _v) const {
    return (m_x * _v.m_x) + (m_y * _v.m_y);
}

float Vec2::Cross(const Vec2& _v) const {
	return (m_x * _v.m_y) - (m_y * _v.m_x);
}

Vec2& Vec2::operator = (const Vec2& _v) {
	m_x = _v.m_x;
	m_y = _v.m_y;
	return *this;
}

bool Vec2::operator == (const Vec2& _v) const {
	return m_x == _v.m_x && m_y == _v.m_y;
}

bool Vec2::operator != (const Vec2& _v) const {
	return !(*this == _v);
}

Vec2 Vec2::operator + (const Vec2& _v) const {
	Vec2 result;
	result.m_x = m_x + _v.m_x;
	result.m_y = m_y + _v.m_y;
	return result;
}

Vec2 Vec2::operator - (const Vec2& _v) const {
	Vec2 result;
	result.m_x = m_x - _v.m_x;
	result.m_y = m_y - _v.m_y;
	return result;
}

Vec2 Vec2::operator * (const float _n) const {
	Vec2 result;
	result.m_x = m_x * _n;
	result.m_y = m_y * _n;
	return result;
}

Vec2 Vec2::operator / (const float _n) const {
	Vec2 result;
	result.m_x = m_x / _n;
	result.m_y = m_y / _n;
	return result;
}

Vec2& Vec2::operator += (const Vec2& _v) {
	m_x += _v.m_x;
	m_y += _v.m_y;
	return *this;
}

Vec2& Vec2::operator -= (const Vec2& _v) {
	m_x -= _v.m_x;
	m_y -= _v.m_y;
	return *this;
}

Vec2& Vec2::operator *= (const float _n) {
	m_x *= _n;
	m_y *= _n;
    return *this;
}

Vec2& Vec2::operator /= (const float _n) {
	m_x /= _n;
	m_y /= _n;
    return *this;
}

Vec2 Vec2::operator - () {
	Vec2 result;
	result.m_x = m_x * -1;
	result.m_y = m_y * -1;
	return result;
}