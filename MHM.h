//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:       Kok Yi Lin, Rachel Ho, Muhammad Bin Md Farid
//  Student Number:     S10170928G, S10170615D, S10172457K

#ifndef _MHM_H             // Prevent multiple definitions if this 
#define _MHM_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "assets.h"
#include "enemy.h"
#include "Player.h"
#include "HUD.h"
#include <vector>



//=============================================================================
// This class is the core of the game
//=============================================================================
class MHM : public Game
{
private:
    // game items

	// map
	TextureManager mapTexture;		// background texture
	Image map;

	// assets
	TextureManager assetTexture, keyTexture;
	Assets door, key;
	std::vector<Assets*> wallList;
	std::vector<Assets*> trapList;
	Assets* wall = NULL;
	Assets* trap = NULL;

	// enemy
	TextureManager enemyTextures;	//enemy texture


	std::vector<Enemy*> enemyList;
	Enemy* slime = NULL;

	TextureManager playerTextures;
	Player player;

	TextureManager hudTexture;
	HUD hud;

	TextureManager gameoverTexture;
	Image gameover;

	bool backgroundMusic;

	//map [y] [x]
	//0 - Empty
	//1 - Wall
	//2 - Door
	//3 - Trap
	//4 - Red slime
	//5 - Orange slime
	//6 - Green slime
	//7 - Blue slime
	//8 - key
	//9 - player
	char tileMap [24][32]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,9,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,8,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,4,0,0,1,1,1,1,1,0,0,4,0,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,3,0,0,0,0,0,0,0,0,1,1,1,1,1,0,3,0,0,0,0,0,3,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,3,0,0,0,0,0,1,1,1,1,1,0,0,0,0,3,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,5,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,5,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,3,0,0,0,0,0,0,0,0,3,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,3,0,0,0,3,0,0,0,3,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,3,3,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

public:
    // Constructor
    MHM();

    // Destructor
    virtual ~MHM();

    // Initialize the game
    void initialize(HWND hwnd);
    void update();      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();
	void deleteAll();
};

#endif
