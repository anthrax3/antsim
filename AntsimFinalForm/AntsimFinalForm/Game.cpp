#include "Game.h"
#include "Vector2D.h"
#include "Ants.h"
#include "Food.h"

#include <string>
#include <sstream>
#include <stdlib.h>

#define ANT_COUNT 100


Game::Game(int w, int h)
	:
	window(sf::VideoMode(w, h), "swarm intelligence"),
	Screen_width(w),
	Screen_height(h)
	
{
	window.setFramerateLimit(60);
	m_Background.loadFromFile("images/background.jpg");
	m_Background.setSmooth(true);
	Background.setTexture(m_Background);
	//create  AI ants
	for (int i = 0; i < ANT_COUNT; i++)
	{
		ants.push_back(new Ants(this));
	}


}

Game::~Game()
{
	while (ants.size() > 0)
	{
		delete ants.back();
		ants.pop_back();
	}
}

void Game::gameloop()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//close window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		update();
		draw();
	}
}

void Game::update()
{
	for (int i = 0; i < ants.size(); i++)
	{
		ants[i]->update();
	}

}

void Game::draw()
{
	window.clear();
	window.draw(Background);

	for (int i = 0; i < ants.size(); i++)
	{
		ants[i]->draw();
	}
	
	
	window.display();
}
