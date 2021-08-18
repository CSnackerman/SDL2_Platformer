#include "Vec2.h"

Vec2::Vec2() {
	this->x = 0;
	this->y = 0;
}

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vec2 Vec2::operator=(const Vec2& rhs) {

	this->x = rhs.x;
	this->y = rhs.y;

	return *this;
}

Vec2 Vec2::operator+(Vec2 const& rhs) {

	float x = this->x + rhs.x;
	float y = this->y + rhs.y;

	return Vec2 (x, y);
}

Vec2 Vec2::operator-(Vec2 const& rhs)
{
	float x = this->x - rhs.x;
	float y = this->y - rhs.y;

	return Vec2(x, y);
}
