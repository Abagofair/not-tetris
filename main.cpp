#include <SFML\Graphics.hpp>
#include <SFML\Main.hpp>
#include <SFML\System.hpp>
#include <vector>
#include "Tetroid.h"
#include "Level.h"
#include "Helper.h"
#include "TetrisBlock.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris Copy", sf::Style::Close);

	sf::Texture backgroundTex;
	sf::Sprite background;

	if (!backgroundTex.loadFromFile("background.jpg"))
	{
		return EXIT_FAILURE;
	}

	background.setTexture(backgroundTex);
	background.setPosition(242.5, 0.0);


	Helper *help;
	Helper temp;
	help = &temp;

	if (help->LoadTextures() == EXIT_FAILURE)
		return EXIT_FAILURE;

	TetrisBlock main(&temp);

	main.CreateBlock();
	main.GetActiveBlock();

	
	while(window.isOpen())
	{
		sf::Event _event;
		while (window.pollEvent(_event))
		{
			if (_event.type == _event.Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		window.draw(background);
		main.UpdateBlocks();
		main.DrawBlocks(window);
		window.display();
	}

	return EXIT_SUCCESS;
}

