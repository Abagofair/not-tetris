#include "Level.h"

Level::Level(int x_max, int y_max)
{
	std::vector< std::vector<int> > temp(y_max, std::vector<int>(x_max));
	list = temp;
	level_max_x = x_max;
	level_max_y = y_max;
	x_temp = 0;
	y_temp = 0;
	placeholder = 1;

	iBlockDefaultPosition.push_back(sf::Vector2i(2, 0));
	iBlockDefaultPosition.push_back(sf::Vector2i(3, 0));
	iBlockDefaultPosition.push_back(sf::Vector2i(4, 0));
	iBlockDefaultPosition.push_back(sf::Vector2i(5, 0));

	jBlockDefaultPosition.push_back(sf::Vector2i(3, 1));
	jBlockDefaultPosition.push_back(sf::Vector2i(4, 0));
	jBlockDefaultPosition.push_back(sf::Vector2i(3, 0));
	jBlockDefaultPosition.push_back(sf::Vector2i(5, 0));

	lBlockDefaultPosition.push_back(sf::Vector2i(3, 0));
	lBlockDefaultPosition.push_back(sf::Vector2i(4, 0));
	lBlockDefaultPosition.push_back(sf::Vector2i(5, 0));
	lBlockDefaultPosition.push_back(sf::Vector2i(5, 1));

	oBlockDefaultPosition.push_back(sf::Vector2i(3, 0));
	oBlockDefaultPosition.push_back(sf::Vector2i(3, 1));
	oBlockDefaultPosition.push_back(sf::Vector2i(4, 0));
	oBlockDefaultPosition.push_back(sf::Vector2i(4, 1));

	sBlockDefaultPosition.push_back(sf::Vector2i(3, 1));
	sBlockDefaultPosition.push_back(sf::Vector2i(4, 1));
	sBlockDefaultPosition.push_back(sf::Vector2i(4, 0));
	sBlockDefaultPosition.push_back(sf::Vector2i(5, 0));

	tBlockDefaultPosition.push_back(sf::Vector2i(3, 0));
	tBlockDefaultPosition.push_back(sf::Vector2i(4, 0));
	tBlockDefaultPosition.push_back(sf::Vector2i(5, 0));
	tBlockDefaultPosition.push_back(sf::Vector2i(4, 1));

	zBlockDefaultPosition.push_back(sf::Vector2i(3, 0));
	zBlockDefaultPosition.push_back(sf::Vector2i(4, 0));
	zBlockDefaultPosition.push_back(sf::Vector2i(4, 1));
	zBlockDefaultPosition.push_back(sf::Vector2i(5, 1));
}

void Level::SpawnBlock(blockType s)
{
	if (s == blockType::I_Block)
	{
		list[iBlockDefaultPosition[0].x][iBlockDefaultPosition[0].y] = blockType::I_Block;
		list[iBlockDefaultPosition[1].x][iBlockDefaultPosition[1].y] = blockType::I_Block;
		list[iBlockDefaultPosition[2].x][iBlockDefaultPosition[2].y] = blockType::I_Block;
		list[iBlockDefaultPosition[3].x][iBlockDefaultPosition[3].y] = blockType::I_Block;
	}
	else if (s == blockType::J_Block)
	{
		list[jBlockDefaultPosition[0].x][jBlockDefaultPosition[0].y] = blockType::J_Block;
		list[jBlockDefaultPosition[1].x][jBlockDefaultPosition[1].y] = blockType::J_Block;
		list[jBlockDefaultPosition[2].x][jBlockDefaultPosition[2].y] = blockType::J_Block;
		list[jBlockDefaultPosition[3].x][jBlockDefaultPosition[3].y] = blockType::J_Block;
	}
	else if (s == blockType::L_Block)
	{
		list[lBlockDefaultPosition[0].x][lBlockDefaultPosition[0].y] = blockType::L_Block;
		list[lBlockDefaultPosition[1].x][lBlockDefaultPosition[1].y] = blockType::L_Block;
		list[lBlockDefaultPosition[2].x][lBlockDefaultPosition[2].y] = blockType::L_Block;
		list[lBlockDefaultPosition[3].x][lBlockDefaultPosition[3].y] = blockType::L_Block;
	}
	else if (s == blockType::O_Block)
	{
		list[oBlockDefaultPosition[0].x][oBlockDefaultPosition[0].y] = blockType::O_Block;
		list[oBlockDefaultPosition[1].x][oBlockDefaultPosition[1].y] = blockType::O_Block;
		list[oBlockDefaultPosition[2].x][oBlockDefaultPosition[2].y] = blockType::O_Block;
		list[oBlockDefaultPosition[3].x][oBlockDefaultPosition[3].x] = blockType::O_Block;
	}
	else if (s == blockType::S_Block)
	{
		list[sBlockDefaultPosition[0].x][sBlockDefaultPosition[0].y] = blockType::S_Block;
		list[sBlockDefaultPosition[1].x][sBlockDefaultPosition[1].y] = blockType::S_Block;
		list[sBlockDefaultPosition[2].x][sBlockDefaultPosition[2].y] = blockType::S_Block;
		list[sBlockDefaultPosition[3].x][sBlockDefaultPosition[3].y] = blockType::S_Block;
	}
	else if (s == blockType::T_Block)
	{
		list[tBlockDefaultPosition[0].x][tBlockDefaultPosition[0].y] = blockType::T_Block;
		list[tBlockDefaultPosition[1].x][tBlockDefaultPosition[1].y] = blockType::T_Block;
		list[tBlockDefaultPosition[2].x][tBlockDefaultPosition[2].y] = blockType::T_Block;
		list[tBlockDefaultPosition[3].x][tBlockDefaultPosition[3].y] = blockType::T_Block;
	}
	else if (s == blockType::Z_Block)
	{
		list[zBlockDefaultPosition[0].x][zBlockDefaultPosition[0].y] = blockType::Z_Block;
		list[zBlockDefaultPosition[1].x][zBlockDefaultPosition[1].y] = blockType::Z_Block;
		list[zBlockDefaultPosition[2].x][zBlockDefaultPosition[2].y] = blockType::Z_Block;
		list[zBlockDefaultPosition[3].x][zBlockDefaultPosition[3].y] = blockType::Z_Block;
	}
}

std::vector<sf::Vector2i> Level::GetBlockDefaultPositions(blockType s)
{
	if (s == blockType::I_Block)
		return iBlockDefaultPosition;
	else if (s == blockType::J_Block)
		return jBlockDefaultPosition;
	else if (s == blockType::L_Block)
		return lBlockDefaultPosition;
	else if (s == blockType::O_Block)
		return oBlockDefaultPosition;
	else if (s == blockType::S_Block)
		return sBlockDefaultPosition;
	else if (s == blockType::T_Block)
		return tBlockDefaultPosition;
	else if (s == blockType::Z_Block)
		return zBlockDefaultPosition;
}

sf::Vector2i Level::GetBlockPos()
{
	std::vector< std::vector<sf::Vector2i> > defPos;

	for (int y = 0; y < level_max_y-1; y++)
	{
		for (int x = 0; x < level_max_x-1; x++)
		{
			
		}
	}

	return sf::Vector2i(0, 0);
}