/*!
\file MovingBlock.h
*/
#pragma once
#include"SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "Col_Def.h"
class	MovingBlock : public sf::RectangleShape, public Col_Def
{
public:
	MovingBlock() {};
	MovingBlock(b2World* world, const sf::Vector2f& Position, const sf::Vector2f& Size, const float& orientation,const sf::Color& Colour); //!< This constructors holds params that will later change in game.cpp
	void Update();
	~MovingBlock();
};

