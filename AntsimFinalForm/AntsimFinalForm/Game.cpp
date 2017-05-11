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
				window.close();

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
	food->draw(window);
	window.display();
}

void Game::update()
{
	/*for (auto i = ants.begin(); i != ants.end();)
	{
		Ants *e = *i;*/
		//if (a->Has_food(a,food))
		//{
		//	a->followtrail();
		//}

		//a->update();
	//}
}

Game::Game(int width, int height)
	:
	window(sf::VideoMode(width, height), "ANTSIMULATION"),
	SCREEN_WIDTH(width),
	SCREEN_HEIGHT(height)
{
	window.setFramerateLimit(60);

	//spawn ants here
	for (int i = 0; i < 10; i++)
	{
		ants.push_back(new Ants(10, Vector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2)));
	}
	
	//spawn food
	Vector2D fpos(0, 0);
	food = new Food(10, 10, fpos);
}
