/*!
\file Game.h
*/
#pragma once
#include "Block.h"
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "MovingBlock.h"
#include "Character.h"
#include <vector>
#include "iostream"
#include "Platform.h"
#include "Col_Def.h"
#include "openingDoor.h"
#include "SFMLDebugDraw.h"
#include "doorOpenSensor.h"
#include "contactListener.h"
#include "movingPLatforms.h"
#include "collectibles.h"

class Game : public sf::Drawable
{
private:

	sf::Texture mytexture; //!< Texture to be used by picture
	sf::Texture coin; //!< Texture to be used for coin
	sf::RectangleShape BackPic; //!< Picture drawn to the scene
	sf::RectangleShape pic;
	sf::View view;
	int Score;
	b2World* m_pWorld = nullptr; 
	std::vector<Block> m_Blocks; //!< for static blocks
	std::vector<collectibles> coins; //!< vector for coins
	//MovingBlock D_Block;
	std::vector<MovingBlock> D_Block; //!< for dynamic blocks.
	Character character; //!< Character
	openingDoor Door; 
	doorOpenSensor m_Open;
	sf::Texture Player;
	contactListener listener;
	Platform platform;
	sf::Texture p_Texture;
	sf::Texture charact;
	int32 velocityIterations = 8;   //how strongly to correct velocity
	int32 positionIterations = 3;
	
	bool m_debug = true;// false; //!< Toggle for debug drawing
	SFMLDebugDraw m_debugDraw; //!< Box2D debug drawing
	void toggleDebug() { m_debug = !m_debug; } //!< Toggle for debug drawing
public:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< draw functions.
	Game();
	void onKeyPress(sf::Keyboard::Key code); //!< on key press function
	void update(float timestep);
	~Game();
};

