#include "pch.h"
#include "Tetromino.h"

//Represents each tile position index of certain tetramino type locally on an array[4][2]
static const uint8_t figures[Tetromino::type::COUNT][4]
{
	{2,3,4,5}, //Tetromino::type::O 
	{1,3,5,7}, //Tetromino::type::I
	{2,4,5,7}, //Tetromino::type::S
	{3,4,5,6}, //Tetromino::type::Z
	{2,3,5,7}, //Tetromino::type::L
	{3,5,7,6}, //Tetromino::type::J
	{3,5,4,7}  //Tetromino::type::T
};

Tetromino::Tetromino(const type& type, int rotation_state)
	:m_type{type}, m_rotation(rotation_state)
{
	m_position = { 0, 0 };
}
