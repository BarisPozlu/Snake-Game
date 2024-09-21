#include <SDL.h>
#include "Snake.h"
#include "Apple.h"
#include "Timer.h"
#include "Collision.h"

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;
constexpr int SCREEN_FPS = 60;
constexpr float SCREEN_DELTATIME = 1000.f / SCREEN_FPS;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

void Init()
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Close()
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}

int main(int argc, char** args)
{
	Init();

	Snake snake(10, {400, 200}, Vector2D(1, 0));
	Apple apple(20);

	bool running = true;
	SDL_Event event;

	int numberOfFrames = 0;
	Timer capTimer;

	while (running)
	{
		capTimer.Start();

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}

			snake.UpdateVelocity(&event);
		}

		if (!snake.UpdatePosition(Vector2D(SCREEN_WIDTH, SCREEN_HEIGHT)) || snake.CollidingItself())
		{
			break;
		}

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(renderer, &apple.rect);

		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
		snake.Render(renderer);

		if (IsColliding(snake.GetHead(), apple.rect))
		{
			snake.Grow();
			apple.GetRandomPosition();
		}

		SDL_RenderPresent(renderer);

		numberOfFrames++;
		Uint32 timePassed = capTimer.GetTime();
		if (timePassed < SCREEN_DELTATIME)
		{
			SDL_Delay(SCREEN_DELTATIME - timePassed);
		}
	}

	Close();
	return 0;
}
