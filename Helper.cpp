#include "Helper.h"

int Helper::LoadTextures()
{
	if (!this->blueTex.loadFromFile("blue_block.jpg"))
	{
		return EXIT_FAILURE;
	}

	if (!this->greenTex.loadFromFile("green_block.jpg"))
	{
		return EXIT_FAILURE;
	}

	if (!this->purpleTex.loadFromFile("purple_block.jpg"))
	{
		return EXIT_FAILURE;
	}

	if (!this->yellowTex.loadFromFile("yellow_block.jpg"))
	{
		return EXIT_FAILURE;
	}

	if (!this->cyanTex.loadFromFile("cyan_block.jpg"))
	{
		return EXIT_FAILURE;
	}
	
	if (!this->orangeTex.loadFromFile("orange_block.jpg"))
	{
		return EXIT_FAILURE;
	}

	if (!this->redTex.loadFromFile("red_block.jpg"))
	{
		return EXIT_FAILURE;
	}
}