#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <algorithm>
#include <iostream>
#include "PVector.h"
class Ball {
public:
	PVector location, speed, acceleration;
	int WIDTH, HEIGHT, R;
	Ball(int WIDTH=640, int HEIGHT=480, int R=0,double x_speed=0, double y_speed=0, double x_acc=0, double y_acc=0) {
		this->WIDTH = WIDTH;
		this->HEIGHT = HEIGHT;
		location = PVector(double(WIDTH / 2), double(HEIGHT / 2));
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
		SDL_RenderDrawPoint(renderer, int(location.x),int(location.y));
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
	void mouse_acceleration(float a,float b) {
		PVector direction = PVector(a, b);
		direction =direction- location;
		direction = direction.normalize();
		//speed = direction;
	}
	void constraint() {
		if (location.x > WIDTH || location.x < 0) {
			speed.x = -speed.x; std::cout << speed.x << " "<<speed.y << "\n";
		}
		else if (location.y > HEIGHT || location.y < 0) {
			speed.y = -speed.y; std::cout << speed.x << " " << speed.y << "\n";
		}
		location.x = std::max(location.x, 0.0);
		location.x = std::min(location.x, double(WIDTH));
		location.y = std::max(location.y, 0.0);
		location.y = std::min(location.y, double(HEIGHT));
		//speed.x = std::min(speed.x, 5.0f);
		//speed.y = std::min(speed.y, 5.0f);
	}
};