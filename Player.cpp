//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:       Muhammad Bin Md Farid
//  Student Number:     S10172457K

#include "Player.h"
//#include "Projectile.h"

Player::Player() : Entity()
{
	
	spriteData.width = 32;
	spriteData.height = 32;
	velocity.x = 0;
	velocity.y = 0;
	radius = TILE_SIZE/2;
	mass = 0.0f;
	collisionType = entityNS::CIRCLE;
	frameDelay = 0.5f;

	//
	speed = 100;
	LWidth = 0;
	LHeight = 0;
	grid_X = 0;
	grid_Y = 0;
	alive = true;
}

void Player::draw()
{
	light.draw(light.getColorFilter());
	Image::draw(colorFilter);
}

bool Player::initialize(Game*gamePtr, int width, int height, int ncols, TextureManager*textureM)
{
	if (!lightTexture.initialize(gamePtr->getGraphics(), LIGHT_TEXTURE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

	if (!light.initialize(gamePtr->getGraphics(), LIGHT_SIZE, LIGHT_SIZE, 1, &lightTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
	
	light.setColorFilter(D3DCOLOR_ARGB(240, 0, 0, 0));
	light.setScale(0.5);

	int extendX = GAME_WIDTH;
	int extendY = GAME_HEIGHT;

	RECT rect;

	rect.left = -(GAME_WIDTH/light.getScale());
	rect.right = (GAME_WIDTH/light.getScale()) + light.getWidth();
	rect.top = -(GAME_HEIGHT/light.getScale());
	rect.bottom = (GAME_HEIGHT/light.getScale()) + light.getHeight();


	light.setSpriteDataRect(rect);

	// the Height and Width of the sprite
	LWidth = light.getSpriteDataRect().right - light.getSpriteDataRect().left;
	LHeight = light.getSpriteDataRect().bottom - light.getSpriteDataRect().top;

	setFrameDelay(0.1f);

	return (Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Player::update(float frameTime) 
{
	setX(getX() + velocity.x*frameTime);
	setY(getY() + velocity.y*frameTime);

	// to center the light to player
	light.setX(this->getX() - LWidth / 2 * light.getScale() + 0.5*TILE_SIZE);
	light.setY(this->getY() - LHeight / 2 * light.getScale() + 0.5*TILE_SIZE);

	Entity::update(frameTime);

}

void Player::movefixed(Input* i)
{
	if (alive)
	{
		velocity.x = 0;
		velocity.y = 0;

		if (i->isKeyDown(UP_KEY))
		{
			velocity.y = -speed;
			setFrames(2*PlayerNS::TEXTURE_COLS, 3*PlayerNS::TEXTURE_COLS-1);		// animation framesfor moving up
		}
		if (i->isKeyDown(DOWN_KEY))
		{
			velocity.y = speed;

			setFrames(0,PlayerNS::TEXTURE_COLS-1);
		}
		if (i->isKeyDown(LEFT_KEY))
		{
			velocity.x = -speed;

			setFrames(3*PlayerNS::TEXTURE_COLS, 4*PlayerNS::TEXTURE_COLS-1);
		}
		if (i->isKeyDown(RIGHT_KEY))
		{
			velocity.x = speed;

			setFrames(1*PlayerNS::TEXTURE_COLS, 2*PlayerNS::TEXTURE_COLS-1);
		}

		// incase walking animation has less frames
		//setFrameDelay(PlayerNS::PLAYER_MOVE_DELAY / (getEndFrame() - getStartFrame() + 1)); // for animating movement

	}
}


//void Player::setGridX(int x)
//{
//	grid_X = x;
//}
//void Player::setGridY(int y) 
//{
//	grid_Y = y;
//}

void Player::setSpawn(int x, int y)
{
	spawnx = x;
	spawny = y;
}

void Player::die()
{
	alive = false;
	active = false;
	velocity.x = 0;
	velocity.y = 0;
	Key = false;
}

void Player::undie()
{
	if(!alive)
	alive = true;
	active = true;
	setX(spawnx);
	setY(spawny);
}

void Player::setKey(bool key)
{
	Key = key;
}



