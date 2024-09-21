#pragma once

#include <SDL.h>
#include <vector>
#include "Vector2D.h"

class Snake
{
public:
	Snake(int rectSize, const SDL_Point& initialPosition, const Vector2D& extendDirection);
	void Grow();
	void UpdateVelocity(SDL_Event* event);
	bool UpdatePosition(const Vector2D& bounds);
	bool CollidingItself();
	void Render(SDL_Renderer* renderer);
	SDL_Rect GetHead();

public:
	inline Vector2D GetPosition() { return m_body.front(); }
	inline int GetRectSize() { return m_rectSize; }

private:
	int m_initialSize;
	int m_rectSize;
	Vector2D m_velocity;
	std::vector<Vector2D> m_body;
};
