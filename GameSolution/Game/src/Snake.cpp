#include "Snake.h"
#include "Collision.h"
#include <SDL.h>

Snake::Snake(int rectSize, const SDL_Point& initialPosition, const Vector2D& extendDirection) :
	m_initialSize(10), m_rectSize(rectSize), m_velocity(-m_rectSize, 0)
{
	for (int i = 0; i < m_initialSize; i++)
	{
		m_body.emplace_back
			(
			initialPosition.x + i * extendDirection.x * m_rectSize,
			initialPosition.y + i * extendDirection.y * m_rectSize
			);
	}

}

void Snake::Grow()
{
	m_body.emplace_back(m_body.back().x, m_body.back().y);
}

void Snake::UpdateVelocity(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN)
	{
		if (event->key.keysym.sym == SDLK_w && m_velocity.y == 0)
		{
			m_velocity = Vector2D(0, -m_rectSize);
		}

		else if (event->key.keysym.sym == SDLK_a && m_velocity.x == 0)
		{
			m_velocity = Vector2D(-m_rectSize, 0);
		}

		else if (event->key.keysym.sym == SDLK_s && m_velocity.y == 0)
		{
			m_velocity = Vector2D(0, m_rectSize);
		}

		else if (event->key.keysym.sym == SDLK_d && m_velocity.x == 0)
		{
			m_velocity = Vector2D(m_rectSize, 0);
		}
	}
}

bool Snake::UpdatePosition(const Vector2D& bounds)
{
	for (int i = m_body.size() - 1; i > 0; i--)
	{
		m_body[i] = m_body[i - 1];
	}

	Vector2D& head = m_body.front();
	head += m_velocity;
	

	return head.x >= 0 && head.x <= bounds.x - m_rectSize &&
		   head.y >= 0 && head.y <= bounds.y - m_rectSize;
}

bool Snake::CollidingItself()
{
	for (int i = 1; i < m_body.size(); i++)
	{
		if (IsColliding(GetHead(), { (int)m_body[i].x, (int)m_body[i].y, m_rectSize, m_rectSize }))
		{
			return true;
		}
	}

	return false;
}

void Snake::Render(SDL_Renderer* renderer)
{
	for (int i = 0; i < m_body.size(); i++)
	{
		SDL_Rect rect = { (int)m_body[i].x, (int)m_body[i].y, m_rectSize, m_rectSize};
		SDL_RenderFillRect(renderer, &rect);
	}

}

SDL_Rect Snake::GetHead()
{
	SDL_Rect rect = { (int)m_body[0].x, (int)m_body[0].y, m_rectSize, m_rectSize };
	return rect;
}
