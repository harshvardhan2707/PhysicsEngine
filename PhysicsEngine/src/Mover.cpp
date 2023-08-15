#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <algorithm>
#include <iostream>
#include "PVector.h"
class Mover {
public:
	PVector loc, vel, acc;
	double mass;
	int WIDTH, HEIGHT;
	Mover(int WIDTH = 640, int HEIGHT = 480,double x_vel = 1, double y_vel = 1, double x_acc = 0, double y_acc = 0,double mass=1.0) {
		this->WIDTH = WIDTH;
		this->HEIGHT = HEIGHT;
		loc = PVector(double(WIDTH / 2), double(HEIGHT / 2));
		vel = PVector(x_vel, y_vel);
		acc = PVector(x_acc, y_acc);
		this->mass = mass;
	}
	void step() {
		vel = vel +acc;
		loc = loc + vel;
		acc = acc * 0;
	}
	void applyForce(PVector force) {
		PVector f = force / mass;
		acc = acc + f;
	}
	void applyForce(double x, double y) {
		applyForce(PVector(x, y));
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
		SDL_RenderDrawPoint(renderer, int(loc.x),int(loc.y));
		//SDL_RenderPresent(renderer);
		//SDL_Delay(1000);
		//SDL_RenderClear(renderer);
		constraint();
		//std::cout << speed.x << " " << speed.y << "\n";
	}
	void constraint() {
		if (loc.x > WIDTH || loc.x < 0) {
			vel.x = -vel.x;
		}
		else if (loc.y > HEIGHT || loc.y < 0) {
			vel.y = -vel.y;
		}
		loc.x = std::max(loc.x, 0.0);
		loc.x = std::min(loc.x, double(WIDTH));
		loc.y = std::max(loc.y, 0.0);
		loc.y = std::min(loc.y, double(HEIGHT));
		//speed.x = std::min(speed.x, 5.0f);
		//speed.y = std::min(speed.y, 5.0f);
	}
};