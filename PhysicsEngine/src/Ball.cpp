#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <algorithm>
#include <iostream>
class Ball {
public:
	int x, y, r, WIDTH, HEIGHT, x_speed, y_speed;
	Ball(int WIDTH, int HEIGHT, int R,int x_speed,int y_speed) {
		this->WIDTH = WIDTH;
		this->HEIGHT = HEIGHT;
		r = R;
		x = WIDTH / 2;
		y = HEIGHT / 2;
		this->x_speed = x_speed;
		this->y_speed = y_speed;
	}
	void render(SDL_Renderer* renderer) {
		//SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		step();
		for (int i = -r; i <= r; i++) {
			for (int j = -r; j <= r; j++) {
				if(i*i+j*j<r*r)
					SDL_RenderDrawPoint(renderer, x + i, y + j);
			}
		}
		//SDL_RenderDrawPoint(renderer, x, y);
		constraint();
	}
	void step() {
		x = x + x_speed;
		y = y + y_speed;
	}
	void constraint() {
		if (x + r > WIDTH || x - r < 0)x_speed = -x_speed;
		else if (y + r > HEIGHT || y - r < 0)y_speed = -y_speed;
		x = std::max(r, x);
		x = std::min(WIDTH - r, x);
		y = std::max(r, y);
		y = std::min(HEIGHT - r, y);
	}
};