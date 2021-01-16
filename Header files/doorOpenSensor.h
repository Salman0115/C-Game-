/*!
\file doorOpenSensor.h
*/
#include "openingDoor.h"
#include "sensorShape.h"

class doorOpenSensor : public sensorShape, public sf::RectangleShape
{
private:

public:
	doorOpenSensor() {}; //!< Default constructor
	doorOpenSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, openingDoor * door); //!< constructor to set param
	void onAction(b2Body * other); //!< what it will do on action when something collides with it.
	~doorOpenSensor();
	void offAction(b2Body * other) {};
	openingDoor * m_door;
};