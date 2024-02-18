#pragma once
#include"pch.h"

class Tetromino : public sf::Drawable
{
public:
	enum type
	{
		O = 0, 
		I,
		S,
		Z,
		L,
		J,
		T,
		COUNT
	};
	enum color // Enum values are offset factor to render a tile with a certain color
	{
		Yellow = 1,
		Red,
		Green,
		Magenta,
		Orange,
		Blue,
		DarkBlue,
	};

	Tetromino(const type& type, int rotation_state = 0);
	
	//virtual void draw(sf::RenderTarget& tetramino, sf::RenderStates states = sf::RenderStates::Default) const override;

private:
	const type m_type;
	sf::Vector2i m_position;
	int m_rotation;
};

