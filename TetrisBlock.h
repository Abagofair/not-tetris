#ifndef TETRISBLOCK_HEADER
#define TETRISBLOCK_HEADER
#define _USE_MATH_DEFINES

#define MAX_AMOUNT_OF_BLOCKS 50
#define MAX_AMOUNT_OF_TETROIDS_IN_A_BLOCK 4

#include <vector>
#include "Tetroid.h"
#include "Helper.h"
#include "Level.h"
#include <math.h>
#include <random>
#include <time.h>

class TetrisBlock {
private:
	sf::Clock clock_pos_y;
	sf::Time timeElapsed_pos_y;

	sf::Clock clock_pos_x;
	sf::Time timeElapsed_pos_x;

	sf::Vector2i _origin;

	std::vector<Tetroid> ActiveBlocks;

	std::vector<sf::Vector2i> iBlockDefaultPosition;
	std::vector<sf::Vector2i> jBlockDefaultPosition;
	std::vector<sf::Vector2i> lBlockDefaultPosition;
	std::vector<sf::Vector2i> oBlockDefaultPosition;
	std::vector<sf::Vector2i> sBlockDefaultPosition;
	std::vector<sf::Vector2i> tBlockDefaultPosition;
	std::vector<sf::Vector2i> zBlockDefaultPosition;
	int debug;
	std::vector<sf::Vector2i> _blockPos;
	std::vector<std::vector<Tetroid>> lineClears;
	std::vector<Tetroid> oldBlockPos;

	int yToClear;

	Helper *_temp;
	blockType s;

	sf::Vector2i pos;
	int datY;

	bool leftInput;
	bool rightInput;

public:
	std::vector<std::vector<Tetroid>> EveryBlock;
	TetrisBlock(Helper *temp);

	bool RotateCollision(std::vector<sf::Vector2i> _temp);
	void Move(std::vector<sf::Vector2i> temp);
	void CreateBlock();
	void UpdateBlocks();
	void Input();
	void DrawBlocks(sf::RenderWindow &window);
	void BoundsCheck();
	void GetActiveBlock();
	void ClearActiveBlock();
	void DeActivateBlock();
	void ChangeActiveBlock();
	void MoveBlock(int move);
	void Movement(int move);
	void ChangeBlockPos();
	void RemoveLine(int y);
	void EraseLine(std::vector<sf::Vector2i> _temp);
	void MoveEveryBlockOne(int _y);

	void EraseBlocks(int y);

	void ClearLine();

	blockType RandomBlock();

	void SpawnBlock();

	void RotateBlock();

	void SetOrigin(sf::Vector2i origin);

	int BlockPosition();

	void Collision();
	bool Collision(int x, int y);

	void MoveBlockY();

};

#endif