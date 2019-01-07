//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:        Rachel Ho
//  Student Number:      S10170615D

#include "enemy.h"

//=============================================================================
// default constructor
//=============================================================================
Enemy::Enemy() : Entity()
{
	spriteData.width = enemyNS::WIDTH;           // size of enemies
	spriteData.height = enemyNS::HEIGHT;
	spriteData.x = enemyNS::X;                   // location on screen
	spriteData.y = enemyNS::Y;
	spriteData.rect.bottom = enemyNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = enemyNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = enemyNS::ENEMY_ANIMATION_DELAY;
	startFrame = enemyNS::SLIME_ORANGE_START_FRAME;     // first frame of ship animation
	endFrame = enemyNS::SLIME_ORANGE_END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	radius = (enemyNS::WIDTH - 2) / 2.0;

	mass = enemyNS::MASS;
	collisionType = entityNS::CIRCLE;


}

//=============================================================================
// Initialize the normal slime.
// Post: returns true if successful, false if failed
//=============================================================================
bool Enemy::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the enemy
//=============================================================================
void Enemy::draw()
{
	Image::draw();              // draw slime

}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Enemy::update(float frameTime)
{
	Entity::update(frameTime);




	// Bounce off walls
	if (spriteData.x > GAME_WIDTH - enemyNS::WIDTH)    // if hit right screen edge
	{
		spriteData.x = GAME_WIDTH - enemyNS::WIDTH;    // position at right screen edge
		velocity.x = -velocity.x;                   // reverse X direction

	}
	else if (spriteData.x < 0)                    // else if hit left screen edge
	{
		spriteData.x = 0;                           // position at left screen edge
		velocity.x = -velocity.x;                   // reverse X direction

	}


	spriteData.x += frameTime * velocity.x;         // move slime along X 


}


//=============================================================================
// change direction of slime
// called after collision
// updates direction and velocity, update slime's position
//=============================================================================
void Enemy::changeDirection(float frameTime)
{
	velocity.x = -velocity.x;

	spriteData.x += frameTime * velocity.x;         // move slime along X 

	return;
}




//=============================================================================
//=============================================================================
// SLIME class (free roam Blue slime)
//=============================================================================
//=============================================================================

Slime::Slime() :Enemy()
{
	spriteData.width = enemyNS::WIDTH;           // size of blue slime
	spriteData.height = enemyNS::HEIGHT;
	spriteData.x = enemyNS::X;                   // location on screen
	spriteData.y = enemyNS::Y;
	spriteData.rect.bottom = enemyNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = enemyNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = enemyNS::ENEMY_ANIMATION_DELAY;
	startFrame = enemyNS::SLIME_BLUE_START_FRAME;     // first frame of ship animation
	endFrame = enemyNS::SLIME_BLUE_START_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	radius = enemyNS::WIDTH / 2.0;

	mass = enemyNS::MASS;
	collisionType = entityNS::CIRCLE;

	count = 600;
}


//=============================================================================
// Initialize the Slime.
// Post: returns true if successful, false if failed
//=============================================================================
bool Slime::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Slime::draw()
{
	Image::draw();              // draw slime

}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Slime::update(float frameTime)
{
	Entity::update(frameTime);

	if (count != 0)
	{
		count--;
	}
	else
	{
		int choice = rand() % 4;

		switch (choice)
		{
		case 0:
			if (velocity.y < 0)
			{
				velocity.y = -velocity.y;
			}
			break;
		case 1:
			if (velocity.x < 0)
			{
				velocity.x = -velocity.x;
			}
			break;
		case 2:
			if (velocity.y > 0)
			{
				velocity.y = -velocity.y;
			}
			break;
		case 3:
			if (velocity.x > 0)
			{
				velocity.x = -velocity.x;
			}
			break;
		default:

			break;
		}

		count = 300;
	}

	spriteData.x += frameTime * velocity.x;         // move slime along X 

	spriteData.y += frameTime * velocity.y;         // move slime along Y



	if (spriteData.y < 16 * TILE_SIZE)                    // else if hit top screen edge
	{
		spriteData.y = 16 * TILE_SIZE;                           // position at top screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
		spriteData.y += frameTime * velocity.y;         // move slime along Y
	}
	


}

//=============================================================================
// change direction of slime
// called after collision
// updates direction and velocity, update slime's position
//=============================================================================
void Slime::changeDirection(float frameTime)
{
	velocity.y = -velocity.y;
	velocity.x = -velocity.x;
	spriteData.x += frameTime * velocity.x;         // move slime along X 
	spriteData.y += frameTime * velocity.y;         // move slime along Y


	return;
}

