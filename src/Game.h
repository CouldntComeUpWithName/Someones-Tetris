#pragma once
#include"pch.h"
#include"../utitlity/ResourceManager.h"

class Game
{
public:
	Game();
	
	void Run();
private:
	sf::RenderWindow m_window;
	
	sf::Sprite tiles;

	TextureManager m_textures;
	SoundManager m_sounds;
};

