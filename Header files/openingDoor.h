/*!
\file openingDoor.h
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "Col_Def.h"

class openingDoor : public sf::Drawable, public Col_Def
{
private:
	b2Body * m_leftSide;
	b2Body * m_leftDoor;
	b2Body * m_rightSide;
	b2Body * m_rightDoor;
	b2MotorJoint * m_leftMotor;
	b2MotorJoint * m_rightMotor;

	sf::RectangleShape m_side1;
	sf::RectangleShape m_side2;
	sf::RectangleShape m_door1;
	sf::RectangleShape m_door2;

	sf::Texture m_sideTex;
	sf::Texture m_doorTex;

	enum { CLOSED, OPENING, OPEN, CLOSING } m_state;
	float m_fElapsedTime;
	float m_fMotionTime;
public:
	openingDoor() {}; //!< Default constructor
	openingDoor(b2World * world, sf::Vector2f position, float angle); //!< constructor to set params
	void update(float timestep); //!< update
	void open();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< to draw the door
};