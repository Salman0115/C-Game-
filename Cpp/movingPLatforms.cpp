/*!
\file movingPlatforms.cpp
*/
#include "movingPLatforms.h"



movingPlatforms::movingPlatforms(b2World * world, const sf::Vector2f & Position, const sf::Vector2f & Size, const float & orientation, const sf::Color & Colour)
{
	b2BodyDef bodyDef;
	b2PolygonShape m_shape;
	b2FixtureDef fixtureDef;
	/*
	bodyDef.position.Set(Position.x, Position.y);
	bodyDef.type = b2_kinematicBody; // a dynamic body
	bodyDef.position.Set(0, 10);
	b2Body* kinematicBody = world->CreateBody(&bodyDef);
	kinematicBody->CreateFixture(&fixtureDef);
	

	fixtureDef.shape = &m_shape;
	fixtureDef.density = Density;
	fixtureDef.friction = Friction;
	fixtureDef.restitution = Restitution;
	m_body->CreateFixture(&fixtureDef);
	*/

	setPosition(Position);
	setRotation(orientation);
	setSize(Size);
	setFillColor(Colour);
	setOrigin(Size.x * 0.5f, Size.y * 0.5f);
}

void movingPlatforms::Update()
{
}

movingPlatforms::~movingPlatforms()
{
}
