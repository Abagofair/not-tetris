#include "TetrisBlock.h"

TetrisBlock::TetrisBlock(Helper *p)
{
	lineClears.resize(20, std::vector<Tetroid>(10));
	//EveryBlock = temp;
	_temp = p;
	debug = 0;
	leftInput = true;
	rightInput = true;
	s = blockType::I_Block;
	//oldieBlocks.resize(9, Tetroid());


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

blockType TetrisBlock::RandomBlock()
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution_y(1, 7);
	std::uniform_int_distribution<int> distribution_x(1, 7);

	float x = 0;

	time_t seed;
	unsigned long currentTime = time(&seed);
	generator.seed(currentTime);

	x = distribution_y(generator);
	
	if (x > 7)
		x = distribution_y(generator);

	if (x == 1)
		return blockType::I_Block;
	else if (x == 2)
		return blockType::J_Block;
	else if (x == 3)
		return blockType::L_Block;
	else if (x == 4)
		return blockType::O_Block;
	else if (x == 5)
		return blockType::S_Block;
	else if (x == 6)
		return blockType::T_Block;
	else if (x == 7)
		return blockType::Z_Block;


}



void TetrisBlock::CreateBlock()
{
	std::vector<Tetroid> block(4);

	s = RandomBlock();

	for (int i = 0; i < 4; i++)
	{
		block[i].SetOriginBlock(false);
		block[i].SetSize(sf::Vector2f(30.0f, 30.0f));

		if (s == blockType::I_Block)
		{
			block[i].SetPosInLevel(iBlockDefaultPosition[i]);
			block[i].SetGlobalPos(sf::Vector2f((((1000-30)/2)/2)+(30*iBlockDefaultPosition[i].x), iBlockDefaultPosition[i].y * 30));
			_blockPos.push_back(iBlockDefaultPosition[i]);
			this->SetOrigin(sf::Vector2i(iBlockDefaultPosition[0].x, iBlockDefaultPosition[0].y));
		}
		else if (s == blockType::J_Block)
		{
			block[i].SetPosInLevel(jBlockDefaultPosition[i]);
			block[i].SetGlobalPos(sf::Vector2f((((1000-30)/2)/2)+(30*jBlockDefaultPosition[i].x), jBlockDefaultPosition[i].y * 30));
			_blockPos.push_back(jBlockDefaultPosition[i]);
			this->SetOrigin(sf::Vector2i(jBlockDefaultPosition[0].x, jBlockDefaultPosition[0].y));
		}
		else if (s == blockType::L_Block)
		{
			block[i].SetPosInLevel(lBlockDefaultPosition[i]);
			block[i].SetGlobalPos(sf::Vector2f((((1000-30)/2)/2)+(30*lBlockDefaultPosition[i].x), lBlockDefaultPosition[i].y * 30));
			_blockPos.push_back(lBlockDefaultPosition[i]);
			this->SetOrigin(sf::Vector2i(lBlockDefaultPosition[0].x, lBlockDefaultPosition[0].y));
		}
		else if (s == blockType::O_Block)
		{
			block[i].SetPosInLevel(oBlockDefaultPosition[i]);
			block[i].SetGlobalPos(sf::Vector2f((((1000-30)/2)/2)+(30*oBlockDefaultPosition[i].x), oBlockDefaultPosition[i].y * 30));
			_blockPos.push_back(oBlockDefaultPosition[i]);
			this->SetOrigin(sf::Vector2i(oBlockDefaultPosition[0].x, oBlockDefaultPosition[0].y));
		}
		else if (s == blockType::S_Block)
		{
			block[i].SetPosInLevel(sBlockDefaultPosition[i]);
			block[i].SetGlobalPos(sf::Vector2f((((1000-30)/2)/2)+(30*sBlockDefaultPosition[i].x), sBlockDefaultPosition[i].y * 30));
			_blockPos.push_back(sBlockDefaultPosition[i]);
			this->SetOrigin(sf::Vector2i(sBlockDefaultPosition[1].x, sBlockDefaultPosition[1].y));
		}
		else if (s == blockType::T_Block)
		{
			block[i].SetPosInLevel(tBlockDefaultPosition[i]);
			block[i].SetGlobalPos(sf::Vector2f((((1000-30)/2)/2)+(30*tBlockDefaultPosition[i].x), tBlockDefaultPosition[i].y * 30));
			_blockPos.push_back(tBlockDefaultPosition[i]);
			this->SetOrigin(sf::Vector2i(tBlockDefaultPosition[1].x, tBlockDefaultPosition[1].y));
		}
		else if (s == blockType::Z_Block)
		{
			block[i].SetPosInLevel(zBlockDefaultPosition[i]);
			block[i].SetGlobalPos(sf::Vector2f((((1000-30)/2)/2)+(30*zBlockDefaultPosition[i].x), zBlockDefaultPosition[i].y * 30));
			_blockPos.push_back(zBlockDefaultPosition[i]);
			this->SetOrigin(sf::Vector2i(zBlockDefaultPosition[1].x, zBlockDefaultPosition[1].y));
		}


		if (_blockPos[i] == _origin)
			block[i].SetOriginBlock(true);


		if (s == blockType::I_Block)
			block[i].LoadTexture(_temp->cyanTex);
		else if (s == blockType::J_Block)
			block[i].LoadTexture(_temp->blueTex);
		else if (s == blockType::L_Block)
			block[i].LoadTexture(_temp->orangeTex);
		else if (s == blockType::O_Block)
			block[i].LoadTexture(_temp->yellowTex);
		else if (s == blockType::S_Block)
			block[i].LoadTexture(_temp->greenTex);
		else if (s == blockType::T_Block)
			block[i].LoadTexture(_temp->purpleTex);
		else if (s == blockType::Z_Block)
			block[i].LoadTexture(_temp->redTex);

		block[i].SetActive(true);
	}
	_blockPos.clear();
	this->EveryBlock.push_back(block);
}

void TetrisBlock::Input()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && leftInput != false)
	{
		Movement(1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && rightInput != false)
	{
		Movement(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Movement(3);
	}
	
}

void TetrisBlock::Movement(int move)
{
	timeElapsed_pos_x = clock_pos_x.getElapsedTime();

	if (timeElapsed_pos_x.asSeconds() >= 0.09f && ActiveBlocks[0].GetActive() == true)
	{
		MoveBlock(move);
	}
	
	if (timeElapsed_pos_x.asSeconds() >= 0.09f && move == 3)
	{
		if (s != blockType::O_Block)
			RotateBlock();
	}

	clock_pos_x.restart();
}

void TetrisBlock::MoveEveryBlockOne(int _y)
{

	int temp_x = 0;
	int temp_y = 0;
	
	for (int y = 0; y < EveryBlock.size(); y++)
	{
		for (int x = 0; x < EveryBlock[y].size(); x++)
		{
			if (EveryBlock[y][x].GetPosInLevel().y < _y && EveryBlock[y][x].eraseFlag == true)
			{
				temp_x = EveryBlock[y][x].GetPosInLevel().x;
				temp_y = EveryBlock[y][x].GetPosInLevel().y;

				temp_y += 1;

				lineClears[temp_y-1][temp_x].isOld = false;
				lineClears[temp_y][temp_x].isOld = true;

				EveryBlock[y][x].SetPosInLevel(sf::Vector2i(temp_x, temp_y));
				EveryBlock[y][x].SetGlobalPos(sf::Vector2f((((1000-30)/2)/2)+(30*temp_x), temp_y * 30));
			}
		}
	}

}

void TetrisBlock::EraseLine(std::vector<sf::Vector2i> _temp)
{
	
	for (int i = 0; i < _temp.size(); i++)
	{
		for (int y = 0; y < EveryBlock.size(); y++)
		{
			for (int x = 0; x < EveryBlock[y].size(); x++)
			{
				if (EveryBlock[y][x].GetPosInLevel().x == _temp[i].x && EveryBlock[y][x].GetPosInLevel().y == _temp[i].y)
				{
					EveryBlock[y].erase(EveryBlock[y].begin() + x);
				}
			}
		}
	}
}

void TetrisBlock::RemoveLine(int y)
{
	std::vector<sf::Vector2i> temp;	
	
	for (int i = 0; i < lineClears[y].size(); i++)
	{
		lineClears[y][i].isOld = false;
		temp.push_back(sf::Vector2i(lineClears[y][i].GetPosInLevel().x, lineClears[y][i].GetPosInLevel().y)); 
	}

	EraseLine(temp);
	MoveEveryBlockOne(y);
}

void TetrisBlock::ClearLine()
{
	int block_count = 0;
	for (int y = 0; y < 20; y++)
	{
		block_count = 0;
		for (int x = 0; x < 10; x++)
		{		
			if (lineClears[y][x].isOld == true)
				block_count++;
			else
				break;

			if  (block_count == 10)
			{
				debug++;
				block_count = 0;	
				RemoveLine(y);
			}
		}
		
	}
}

//void TetrisBlock::RotateBlock()
//{
//	int x_ori, y_ori;
//
//	for (int i = 0; i < ActiveBlocks.size(); i++)
//	{
//		if (ActiveBlocks[i].IsOrigin() == true)
//		{
//			x_ori = ActiveBlocks[i].GetPosInLevel().x;
//			y_ori = ActiveBlocks[i].GetPosInLevel().y;
//		}
//	}
//
//	for (int i = 0; i < ActiveBlocks.size(); i++)
//	{
//		int x = ActiveBlocks[i].GetPosInLevel().x;
//		int y = ActiveBlocks[i].GetPosInLevel().y;
//
//		x -= x_ori;
//		y -= y_ori;
//
//		float angle = 90.0f;
//
//		float rad_angle = angle*(M_PI/180);
//
//		int new_x = (x*std::cos(rad_angle)) - (y*std::sin(rad_angle));
//		int new_y = (y*std::cos(rad_angle)) + (x*std::sin(rad_angle));
//
//		x = x_ori + new_x;
//		y = y_ori + new_y;
//
//		if (i >= 1)
//		{
//			if (x == ActiveBlocks[i-1].GetPosInLevel().x && y == ActiveBlocks[i-1].GetPosInLevel().y)
//			{
//				x -= x_ori;
//				y -= y_ori;
//
//				int new_x = (x*std::cos(rad_angle)) - (y*std::sin(rad_angle));
//				int new_y = (y*std::cos(rad_angle)) + (x*std::sin(rad_angle));
//
//				x = x_ori + new_x;
//				y = y_ori + new_y;
//
//			}
//		}
//
//
//		ActiveBlocks[i].SetPosInLevel(sf::Vector2i(x, y));
//		//ActiveBlocks[i].SetGlobalPos(sf::Vector2f((((1000-30.0f)/2)/2)+(new_x*30.0f), new_y*30.0f));
//	}
//
//}

void TetrisBlock::RotateBlock()
{
	std::vector<sf::Vector2i> temp;
	std::vector<sf::Vector2i> oldTemp;

	int x_ori = 0, y_ori = 0;
	for(int i = 0; i < ActiveBlocks.size(); i++)
	{
		if (ActiveBlocks[i].IsOrigin() == true)
		{
			x_ori = ActiveBlocks[i].GetPosInLevel().x;
			y_ori = ActiveBlocks[i].GetPosInLevel().y;
		}
	}

	for (int i = 0; i < ActiveBlocks.size(); i++)
	{
		int x = ActiveBlocks[i].GetPosInLevel().x;
		int y = ActiveBlocks[i].GetPosInLevel().y;

		oldTemp.push_back(sf::Vector2i(x, y));

		x -= x_ori;
		y -= y_ori;

		int new_x = -y;
		int new_y = x;

		x = x_ori + new_x;
		y = y_ori + new_y;

		temp.push_back(sf::Vector2i(x, y));
	}

	if (RotateCollision(temp) == false)
	{
		Move(temp);
	}
	else
	{
		Move(oldTemp);
	}

}

void TetrisBlock::SetOrigin(sf::Vector2i origin)
{
	_origin = origin;
}

void TetrisBlock::BoundsCheck()
{

	for (int i = 0; i < ActiveBlocks.size(); i++)
	{
		sf::Vector2i tempPos = ActiveBlocks[i].GetPosInLevel();

		if (((tempPos.y) == 20))
		{
			DeActivateBlock();
			SpawnBlock();
		}

	}

}

int TetrisBlock::BlockPosition()
{
	for (int i = 0; i < ActiveBlocks.size(); i++)
	{
		float param = ActiveBlocks[i].GetPosInLevel().x;

		if (param <= 0)
		{
			return 1;
		}
		else if (param >= 9)
		{
			return 2;
		}
	}

	return 0;
}

void TetrisBlock::GetActiveBlock()
{
	for (int y = 0; y < this->EveryBlock.size(); y++)
	{
		for (int x = 0; x < EveryBlock[y].size(); x++)
		{
			if (this->EveryBlock[y][x].GetActive() == true)
			{
				datY = y;
				ActiveBlocks.push_back(EveryBlock[y][x]);
			}
		}
	}
}

void TetrisBlock::DeActivateBlock()
{
	for (int i = 0; i < ActiveBlocks.size(); i++)
	{
		ActiveBlocks[i].SetActive(false);
		ActiveBlocks[i].isOld = true;
		ActiveBlocks[i].eraseFlag = true;
		lineClears[ActiveBlocks[i].GetPosInLevel().y][ActiveBlocks[i].GetPosInLevel().x] = ActiveBlocks[i];
	}
}

void TetrisBlock::ClearActiveBlock()
{
	ActiveBlocks.clear();
}

void TetrisBlock::ChangeActiveBlock()
{
	for (int i = 0; i < ActiveBlocks.size(); i++)
	{
		EveryBlock[EveryBlock.size()-1][i] = ActiveBlocks[i];
	}
}

void TetrisBlock::SpawnBlock()
{
	this->ChangeActiveBlock();
	this->ClearActiveBlock();
	this->CreateBlock();
	this->GetActiveBlock();
}

bool TetrisBlock::RotateCollision(std::vector<sf::Vector2i> _temp)
{
	int x = _temp[0].x;
	for (int i = 0; i < _temp.size(); i++)
	{
		if (Collision(_temp[i].x, _temp[i].y) == true)
			return true;
	}

	return false;
}

bool TetrisBlock::Collision(int x, int y)
{

	if (x < 0)
		return true;
	else if (y > 19)
		return true;
	else if (x > 9)
		return true;

	if (lineClears[y][x].isOld == true)
	{
		return true;
	}
	
	
	return false;
}

void TetrisBlock::Move(std::vector<sf::Vector2i> temp)
{
	for (int i = 0; i < ActiveBlocks.size(); i++)
	{
		ActiveBlocks[i].SetPosInLevel(temp[i]);
		ActiveBlocks[i].SetGlobalPos(sf::Vector2f((((1000-30)/2)/2)+(30*temp[i].x), temp[i].y * 30));
	}
}

void TetrisBlock::MoveBlock(int move)
{
	std::vector<sf::Vector2i> temp;
	for (int i = 0; i < ActiveBlocks.size(); i++)
	{
		pos = ActiveBlocks[i].GetPosInLevel();

		if (move == 1 && ActiveBlocks[i].GetActive() == true)
			pos.x -= 1;
		else if (move == 2 && ActiveBlocks[i].GetActive() == true)
			pos.x += 1;

		if (Collision(pos.x, pos.y) == true)
		{
			DeActivateBlock();
			SpawnBlock();
		}
		else
		{
			temp.push_back(pos);
		}	
	}

	if (temp.size() == 4)
		Move(temp);

}

void TetrisBlock::MoveBlockY()
{
	std::vector<sf::Vector2i> temp;
	for (int i = 0; i < ActiveBlocks.size(); i++)
	{
		pos = ActiveBlocks[i].GetPosInLevel();

		if (ActiveBlocks[i].GetActive() == true)
			pos.y += 1;

		if (Collision(pos.x, pos.y) == true)
		{
			DeActivateBlock();
			SpawnBlock();
		}
		else
		{
			temp.push_back(pos);
		}	
		
	}

	if (temp.size() == 4)
		Move(temp);

}

void TetrisBlock::UpdateBlocks()
{
	timeElapsed_pos_y = clock_pos_y.getElapsedTime();
	
	if (BlockPosition() == 1)
		leftInput = false;
	else
		leftInput = true;

	if (BlockPosition() == 2)
		rightInput = false;
	else
		rightInput = true;

	if (timeElapsed_pos_y.asSeconds() >= 0.25f)
	{
		if (ActiveBlocks[0].GetActive() == true)
		{
			MoveBlockY();
			BoundsCheck();
		}


		clock_pos_y.restart();
	}
	else
	{
		Input();
	}
	
	ClearLine();
	ChangeActiveBlock();
}

void TetrisBlock::DrawBlocks(sf::RenderWindow &window)
{

	if (this->EveryBlock.size() <= 1)
	{
		for (int y = 0; y < 1; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				this->EveryBlock[y][x].Draw(window);
			}
		}
	}
	else
	{
		for (int y = 0; y < this->EveryBlock.size(); y++)
		{
			for (int x = 0; x < EveryBlock[y].size(); x++)
			{
				if (EveryBlock[y].size() > 0)
					this->EveryBlock[y][x].Draw(window);
			}
		}
	}

}
