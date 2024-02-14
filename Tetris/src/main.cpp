#include<SFML\Graphics.hpp>

int WinMain()
{
	sf::RenderWindow window(sf::VideoMode(300, 300), "Test");

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


			window.clear(sf::Color::Magenta);
			window.display();
		}
	}

	return 0;
}