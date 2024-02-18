#include "pch.h"
#include "Game.h"
#include"filesystem.h"

Game::Game()
	:m_window(sf::VideoMode::getDesktopMode(), "Tetris", sf::Style::Close | sf::Style::Titlebar)
{
	sf::Vector2u Window_Size = sf::Vector2u(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height) / 2u;
	m_window.setSize(Window_Size);

}

void Game::Run()
{

	TextureManager::Load("tiles", get_absolute_path("\\resources\\assets\\tiles.png"));

	tiles.setTexture(TextureManager::Get("tiles"));

	sf::Event event;
	while (m_window.isOpen()) // Game Loop
	{
		while (m_window.pollEvent(event)) // Event Handling
		{
			if (event.type == sf::Event::Closed)
				m_window.close();

			m_window.clear();
			m_window.draw(tiles);
			m_window.display();
		}
	}

}
