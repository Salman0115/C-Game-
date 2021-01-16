/*!
\file Character.h
*/
#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Col_Def.h"
class Character : public sf::RectangleShape , public Col_Def
{
private:
	
	sf::RectangleShape shape;
public:
	Character() {};
	sf::Vector2f getPosition();
	Character(b2World * world, const sf::Vector2f & Position, const sf::Vector2f & Size, const float & orientation, sf::Texture* texture); //!< constructor which holds params
	void applyImpulse(b2Vec2 impulse);
	void update();



};

