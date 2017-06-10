#include <SFML/Graphics.hpp>
#include "Ants.h"
#include "Game.h"
#include <iostream>


Game::Game(int width, int height)
	:
	window(sf::VideoMode(width, height), "ANTSIMULATION"),
	SCREEN_WIDTH(width),
	SCREEN_HEIGHT(height)
{
	window.setFramerateLimit(60);

	//spawn ants here
	for (int i = 0; i < 150; i++)
	{
		ants.push_back(new Ants(5, Vector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2)));
	}

}

void Game::gameloop()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			{
				
			}
		}

		update();
		draw();

	}

}

void Game::update()
{
	
	for (auto a : ants)
	{
		a->update(ants);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			a->applyBehaviour(ants);
		}
	}


}

void Game::drawText()
{
	using namespace sf;

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}

	Text text;
	text.setFont(font);
	text.setString("Press C to activate Flocking behaviour");
	text.setCharacterSize(20);
	text.setOrigin(0.0f, 0.0f);

	window.draw(text);
}



void Game::draw()
{
	
	window.clear();
	for(auto a: ants)
	{
		a->draw(window);
	}
	drawText();
	window.display();
}
