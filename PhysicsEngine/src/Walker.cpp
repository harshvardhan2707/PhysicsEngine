//#include "Walker.h"
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>

class Walker {
public:
	int x, y, WIDTH, HEIGHT;
	Walker(int WIDTH, int HEIGHT) {
		this->WIDTH = WIDTH;
		this->HEIGHT = HEIGHT;
		x = WIDTH / 2;
		y = HEIGHT / 2;
	}
	void render(SDL_Renderer* renderer) {
		step();
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		//SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
		SDL_RenderDrawPoint(renderer, x, y);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	void step() {
		float num = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		std::cout << num << "\n";
		if (num < 0.25)x += 1;
		else if (num < 0.5)x -= 1;
		else if (num < 0.75)y += 1;
		else y -= 1;
		//std::cout << choice << "\n";
		//switch (choice)
		//{
		//case 0:x += 1; break;
		//case 1:x -= 1; break;
		//case 2:y += 1; break;
		//case 3:y -= 1; break;
		//default:
		//	break;
		//}
		constraint();
	}
	void constraint() {
		if (x >= WIDTH)x = 0;
		else if (x < 0)x = WIDTH - 1;
		if (y >= HEIGHT)y = 0;
		else if (y < 0)y = HEIGHT - 1;
	}
};
//Walker::Walker(int WIDTH,int HEIGHT)
//{
//	this->WIDTH = WIDTH;
//	this->HEIGHT = HEIGHT;
//	x = WIDTH/2;
//	y = HEIGHT/2;
//}
//
//void Walker::render(SDL_Renderer* renderer)
//{
//		step();
//		SDL_RenderDrawPoint(renderer, x, y);
//		//std::cout << x << " x " << y << " y\n";
//
//}
//
//void Walker::step()
//{
//	float num = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
//	std::cout << num << "\n";
//	if (num < 0.25)x += 1;
//	else if (num < 0.5)x -= 1;
//	else if (num < 0.75)y += 1;
//	else y -= 1;
//	//std::cout << choice << "\n";
//	//switch (choice)
//	//{
//	//case 0:x += 1; break;
//	//case 1:x -= 1; break;
//	//case 2:y += 1; break;
//	//case 3:y -= 1; break;
//	//default:
//	//	break;
//	//}
//	constraint();
//}
//
//void Walker::constraint()
//{
//	if (x >= WIDTH)x = 0;
//	else if (x < 0)x = WIDTH-1;
//	if (y >= HEIGHT)y = 0;
//	else if (y < 0)y = HEIGHT-1;
//}
////int walk() {
////	Walker* f = new Walker();
////	f->render();
////}