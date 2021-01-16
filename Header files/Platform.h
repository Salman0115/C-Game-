/*!
\file Platform.h
*/
#pragma once
#pragma once
#include"SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "Col_Def.h"
class Platform : public sf::RectangleShape, public Col_Def
{
public:
	Platform();
	Platform(b2World * world, const sf::Vector2f& Position, const sf::Vector2f& Size, const float& orientation, sf::Texture* texture);
	~Platform();
};

