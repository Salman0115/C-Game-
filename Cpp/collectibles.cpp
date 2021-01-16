/*!
\file collectibles.cpp
*/
#include "collectibles.h"

std::vector<collectibles*> collectibles::collectiblesToRemove;
//! Function to set all the parameters for the coin
/*!
\setting the size position, height and texture for the coin.
*/

collectibles::collectibles(b2World* world, sf::Vector2f position, float radius, float height, sf::Texture* texture)
{
	/*Coin(world, position, radius);
	float theta = atan(radius / height);*/

	//createCoin(world, position, radius); // don't need this

	b2BodyDef l_bodyDef;
	b2CircleShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.type = b2_staticBody; // make it a static body as it's not going to move around.

	m_body = world->CreateBody(&l_bodyDef);

	l_shape.m_radius = radius;

	l_fixtureDef.density = Density;
	l_fixtureDef.friction = Friction;
	l_fixtureDef.restitution = Restitution;
	l_fixtureDef.shape = &l_shape;

	l_fixtureDef.isSensor = true; //Make it a sensor

	m_body->CreateFixture(&l_fixtureDef);

	setRadius(radius);
	setPosition(position);
	setOrigin(radius, radius);

	setTexture(texture); //set a texture so it collect coins.
}
//! Function to tell what happens on contact with an object
/*!
\ the removes the object.
*/
void collectibles::onAction(b2Body* other)
{
	//m_body->DestroyFixture();
	//m_body->GetWorld()->DestroyBody(m_body);
	setFillColor(sf::Color::Magenta);

	collectibles::collectiblesToRemove.push_back(this);
}

void collectibles::offAction(b2Body* other)
{
	setFillColor(sf::Color::Red);
}

void collectibles::destoryBody()
{
	m_body->GetWorld()->DestroyBody(m_body); // destroy this body
}

collectibles::~collectibles()
{
	//m_body->GetWorld()->DestroyBody(m_body); // destroy this body
}