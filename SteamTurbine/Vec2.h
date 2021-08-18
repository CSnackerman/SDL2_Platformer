#pragma once
class Vec2
{
public:
	
	// data
	float x, y;

	// functions
	Vec2();
	Vec2(float x, float y);

	// Operator overload
	Vec2 operator = (const Vec2 &rhs);
	Vec2 operator + (Vec2 const &rhs);
	Vec2 operator - (Vec2 const &rhs);
};

