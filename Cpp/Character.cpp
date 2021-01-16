/*!
\file Character.cpp
*/
#include "Character.h"
//! Function to get postion for the character
/*!
\ returns the position,
*/
sf::Vector2f Character::getPosition()
{
	b2Vec2 position = m_body->GetPosition();
	return sf::Vector2f(position.x, position.y);

}
//! Constructor
/*!
\ to set params for character
*/

Character::Character(b2World* world, const sf::Vector2f& Position, const sf::Vector2f& Size, const float& orientation, sf::Texture* texture)
{
	b2BodyDef bodyDef;
	b2PolygonShape m_shape;
	b2FixtureDef fixtureDef;

	bodyDef.position.Set(Position.x, Position.y);
	bodyDef.type = b2_dynamicBody; // a dynamic body
	bodyDef.fixedRotation = true;
	m_body = world->CreateBody(&bodyDef);

	m_shape.SetAsBox(Size.x * 0.5f, Size.y * 0.5f);
	m_shape.m_radius = 0.0f;

	fixtureDef.shape = &m_shape;
	fixtureDef.density = 4;
	fixtureDef.friction = Friction;
	fixtureDef.restitution = Restitution;
	m_body->CreateFixture(&fixtureDef);

	setTexture(texture);
	setPosition(Position);
	setRotation(orientation);
	setSize(Size);
	setOrigin(Size.x * 0.5f, Size.y * 0.5f);
	
}

//! Function to apply impulse.
/*!
\this is setting the linearvelocity for when the character jumps it applies it.
*/
void Character::applyImpulse(b2Vec2 impulse)
{
	m_body->SetLinearVelocity(impulse);
	shape.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
	
}
//! Function to update the the characters position and the movement of the characeter
/*!
\ made bool for left and right and used box2d documentation to implement the keyboard movement,
*/
void Character::update()
{
	b2Vec2 pos = m_body->GetPosition();
	setPosition(pos.x, pos.y);
	float dvelocity;
	bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

	if (left)
	{
		if (left) 
		{
			dvelocity = -4; 
		}
		else
		{
			dvelocity = 0;
		}
	}
	else
	{
		if (right)
			{
				dvelocity = 4;
			}
			else
			{
				dvelocity = 0;
			}
	}



	b2Vec2 vel = m_body->GetLinearVelocity();
	float velchange = dvelocity - vel.x;
	float impulse = m_body->GetMass() * velchange;
	m_body->ApplyLinearImpulse(b2Vec2(impulse, 0), m_body->GetWorldCenter(), true);
}