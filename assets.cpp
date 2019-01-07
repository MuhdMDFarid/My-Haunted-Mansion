//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:       Kok Yi Lin
//  Student Number:     S10170928G

#include "assets.h"

Assets::Assets() : Entity() {
	spriteData.x = 0;
	spriteData.y = 0;
	spriteData.width = TILE_SIZE;
	spriteData.height = TILE_SIZE;
	spriteData.rect.bottom = TILE_SIZE;
	spriteData.rect.right = TILE_SIZE;
	setCurrentFrame(startFrame);
	edge.left = -15;
	edge.top = -15;
	edge.right = 15;
	edge.bottom = 15;

	mass = obstaclesNS::MASS;
	collisionType = entityNS::BOX;
}

bool Assets::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM) 
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Assets::draw()
{
	Image::draw();              // draw assets
}