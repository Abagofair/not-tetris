#ifndef HELPER_HEADER
#define HELPER_HEADER

#include <SFML\Graphics.hpp>

enum blockType {I_Block=1, J_Block, L_Block, O_Block, S_Block, T_Block, Z_Block}; 

class Helper {
public:
	sf::Texture blueTex;
	sf::Texture greenTex;
	sf::Texture purpleTex;
	sf::Texture cyanTex;
	sf::Texture yellowTex;
	sf::Texture orangeTex;
	sf::Texture redTex;

	int LoadTextures();
};



#endif