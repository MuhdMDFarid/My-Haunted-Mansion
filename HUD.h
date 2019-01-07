//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:       Muhammad Bin Md Farid
//  Student Number:     S10172457K

#ifndef _HUD_H
#define _HUD_H
#define WIN32_LEAN_AND_MEAN

#include "constants.h"
#include "game.h"
#include "image.h"
#include "Player.h"
#include <vector>

using namespace std;

struct hudobj{
	Image objimage;
	int itemNo;
	int frame;
};

class HUD : Image
{
private:
	Game* gPtr;


	TextureManager texture;		// texture of object
	vector<hudobj> objectvec;	// objects
public:

	HUD();

	virtual bool initialize(Game*gamePtr, int width, int height, int ncols, TextureManager*textureM);

	virtual void draw();

	void update(float frameTime);

	bool newhudobj(int width, int height);

	int getSize();

	void updateObjects();

	void clearObjects();
};

#endif