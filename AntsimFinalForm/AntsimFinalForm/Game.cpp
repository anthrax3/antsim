#include <SFML/Graphics.hpp>
#include "Ants.h"
#include "Game.h"


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

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Vector2D mousepos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
				Food* f = new Food(10, 80, mousepos);
				food.push_back(f);
			}

		}

		

		update();
		draw();
		
		
	}

}

void Game::draw()
{
	
	window.clear();
	for(auto a: ants)
	{
		a->draw(window);
		a->update();
	}
	for(auto f: food)
	{
		f->draw(window);
	}
	window.display();
}

void Game::update()
{
	for (auto a : ants)
	{
		for (auto f : food)
		{
			if (a->Has_food(f))
			{
				a->seeking(f);
			}
		}
	}

}

Game::Game(int width, int height)
	:
	window(sf::VideoMode(width, height), "ANTSIMULATION"),
	SCREEN_WIDTH(width),
	SCREEN_HEIGHT(height)
{
	window.setFramerateLimit(60);

	//spawn ants here
	for (int i = 0; i < 20; i++)
	{
		ants.push_back(new Ants(10, Vector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2)));
	}
	
}
