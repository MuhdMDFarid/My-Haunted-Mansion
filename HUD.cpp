//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:       Muhammad Bin Md Farid
//  Student Number:     S10172457K

#include "HUD.h"

HUD::HUD()
{

}

bool HUD::initialize(Game*gamePtr, int width, int height, int ncols, TextureManager*textureM)
{
	gPtr = gamePtr;
	
	//initialize all elemnents of the HUD
	if (!texture.initialize(gamePtr->getGraphics(), HUD_TEXTURE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));


	return (Image::initialize(gamePtr->getGraphics(), width, height, ncols, textureM));
}

void HUD::draw()
{
	for (int i = 0; i < objectvec.size(); i++)
	{
		objectvec[i].objimage.setX((1 + i) * 50);
		objectvec[i].objimage.setY(50);
		objectvec[i].objimage.draw();
	}

	Image::draw();
}

void HUD::update(float frameTime)
{
	// Update HUD elements
	for (int i = 0; i < objectvec.size(); i++)
	{
		objectvec[i].objimage.update(frameTime);
	}

	Image::update(frameTime);
}

bool HUD::newhudobj(int width,int height)
{
	hudobj obj;

	if (!obj.objimage.initialize(gPtr->getGraphics(), width, height, 1, &texture))
		return false;
	else
	{
		obj.objimage.setScale(0.1);
		objectvec.push_back(obj);
		return true;
	}
	
}

int HUD::getSize()
{
	return objectvec.size();
}

void HUD::updateObjects()
{
}

void HUD::clearObjects()
{
	objectvec.clear();
}
