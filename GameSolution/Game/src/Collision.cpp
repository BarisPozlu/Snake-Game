#include "Collision.h"
#include <SDL.h>

bool IsColliding(const SDL_Rect& rect1, const SDL_Rect& rect2)
{
    int rect1Left = rect1.x;
    int rect1Right = rect1.x + rect1.w;
    int rect1Top = rect1.y;
    int rect1Bottom = rect1.y + rect1.h;

    int rect2Left = rect2.x;
    int rect2Right = rect2.x + rect2.w;
    int rect2Top = rect2.y;
    int rect2Bottom = rect2.y + rect2.h;

    return rect1Bottom > rect2Top &&
        rect1Top < rect2Bottom &&
        rect1Right > rect2Left &&
        rect1Left < rect2Right;
}
