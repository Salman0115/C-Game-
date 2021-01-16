/*!
\file Block.cpp
*/
#include "Block.h"



Block::Block()
{
}

Block::Block(b2World * world, const sf::Vector2f& Position, const sf::Vector2f& Size, const float& orientation, const sf::Color& Colour)
{
	b2BodyDef bodyDef;
	b2PolygonShape m_shape;
	b2FixtureDef fixtureDef;

	bodyDef.position.Set(Position.x, Position.y);
	bodyDef.type = b2_staticBody; // a dynamic body
	m_body = world->CreateBody(&bodyDef);
	bodyDef.fixedRotation = true;
	m_shape.SetAsBox(Size.x * 0.5f, Size.y * 0.5f);
	m_shape.m_radius = 0.0f;

	fixtureDef.shape = &m_shape;
	fixtureDef.density = 5;
	fixtureDef.friction = 2;
	fixtureDef.restitution = Restitution;
	m_body->CreateFixture(&fixtureDef);

	setPosition(Position);
	setRotation(orientation);
	setSize(Size);
	setFillColor(Colour);
	setOrigin(Size.x * 0.5f, Size.y * 0.5f);

		
}

Block::~Block()
{
}
