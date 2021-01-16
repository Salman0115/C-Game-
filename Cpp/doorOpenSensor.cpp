/*!
\file doorOpenSensor.cpp
*/

#include "doorOpenSensor.h"



//! constructor for the sensor
/*!
\setting the rectangle postion, size, orientation
\ setting the colour.
*/
doorOpenSensor::doorOpenSensor(b2World* world, sf::Vector2f position, sf::Vector2f size, float orientation, openingDoor* door)
{
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	m_body = world->CreateBody(&l_bodyDef);

	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;

	l_fixtureDef.density = Density;
	l_fixtureDef.friction = Friction;
	l_fixtureDef.restitution = Restitution;
	l_fixtureDef.shape = &l_shape;

	l_fixtureDef.isSensor = true; //to make it a sensor

	m_body->CreateFixture(&l_fixtureDef);

	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);
	setFillColor(sf::Color(0, 255, 0));

	m_door = door;
}

void doorOpenSensor::onAction(b2Body * other)
{
	//this is to tell what it will do once it collides with an object.
	m_door->open();
}

doorOpenSensor::~doorOpenSensor()
{
}
