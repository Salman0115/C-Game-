/*!
\file sensorShape.h
*/
#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Col_Def.h"

class sensorShape : public Col_Def
{
public:
	//void Rectangle(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation);
	//void createCoin(b2World * world, sf::Vector2f position, float radius);
	virtual void onAction(b2Body * other) = 0; //!< Thing the sensor does when hit
	virtual void offAction(b2Body * other) = 0; //!< Thing the sensor does when hit stops

};