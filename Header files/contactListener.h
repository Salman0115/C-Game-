#pragma once

/*!
\file contactListener.h
*/

#include <Box2D\Box2D.h>
#include "sensorShape.h"
#include "collectibles.h"


class contactListener : public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact)
	{
		b2Body* bodyA = contact->GetFixtureA()->GetBody();
		b2Body* bodyB = contact->GetFixtureB()->GetBody();

		bool isSensorA = contact->GetFixtureA()->IsSensor();
		bool isSensorB = contact->GetFixtureB()->IsSensor();

		if (isSensorA)
		{
			/*sensorShape * sensor = static_cast<sensorShape *>(bodyA->GetUserData());
			sensor->onAction(bodyB);*/

			std::pair<std::string, void*> userData = *((std::pair<std::string, void*>*) bodyA->GetUserData());
			sensorShape* sensor = static_cast<sensorShape*>(userData.second);
			sensor->onAction(bodyB);
			////collectibles* sensor;

			//// This sensor is a collectible object
			//if (userData.first == typeid(collectibles).name())
			//{
			//	//sensor = static_cast<collectibles*>(userData.second);
			//	sensor->onAction(bodyB); 
			//}

			//// This sensor is a door open sensor
			//if (userData.first == typeid(doorOpenSensor).name())
			//{
			//	//sensorShape* sensor2 = static_cast<sensorShape*>(userData.second);
			//	sensor->onAction(bodyB);
			//}


		}

		if (isSensorB)
		{
			/*sensorShape * sensor = static_cast<sensorShape *>(bodyB->GetUserData());
			sensor->onAction(bodyA);*/

			std::pair<std::string, void*> userData = *((std::pair<std::string, void*>*) bodyB->GetUserData());
			sensorShape* sensor = static_cast<sensorShape*>(userData.second);
			sensor->onAction(bodyA);
			//collectibles* sensor;

			//// This sensor is a collectible object
			//if (userData.first == typeid(collectibles).name())
			//{
			//	sensor = static_cast<collectibles*>(userData.second);
			//	sensor->onAction(bodyA);
			//}

			//// This sensor is a door open sensor
			//if (userData.first == typeid(doorOpenSensor).name())
			//{
			//	sensorShape* sensor2 = static_cast<sensorShape*>(userData.second);
			//	sensor2->onAction(bodyA);
			//}


		}

	}

	void EndContact(b2Contact* contact)
	{
		b2Body* bodyA = contact->GetFixtureA()->GetBody();
		b2Body* bodyB = contact->GetFixtureB()->GetBody();

		bool isSensorA = contact->GetFixtureA()->IsSensor();
		bool isSensorB = contact->GetFixtureB()->IsSensor();

		if (isSensorA)
		{
			std::pair<std::string, void*> userData = *((std::pair<std::string, void*>*) bodyA->GetUserData());
			sensorShape* sensor = static_cast<sensorShape*>(userData.second);
			sensor->offAction(bodyB);
			//collectibles* sensor;

			//// This sensor is a collectible object
			//if (userData.first == typeid(collectibles).name())
			//{
			//	sensor = static_cast<collectibles*>(userData.second);
			//	sensor->offAction(bodyB);
			//}

		}

		if (isSensorB)
		{
			std::pair<std::string, void*> userData = *((std::pair<std::string, void*>*) bodyB->GetUserData());
			sensorShape* sensor = static_cast<sensorShape*>(userData.second);
			sensor->offAction(bodyA);
			//collectibles* sensor;

			//// This sensor is a collectible object
			//if (userData.first == typeid(collectibles).name())
			//{
			//	sensor = static_cast<collectibles*>(userData.second);
			//	sensor->offAction(bodyA);
			//}

		}
	}
};