#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Walker.h"
#include <iostream>
using namespace std;
int main() {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(640*4 , 480*4 , 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 4, 4);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	Walker* w = new Walker(640, 480);
	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type == SDL_KEYDOWN) { // Check for key press
				quit = true;
			}
		}
		SDL_RenderDrawPoint(renderer, w->x, w->y);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
		w->step();
	}
	return 0;

}