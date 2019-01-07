//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:       Muhammad Bin Md Farid
//  Student Number:     S10172457K

#ifndef _Player_H
#define _Player_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "textureManager.h"
#include "image.h"
#include "input.h"

namespace PlayerNS
{
	const int TEXTURE_COLS = 3;
	
}

class Player : public Entity
{
private:
	float speed;
	int LWidth;		//light Width
	int LHeight;	//light Height
	int grid_X;
	int grid_Y;
	bool alive;
	bool Key = false;
	TextureManager lightTexture;
	Image light;
	int spawnx;
	int spawny;

public:

	Player();

	float getSpeed() { return speed; }


	void movefixed(Input* i);

	virtual void draw();
	
	virtual bool initialize(Game*gamePtr, int width, int height, int ncols, TextureManager*textureM);

	void update(float frameTime);

	//int getGridX() { return grid_X; }

	//void setGridX(int x);

	//int getGridY() { return grid_Y; }

	//void setGridY(int y);

	void setSpawn(int x, int y);

	void die();

	void undie();

	bool isAlive() { return alive; }

	void setKey(bool key);

	bool hasKey() { return Key; }
};

#endif