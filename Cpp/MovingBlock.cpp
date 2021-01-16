/*!
\file MovingBlock.cpp
*/
#include "MovingBlock.h"



MovingBlock::MovingBlock(b2World * world, const sf::Vector2f& Position, const sf::Vector2f& Size, const float& orientation, const sf::Color& Colour)
{
	b2BodyDef bodyDef;
	b2PolygonShape m_shape;
	b2FixtureDef fixtureDef;

	bodyDef.position.Set(Position.x, Position.y);
	bodyDef.type = b2_dynamicBody; // a dynamic body
	m_body = world->CreateBody(&bodyDef);
	

	m_shape.SetAsBox(Size.x * 0.5f, Size.y * 0.5f);
	m_shape.m_radius = 0.0f;

	fixtureDef.shape = &m_shape;
	fixtureDef.density = Density;
	fixtureDef.friction = Friction;
	fixtureDef.restitution = Restitution;
	m_body->CreateFixture(&fixtureDef);

	setPosition(Position);
	setRotation(orientation);
	setSize(Size);
	setFillColor(Colour);
	setOrigin(Size.x * 0.5f, Size.y * 0.5f);

}
void MovingBlock::Update()
{
	b2Vec2 pos = m_body->GetPosition();
	setPosition(pos.x, pos.y);
}


MovingBlock::~MovingBlock()
{
	
}
