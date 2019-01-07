//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:       Rachel Ho
//  Student Number:     S10170615D

#ifndef _ENEMY_H                 // Prevent multiple definitions if this 
#define _ENEMY_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace enemyNS
{
	const int WIDTH = 32;                   // image width
	const int HEIGHT = 32;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float MASS = 300.0f;              // mass
	const int   TEXTURE_COLS = 3;           // texture has 3 columns
	//orange slime
	const float SLIME_ORANGE_SPEED = 128;                // 128 pixels per second
	const int   SLIME_ORANGE_START_FRAME = 0;      // slime1 starts at frame 0
	const int   SLIME_ORANGE_END_FRAME = 2;        // slime1 animation frames 0,1,2
	//red slime
	const float SLIME_RED_SPEED = 64;                // 64 pixels per second
	const int   SLIME_RED_START_FRAME = 3;      // slime2 starts at frame 3
	const int   SLIME_RED_END_FRAME = 5;       // slime2 animation frames 3,4,5
	//green slime
	const float SLIME_GREEN_SPEED = 192;                // 192 pixels per second
	const int   SLIME_GREEN_START_FRAME = 6;      // slime3 starts at frame 6
	const int   SLIME_GREEN_END_FRAME = 8;       // slime3 animation frames 6,7,8
	//blue slime
	const float SLIME_BLUE_SPEED = 50;                // 256 pixels per second
	const int   SLIME_BLUE_START_FRAME = 9;      // slime4 starts at frame 9
	const int   SLIME_BLUE_END_FRAME = 11;       // slime4 animation frames 9,10,11
	//mushroom mob

	//
	const float ENEMY_ANIMATION_DELAY = 0.2f;    // time between frames
}

// inherits from Entity class
class Enemy : public Entity
{
private:
	
public:
	// constructor
	Enemy();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	virtual void update(float frameTime);

	virtual void changeDirection(float frameTime);



};

//inherits from Enemy class
class Slime :public Enemy
{
private:
	int count;

public:
	//Constructor
	Slime();

	//inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	//after collision
	virtual void changeDirection(float frameTime);
};

#endif


