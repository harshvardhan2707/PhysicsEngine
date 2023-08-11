#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Walker.cpp"
#include <iostream>
#include "Ball.cpp"
using namespace std;
int main() {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(640 , 480 , 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 1,1);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	Walker* w = new Walker(640, 480);
	Ball* b = new Ball(640 , 480 , 10, 1.0,0.0,0.0,0.0);
	bool quit = false;
	SDL_Event e;
	int i = 255, j = 255, k = 255;
	bool pos = false;

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
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		//SDL_RenderClear(renderer);
		//if (j == 0)pos = true;
		//else if (j == 255)pos = false;
		//if (pos)j = j + 1;
		//else j = j - 1;
		////j = (j + 1) % 255;
		////k = (k + 1) % 255;
		//SDL_SetRenderDrawColor(renderer, i,j,k, 255);
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		//SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		int mouseX, mouseY;
		Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
		b->mouse_acceleration(float(mouseX), float(mouseY));
		b->render(renderer);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
		/*SDL_RenderPresent(renderer);
		SDL_Delay(10);*/
		//SDL_RenderClear(renderer);
		//w->step();
	}
	//Ball* b=new Ball()
	return 0;

}
//1