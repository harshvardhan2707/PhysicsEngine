#pragma once
class Walker
{
public:
	int x, y, WIDTH, HEIGHT;
	Walker(int WIDTH,int HEIGHT);
	void render();
	void step();
	void constraint();
};

