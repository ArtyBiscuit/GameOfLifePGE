#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class GameOfLife : public olc::PixelGameEngine
{
public:
	GameOfLife()
	{
		sAppName = "Game of Life";
	}


public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{	
		return true;
	}

	void UpdateCycle()
	{
	}
};

int main()
{
	GameOfLife game;
	if (game.Construct(256, 240, 4, 4))
		game.Start();
	return 0;
}
