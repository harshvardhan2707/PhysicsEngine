#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Walker.cpp"
#include <iostream>
#include "Ball.cpp"
using namespace std;
int main() {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(640 , 480 , 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 4, 4);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	Walker* w = new Walker(640/4, 480/4);
	Ball* b = new Ball(640/4, 480/4, 2, 1, 1);
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
		//SDL_RenderDrawPoint(renderer, w->x, w->y);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		b->render(renderer);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
		SDL_RenderClear(renderer);
		//w->step();
	}
	//Ball* b=new Ball()
	return 0;

}
//1