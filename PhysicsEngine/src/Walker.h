#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
class Walker
{
public:
	int x, y, WIDTH, HEIGHT;
	Walker(int WIDTH,int HEIGHT);
	void render(SDL_Renderer* renderer);
	void step();
	void constraint();
};

