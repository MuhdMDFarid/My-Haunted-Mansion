//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:       Kok Yi Lin
//  Student Number:     S10170928G


#ifndef _ASSETS_H
#define _ASSETS_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace obstaclesNS {
	const int	WALL_START_FRAME = 1;
	const int	WALL_END_FRAME = 1;
	const int	TRAP_START_FRAME = 17;
	const int   TRAP_END_FRAME = 17;          // no animation
	const int	DOOR_START_FRAME = 8;
	const int   DOOR_END_FRAME = 8;          // no animation
	const int	ASSET_COLS = 14;
	const int	KEY_START_FRAME = 1;
	const int	KEY_END_FRAME = 1;
	const int	KEY_COLS = 4;
	const float MASS = 300.0f;
}

class Assets : public Entity
{
public:
	Assets(); // constructor
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
};
#endif