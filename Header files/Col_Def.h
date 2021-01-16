/*!
\file Col_Def.h
*/
#pragma once
#include <Box2D/Box2D.h>
#define DEG2RAD 0.017453f
#define RAD2DEG 57.29577f
class Col_Def
{
protected:
	b2Body * m_body = nullptr;
	float Density = 1.0f; 
	float Friction = 0.1f; 
	float Restitution = 0.8f; 

public:
	void setUserData(void* Data) { //!< this is used for contact listner
		m_body->SetUserData(Data);
	}

};

