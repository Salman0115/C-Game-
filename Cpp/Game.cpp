/*!
\file Game.cpp
*/
/*!\
\this holds all the information about the game such as the size of the blocks, character, coins etc.
*/
#include "Game.h"
// update game
void Game::update(float timeStep)
{

	view.setCenter(character.getPosition()); 
	m_pWorld->Step(timeStep, velocityIterations, positionIterations);

	// Check if object needs to be removed:
	for (int i = 0; i < collectibles::collectiblesToRemove.size(); i++)
	{
		// Delete the coin
		collectibles& coinToDelete = *collectibles::collectiblesToRemove[i];
		coinToDelete.destoryBody();

		sf::Vector2f position = coinToDelete.getPosition();

		for (int i = 0; i < coins.size(); i++)
		{
			// Look at position to determine if this is the coin to delete from list
			if (coins[i].getPosition() == coinToDelete.getPosition())
			{
				coins.erase(coins.begin() + i);
				break;
			}
		}

		// Reset user data
		for (int i = 0; i < coins.size(); i++)
		{
			coins[i].setUserData(new std::pair<std::string, void*>(typeid(collectibles).name(), &coins[i]));
		}
	}
	collectibles::collectiblesToRemove.clear();



	Door.update(timeStep);

	for (auto& block : D_Block) block.Update();
	character.update();
	// Delete debug shapes
	if (m_debug) m_debugDraw.clear();
}
//! Function to draw
/*!
\ in this function I have set for loops to draw all my blocks no matter how many they are.
\ I have also set the background picture the coin picture
\ Also I have used this function to draw the door
*/

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

	target.setView(view);
	target.draw(BackPic);
	for (int i = 0; i < m_Blocks.size(); i++)
	{
		target.draw(m_Blocks[i]);
	}
	for (int i = 0; i < D_Block.size(); i++)
	{
		target.draw(D_Block[i]);
	}
	for (int i = 0; i < coins.size(); i++)
	{
		target.draw(coins[i]);
	}

	//target.draw(platform);// platform in the middle comment it out for now but will get back to it later
	target.draw(character);
	target.draw(m_Open);
	if (!m_debug) target.draw(Door);
	// Debug Draw
	if (m_debug) target.draw(m_debugDraw);
}

//! Constructor 
/*!
\ this is where I've set all my parameters. 
\ set the screen size
\ set the postion of of background
\ camera follows the player
\ set all my blocks size and postion
\
*/

Game::Game()
{
	//texture for the background
	mytexture.loadFromFile("../assets/37744.jpg");
	BackPic.setTexture(&mytexture);	// this might not work
	BackPic.setSize(sf::Vector2f(600, 400));
	BackPic.setPosition(-5, -8);
	//character.getPosition();
	//view.setCenter(character.getPosition());
	view.setCenter(sf::Vector2f(0, 0));
	view.setSize(sf::Vector2f(10.24, 8.0));
	m_pWorld = new b2World(b2Vec2(0.f, 9.81f));
	m_debugDraw.setWorld(m_pWorld);
	m_Blocks.resize(9);
	//opening door
	Door = openingDoor(m_pWorld, sf::Vector2f(13.75, 1.5), 0.f);
	//m_Open = slidingDoorOpen(m_pWorld, sf::Vector2f(0.5f, -1.0f), sf::Vector2f(0.3f * 0.5f, 0.3f * 0.5f), 0.f, &m_door);
	m_Open = doorOpenSensor(m_pWorld, sf::Vector2f(10.5f, 0.0f), sf::Vector2f(0.8f * 0.5f, 0.3f * 0.5f), 0.f, &Door);
	std::pair<std::string, void*>* userData = new std::pair<std::string, void*>(typeid(doorOpenSensor).name(), &m_Open);
	m_Open.setUserData(userData);
	//m_platforms = movingPlatforms(m_pWorld, sf::Vector2f(0,0), sf::Vector2f(10,20), 0, sf::Color::Red);
	
	//m_Blocks[4] = Block(m_pWorld, sf::Vector2f(0.f, 30.0f), sf::Vector2f(20.0, 0.25f), -15.f, sf::Color::Green);
	m_Blocks[0] = Block(m_pWorld, sf::Vector2f(95.7f, 3.0f), sf::Vector2f(200.0, 0.25f), 0.f, sf::Color::Yellow);
	m_Blocks[1] = Block(m_pWorld, sf::Vector2f(10.f, 2.6f), sf::Vector2f(1.0, 0.55f), 0.f, sf::Color::Blue);
	m_Blocks[2] = Block(m_pWorld, sf::Vector2f(	12.0f, 2.2f), sf::Vector2f(1.0, 1.35f), 0.f, sf::Color::Red);
	m_Blocks[3] = Block(m_pWorld, sf::Vector2f(19.f, 2.6f), sf::Vector2f(1.0, 0.55f), 0.f, sf::Color::Blue);
	m_Blocks[4] = Block(m_pWorld, sf::Vector2f(17.0f, 2.2f), sf::Vector2f(1.0, 1.35f), 0.f, sf::Color::Red);
	m_Blocks[5] = Block(m_pWorld, sf::Vector2f(9.17f, 0.0f), sf::Vector2f(0.35, 1.0f), 0.f, sf::Color::Blue);
	m_Blocks[6] = Block(m_pWorld, sf::Vector2f(10.0f, 0.5f), sf::Vector2f(2.0, 0.35f), 0.f, sf::Color::Yellow);
	m_Blocks[7] = Block(m_pWorld, sf::Vector2f(-4.1f, -1.0f), sf::Vector2f(0.35, 8.35f), 0.f, sf::Color::Black);
	m_Blocks[8] = Block(m_pWorld, sf::Vector2f(15.1f, -2.5f), sf::Vector2f(0.35, 8.35f), 0.f, sf::Color::Black);
	D_Block.resize(3);
	D_Block[0] = MovingBlock(m_pWorld, sf::Vector2f(6.f, 0.8f), sf::Vector2f(1.0f, 0.25f), 0.f, sf::Color::Magenta);
	D_Block[1] = MovingBlock(m_pWorld, sf::Vector2f(6.1f, 0.9f), sf::Vector2f(1.0f, 0.25f), 0.f, sf::Color::Magenta);
	D_Block[2] = MovingBlock(m_pWorld, sf::Vector2f(4.f, 1.0f), sf::Vector2f(1.0f, 0.25f), 0.f, sf::Color::Magenta);
	if (!charact.loadFromFile("C:/Users/User/aoob/Student Pack/lab code/a_CWStarter/assets/mario.png"))
	{
		//exit(0);
	}
	character = Character(m_pWorld, sf::Vector2f(0, 0), sf::Vector2f(0.5, 0.7f), 0.0f, &charact);
	if (coin.loadFromFile("C:/Users/User/aoob/Student Pack/lab code/updated code/assets/coin.png"))
	{
		//exit(0);
	}
	coins.resize(6);
	coins[0] = collectibles(m_pWorld, sf::Vector2f(15.0f, 2.0f), 0.3f, 0.5f, &coin);
	coins[1] = collectibles(m_pWorld, sf::Vector2f(16.0f, 2.0f), 0.3f, 0.5f, &coin);
	coins[2] = collectibles(m_pWorld, sf::Vector2f(19.0f, 2.0f), 0.3f, 0.5f, &coin);
	coins[3] = collectibles(m_pWorld, sf::Vector2f(20.0f, 2.0f), 0.3f, 0.5f, &coin);
	coins[4] = collectibles(m_pWorld, sf::Vector2f(21.0f, 2.0f), 0.3f, 0.5f, &coin);
	coins[5] = collectibles(m_pWorld, sf::Vector2f(22.0f, 2.0f), 0.3f, 0.5f, &coin);
	// Set the user data - This is required for collision listener

	for (int i = 0; i < coins.size(); i++)
	{
		coins[i].setUserData(new std::pair<std::string, void*>(typeid(collectibles).name(), &coins[i]));
	}
	


	
	view.setCenter(character.getPosition());
	view.setSize(sf::Vector2f(10.24, 8.0));
	m_pWorld->SetContactListener(&listener);


	//D_Block = MovingBlock(m_pWorld, sf::Vector2f(2.0f, -3.0f), sf::Vector2f(5.0f, 8.0f), 0.0f, sf::Color::Green);

}
//! Function for keypresses
/*!
\ to look at debug
\ up button for jump
*/

void Game::onKeyPress(sf::Keyboard::Key code)
{
	float desiredVel = 0;
	switch (code)
	{
	case sf::Keyboard::Tab:
		toggleDebug();
		break;
		// keyboard button for jump to apply impulse.
	case sf::Keyboard::Up:
		if (sf::Keyboard::Up)
		character.applyImpulse(b2Vec2(0, 6.0));
		break;
		//this is to make it stop.
	case sf::Keyboard::Down:
		character.applyImpulse(b2Vec2(0, 0));
	}

}



Game::~Game()
{
	delete m_pWorld;
	m_pWorld = nullptr;
}
