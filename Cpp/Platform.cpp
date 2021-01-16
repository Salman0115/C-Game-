/*!
\file Platform.cpp
*/
#include "Platform.h"

Platform::Platform()
{
}

Platform::Platform(b2World* world, const sf::Vector2f& Position, const sf::Vector2f& Size, const float& orientation, sf::Texture* texture)
{
	b2BodyDef bodyDef;
	b2PolygonShape m_shape;
	b2FixtureDef fixtureDef;

	m_body = world->CreateBody(&bodyDef);
	bodyDef.position.Set(Position.x, Position.y);
	bodyDef.type = b2_staticBody; // a dynamic body
	m_shape.SetAsBox(Size.x, Size.y);
	m_shape.m_radius = 0.0f;

	fixtureDef.shape = &m_shape;
	m_body->CreateFixture(&fixtureDef);
	fixtureDef.density = Density;
	fixtureDef.friction = Friction;
	fixtureDef.restitution = Restitution;



	setPosition(Position);
	setRotation(orientation);
	setSize(Size);

}


Platform::~Platform()
{
}


