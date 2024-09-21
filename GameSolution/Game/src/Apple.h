#pragma once

#include <SDL.h>

struct Apple
{
public:
	Apple(int size);
	void GetRandomPosition();

public:
	SDL_Rect rect;
};
