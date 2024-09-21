#include "Apple.h"
#include <cstdlib>
#include <ctime>

Apple::Apple(int size)
{
	srand(time(nullptr));
	GetRandomPosition();
	rect.w = size;
	rect.h = size;
}

void Apple::GetRandomPosition()
{
	rect.x = rand() % 63 * 10;
	rect.y = rand() % 47 * 10;
}
