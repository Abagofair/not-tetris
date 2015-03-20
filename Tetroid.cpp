#include "Tetroid.h"

void Tetroid::LoadTexture(sf::Texture &tex)
{
	block.setTexture(&tex);
}

Tetroid::Tetroid()
{
	isActive = false;
	isOld = false;
	eraseFlag = false;
}

void Tetroid::SetOld(bool yes)
{
	isOld = yes;
}

void Tetroid::SetOriginBlock(bool yes)
{
	_originBlock = yes;
}

void Tetroid::SetSize(sf::Vector2f size)
{
	blockSize = size;
	block.setSize(blockSize);
}

Tetroid::Tetroid(sf::Vector2f size, sf::Texture &tex)
{
	block.setSize(size);
	LoadTexture(tex);
}

void Tetroid::SetPosInLevel(sf::Vector2i pos)
{
	posInLevel.x = pos.x;
	posInLevel.y = pos.y;
}

sf::Vector2i Tetroid::GetPosInLevel()
{
	return posInLevel;
}

void Tetroid::Draw(sf::RenderWindow &window)
{
	window.draw(block);
}

void Tetroid::SetGlobalPos(sf::Vector2f pos)
{
	globalPos = pos;
	block.setPosition(globalPos);
}

sf::Vector2f Tetroid::GetGlobalPos()
{
	return block.getPosition();
}

void Tetroid::SetActive(bool yes)
{
	isActive = yes;
}

bool Tetroid::GetActive()
{
	return isActive;
}

bool Tetroid::IsOrigin()
{
	return _originBlock;
}

void Tetroid::Clear()
{

}