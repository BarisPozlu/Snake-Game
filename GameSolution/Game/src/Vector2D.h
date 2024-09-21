#pragma once

struct Vector2D
{
public:
	Vector2D();
	Vector2D(float x, float y);
	Vector2D operator+(const Vector2D& other);
	Vector2D& operator+=(const Vector2D& other);
	
public:
	float x, y;
};
