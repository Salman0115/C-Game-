/*!
\file collectibles.h
*/
#pragma once

#include "sensorShape.h"
#include <SFML/Graphics.hpp>
#include"Box2D/Box2D.h"
#include "Col_Def.h"

class collectibles : public sensorShape, public sf::CircleShape
{
private:

public:
	collectibles() {}; //!< Default constructor
	collectibles(b2World * world, sf::Vector2f position, float radius, float hieght, sf::Texture* texture); //!< constructor for coins to set texture postion etc.
	~collectibles();
	void onAction(b2Body* other);
	void offAction(b2Body* other);
	void destoryBody();

	static std::vector<collectibles*> collectiblesToRemove;
};