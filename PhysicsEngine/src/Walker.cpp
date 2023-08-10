#include "Walker.h"
#include <iostream>

Walker::Walker(int WIDTH,int HEIGHT)
{
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	x = WIDTH/2;
	y = HEIGHT/2;
}

void Walker::render()
{
		step();
		//std::cout << x << " x " << y << " y\n";

}

void Walker::step()
{
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

void Walker::constraint()
{
	if (x >= WIDTH)x = 0;
	else if (x < 0)x = WIDTH-1;
	if (y >= HEIGHT)y = 0;
	else if (y < 0)y = HEIGHT-1;
}
//int walk() {
//	Walker* f = new Walker();
//	f->render();
//}