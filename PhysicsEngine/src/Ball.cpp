#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <algorithm>
#include <iostream>
#include "PVector.cpp"
class Ball {
public:
	PVector location, speed, acceleration;
	int WIDTH, HEIGHT, R;
	Ball(int WIDTH=640, int HEIGHT=480, int R=0,float x_speed=0,float y_speed=0,float x_acc=0,float y_acc=0) {
		this->WIDTH = WIDTH;
		this->HEIGHT = HEIGHT;
		location = PVector(float(WIDTH / 2), float(HEIGHT / 2));
		speed = PVector(x_speed, y_speed);
		this->R = R;
		acceleration = PVector(x_acc, y_acc);
	}
	void render(SDL_Renderer* renderer) {
		//SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		//for (float i = -R; i <= R; i += 0.1) {
		//	for (float j = -R; j <= R; j += 0.1) {
		//		if (i * i + j * j <= R * R)SDL_RenderDrawPoint(renderer, location.x + i, location.y + j);
		//	}
		//}
		step();
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		//SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
		SDL_RenderDrawPoint(renderer, location.x,location.y);
		//SDL_RenderPresent(renderer);
		//SDL_Delay(1000);
		//SDL_RenderClear(renderer);
		constraint();
		//std::cout << speed.x << " " << speed.y << "\n";
	}
	void step() {
		speed = speed + acceleration;
		location = location + speed;
	}
	void constraint() {
		if (location.x > WIDTH || location.x < 0) {
			speed.x = -speed.x; std::cout << speed.x << " "<<speed.y << "\n";
		}
		else if (location.y > HEIGHT || location.y < 0) {
			speed.y = -speed.y; std::cout << speed.x << " " << speed.y << "\n";
		}
		location.x = std::max(location.x, 0.0f);
		location.x = std::min(location.x, float(WIDTH));
		location.y = std::max(location.y, 0.0f);
		location.y = std::min(location.y, float(HEIGHT));
	}
};