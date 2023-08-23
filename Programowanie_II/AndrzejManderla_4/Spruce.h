#pragma once
class Spruce
{
public:
	Spruce();
	void Build();

private:
	int Height, Width, Margin;
	int Branch(int x, int y, int tmp);
	void Trunk(int x, int y);
};

