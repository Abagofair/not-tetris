#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include <vector>
#include <SFML\System.hpp>
#include "Helper.h"

class Level {
private:
	std::vector< std::vector<int> > list;
	int level_max_x;
	int level_max_y;
	int x_temp;
	int y_temp;
	int placeholder;

	std::vector<sf::Vector2i> iBlockDefaultPosition;
	std::vector<sf::Vector2i> jBlockDefaultPosition;
	std::vector<sf::Vector2i> lBlockDefaultPosition;
	std::vector<sf::Vector2i> oBlockDefaultPosition;
	std::vector<sf::Vector2i> sBlockDefaultPosition;
	std::vector<sf::Vector2i> tBlockDefaultPosition;
	std::vector<sf::Vector2i> zBlockDefaultPosition;

public:
	Level(int x_max, int y_max);
	void SpawnBlock(blockType s);
	sf::Vector2i GetBlockPos();
	std::vector<sf::Vector2i> GetBlockDefaultPositions(blockType s);

};

#endif