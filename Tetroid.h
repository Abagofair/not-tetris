#ifndef TETROID_HEADER
#define TETROID_HEADER

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <string>

class Tetroid {
private:
	sf::Vector2i posInLevel;
	sf::Vector2f globalPos;
	sf::Vector2f blockSize;
	sf::Texture blockTexture;
	sf::RectangleShape block;

	

	bool _originBlock;

	bool isActive;

public:
	bool eraseFlag;

	bool isOld;
	Tetroid();
	void SetSize(sf::Vector2f size);
	void LoadTexture(sf::Texture &tex);
	Tetroid(sf::Vector2f size, sf::Texture &tex);
	sf::Vector2i GetPosInLevel();
	void SetPosInLevel(sf::Vector2i pos);
	void SetGlobalPos(sf::Vector2f pos);
	sf::Vector2f GetGlobalPos();
	void Draw(sf::RenderWindow &window);
	void SetOriginBlock(bool yes);
	void SetActive(bool yes);
	void SetOld(bool yes);
	bool GetActive();
	bool IsOrigin();

	void Clear();
};

#endif