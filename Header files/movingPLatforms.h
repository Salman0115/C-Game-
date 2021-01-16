/*!
\file movingPLatforms.h
*/
#pragma once
#include"SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "Col_Def.h"
class	movingPlatforms : public sf::RectangleShape, public Col_Def
{
public:
	movingPlatforms() {};
	movingPlatforms(b2World* world, const sf::Vector2f& Position, const sf::Vector2f& Size, const float& orientation, const sf::Color& Colour);//!< constructor which holds params
	void Update();
	~movingPlatforms();
};

