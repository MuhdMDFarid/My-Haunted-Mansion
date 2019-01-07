//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:       Kok Yi Lin, Rachel Ho, Muhammad Bin Md Farid
//  Student Number:     S10170928G, S10170615D, S10172457K

#include "MHM.h"

//=============================================================================
// Constructor
//=============================================================================
MHM::MHM()
{}

//=============================================================================
// Destructor
//=============================================================================
MHM::~MHM()
{
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void MHM::initialize(HWND hwnd)
{

	Game::initialize(hwnd); // throws GameError

	// map texture
	if (!mapTexture.initialize(graphics, MAP_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing map texture"));

	// map(floor) image
	if (!map.initialize(graphics, 0, 0, 0, &mapTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing map"));

	// assets textures
	if (!assetTexture.initialize(graphics, TEXTURE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing assets texture"));

	// key textures
	if (!keyTexture.initialize(graphics, KEY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing key texture"));

	//=============================================================================

	//Enemy textures
	if (!enemyTextures.initialize(graphics, ENEMY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy textures"));

	//player texture
	if (!playerTextures.initialize(graphics, PLAYER_TEXTURE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));


	for (int y = 0; y < MAP_ROW; y++)
	{
		for (int x = 0; x < MAP_COLUMN; x++)
		{
			char tile = tileMap[y][x];

			switch (tile)
			{
			case 0:			// empty
				break;
			case 1:			//wall
				wall = new Assets();
				if (!wall->initialize(this, TILE_SIZE, TILE_SIZE, obstaclesNS::ASSET_COLS, &assetTexture))
					throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing wall"));
				wall->setCurrentFrame(obstaclesNS::WALL_START_FRAME);
				wall->setY(y*TILE_SIZE);
				wall->setX(x*TILE_SIZE);
								
				wall->getCollisionType();
				wallList.push_back(wall);

				break;
			case 2:			//door
				if (!door.initialize(this, TILE_SIZE, TILE_SIZE, obstaclesNS::ASSET_COLS, &assetTexture))
					throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing door"));
				door.setCurrentFrame(obstaclesNS::DOOR_START_FRAME);
				door.setY(y*TILE_SIZE);
				door.setX(x*TILE_SIZE);
				door.getActive();


				break;

			case 3:			//trap
				trap = new Assets();
				if (!trap->initialize(this, TILE_SIZE, TILE_SIZE, obstaclesNS::ASSET_COLS, &assetTexture))
					throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing trap"));
				trap->setCurrentFrame(obstaclesNS::TRAP_START_FRAME);
				trap->setY(y*TILE_SIZE);
				trap->setX(x*TILE_SIZE);

				RECT r;
				r.left = -TILE_SIZE / 16 + 1;
				r.top = -TILE_SIZE / 16 + 1;
				r.right = TILE_SIZE / 16 - 1;
				r.bottom = TILE_SIZE / 16 - 1;
				trap->setEdge(r);
				trapList.push_back(trap);

				break;

			case 4:			//red slime
				slime = new Enemy();

				if (!slime->initialize(this, enemyNS::WIDTH, enemyNS::HEIGHT, enemyNS::TEXTURE_COLS, &enemyTextures))
					throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing red slime"));
				slime->setFrames(enemyNS::SLIME_RED_START_FRAME, enemyNS::SLIME_RED_END_FRAME);
				slime->setCurrentFrame(enemyNS::SLIME_RED_START_FRAME);
				slime->setY(y*TILE_SIZE);
				slime->setX(x*TILE_SIZE);
				slime->setVelocity(VECTOR2(-enemyNS::SLIME_RED_SPEED, -enemyNS::SLIME_RED_SPEED)); // VECTOR2(X, Y)

				enemyList.push_back(slime);

				slime = NULL;

				break;

			case 5:			//orange slime
				slime = new Enemy();

				if (!slime->initialize(this, enemyNS::WIDTH, enemyNS::HEIGHT, enemyNS::TEXTURE_COLS, &enemyTextures))
					throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing orange slime"));
				slime->setFrames(enemyNS::SLIME_ORANGE_START_FRAME, enemyNS::SLIME_ORANGE_END_FRAME);
				slime->setCurrentFrame(enemyNS::SLIME_ORANGE_START_FRAME);
				slime->setY(y*TILE_SIZE);
				slime->setX(x*TILE_SIZE);
				slime->setVelocity(VECTOR2(enemyNS::SLIME_ORANGE_SPEED, enemyNS::SLIME_ORANGE_SPEED)); // VECTOR2(X, Y)

				enemyList.push_back(slime);

				slime = NULL;

				break;

			case 6:			//green slime
				slime = new Enemy();

				if (!slime->initialize(this, enemyNS::WIDTH, enemyNS::HEIGHT, enemyNS::TEXTURE_COLS, &enemyTextures))
					throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing green slime"));
				slime->setFrames(enemyNS::SLIME_GREEN_START_FRAME, enemyNS::SLIME_GREEN_END_FRAME);
				slime->setCurrentFrame(enemyNS::SLIME_GREEN_START_FRAME);
				slime->setY(y*TILE_SIZE);
				slime->setX(x*TILE_SIZE);
				slime->setVelocity(VECTOR2(enemyNS::SLIME_GREEN_SPEED, enemyNS::SLIME_GREEN_SPEED)); // VECTOR2(X, Y)

				enemyList.push_back(slime);

				slime = NULL;

				break;

			case 7:			//blue slime
				slime = new Slime();

				if (!slime->initialize(this, enemyNS::WIDTH, enemyNS::HEIGHT, enemyNS::TEXTURE_COLS, &enemyTextures))
					throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing blue slime"));
				slime->setFrames(enemyNS::SLIME_BLUE_START_FRAME, enemyNS::SLIME_BLUE_END_FRAME);
				slime->setCurrentFrame(enemyNS::SLIME_BLUE_START_FRAME);
				slime->setY(y*TILE_SIZE);
				slime->setX(x*TILE_SIZE);
				slime->setVelocity(VECTOR2(-enemyNS::SLIME_BLUE_SPEED, -enemyNS::SLIME_BLUE_SPEED)); // VECTOR2(X, Y)

				enemyList.push_back(slime);

				slime = NULL;


				break;

			case 8: // key
				if (!key.initialize(this, TILE_SIZE, TILE_SIZE, obstaclesNS::ASSET_COLS, &keyTexture))
					throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing key"));
				key.setCurrentFrame(obstaclesNS::KEY_START_FRAME);
				key.setY(y*TILE_SIZE);
				key.setX(x*TILE_SIZE);

				break;

			case 9: // player
				if (!player.initialize(this, TILE_SIZE, TILE_SIZE, PlayerNS::TEXTURE_COLS, &playerTextures))
					throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));

				player.setCurrentFrame(1);
				player.setY(y*TILE_SIZE);
				player.setX(x*TILE_SIZE);
				player.setSpawn(x*TILE_SIZE, y*TILE_SIZE);

			default:
				break;
			}
		}

		
	}
	//=============================================================================


	//HUD
	if (!hudTexture.initialize(graphics, HUD_TEXTURE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing HUD textures"));

	if (!hud.initialize(this, 1, 1, 1, &hudTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing HUD"));

	//GAME OVER/VICTORY
	if (!gameoverTexture.initialize(graphics, GAME_END_SCREEN))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing GAME OVER texture"));

	if (!gameover.initialize(this->getGraphics(), GAME_WIDTH, GAME_HEIGHT, 2, &gameoverTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing GAME OVER screen"));
	gameover.setVisible(false);

	SAFE_DELETE(slime);

	//=============================================================================
	//SOUND
	mciSendString("open \"sounds\\mysticaltheme.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	//backgroundMusic = PlaySound(BACKGROUND_MUSIC, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);


	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void MHM::update()
{
	/*
	if (!backgroundMusic)
	{
		PlaySound(BACKGROUND_MUSIC, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	*/

	mciSendString("play mp3 repeat", NULL, 0, NULL);

	if (input->wasKeyPressed(VK_SPACE))
	{
		if (!player.isAlive())		//restart
		{
			player.undie();
			gameover.setVisible(false);
			key.setVisible(true);
			hud.clearObjects();
			paused = true;
			startmenu=true;
			spaceReleased = false;
		}
	}

	player.movefixed(input);
	player.update(frameTime);

	//Update enemies

	for (int a = 0; a < enemyList.size(); a++)
	{
		enemyList[a]->update(frameTime);
	}

}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void MHM::ai()
{
	
}

//=============================================================================
// Handle collisions
//=============================================================================
void MHM::collisions()
{
	VECTOR2 collisionVector;

	//if collision between slime and walls
	for (int a = 0; a < enemyList.size(); a++)
	{
		for (int b = 0; b < wallList.size(); b++)
		{
			// When slime collide to wall, bounce off.
			if (enemyList[a]->collidesWith(*wallList.at(b), collisionVector))
			{
				enemyList[a]->changeDirection(frameTime);
			}
		}
	}
	for (int a = 0; a < enemyList.size(); a++)
	{
		if (player.collidesWith(*enemyList[a], collisionVector))
		{
			player.die();
			gameover.setVisible(true);
			gameover.setCurrentFrame(1);
		}
	}

	for (int a = 0; a < trapList.size(); a++)
	{
		if (player.collidesWith(*trapList[a], collisionVector))
		{
			player.die();
			gameover.setVisible(true);
			gameover.setCurrentFrame(1);

		}
	}
	for (int a = 0; a < wallList.size(); a++)
	{
		if (player.collidesWith(*wallList[a], collisionVector))
		{

			if ((player.getCenterX() + player.getRadius()) >= wallList[a]->getCorner(0)->x && (player.getCenterX() - player.getRadius()) < wallList[a]->getCorner(0)->x)	// collide from left
			{
				if (player.getVelocity().x > 0)
					player.setX(player.getX() - player.getVelocity().x*frameTime);
			}
			if ((player.getCenterX() - player.getRadius()) <= wallList[a]->getCorner(1)->x && (player.getCenterX() + player.getRadius()) > wallList[a]->getCorner(1)->x)	// collide from right
			{
				if (player.getVelocity().x < 0)
					player.setX(player.getX() - player.getVelocity().x*frameTime);
			}

			if ((player.getCenterY() + player.getRadius()) >= wallList[a]->getCorner(1)->y && (player.getCenterY() - player.getRadius()) < wallList[a]->getCorner(1)->y)	// collide from top
			{
				if (player.getVelocity().y > 0)
					player.setY(player.getY() - player.getVelocity().y*frameTime);
			}

			if ((player.getCenterY() - player.getRadius()) <= wallList[a]->getCorner(3)->y && (player.getCenterY() + player.getRadius()) > wallList[a]->getCorner(3)->y)	// collide from bottom
			{
				if (player.getVelocity().y < 0)
					player.setY(player.getY() - player.getVelocity().y*frameTime);
			}

		}

	}

	if (player.collidesWith(key, collisionVector))		// collide with key
	{
		if (hud.getSize() < 1)		// if key not collected
		{
			hud.newhudobj(800, 642);
		}

		key.setVisible(false);
		player.setKey(true);
	}

	if (player.collidesWith(door, collisionVector))
	{
		if (player.hasKey())
		{
			player.setKey(false);
			// victory screen	
			gameover.setCurrentFrame(0);
			gameover.setVisible(true);
			////paused = true;
			//startmenu = true;
			//spaceReleased = false;
			player.die();

			hud.clearObjects();
		}
		if ((player.getCenterX() + player.getRadius()) > door.getCorner(0)->x && (player.getCenterX() - player.getRadius()) < door.getCorner(0)->x)	// collide from left
		{
			if (player.getVelocity().x > 0)
				player.setX(player.getX() - player.getVelocity().x*frameTime);
		}
		if ((player.getCenterX() - player.getRadius()) < door.getCorner(1)->x && (player.getCenterX() + player.getRadius()) > door.getCorner(1)->x)	// collide from right
		{
			if (player.getVelocity().x < 0)
				player.setX(player.getX() - player.getVelocity().x*frameTime);
		}

		if ((player.getCenterY() + player.getRadius()) > door.getCorner(1)->y && (player.getCenterY() - player.getRadius()) < door.getCorner(1)->y)	// collide from top
		{
			if (player.getVelocity().y > 0)
				player.setY(player.getY() - player.getVelocity().y*frameTime);
		}

		if ((player.getCenterY() - player.getRadius()) < door.getCorner(3)->y && (player.getCenterY() + player.getRadius()) > door.getCorner(3)->y)	// collide from top
		{
			if (player.getVelocity().y < 0)
				player.setY(player.getY() - player.getVelocity().y*frameTime);
		}
	}




}

//=============================================================================
// Render game items
//=============================================================================
void MHM::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	map.draw();	// mud ground
	door.draw(); // door
	key.draw(); // key

	for each(Assets* a in wallList) {
		a->draw();
	}

	for each(Assets* b in trapList) {
		b->draw();
	}

	//Draw enemies
	for (int a = 0; a < enemyList.size(); a++)
	{
		enemyList[a]->draw();
	}

	player.draw();
	hud.draw();
	gameover.draw();

	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void MHM::releaseAll()
{
	mapTexture.onLostDevice();
	assetTexture.onLostDevice();
	enemyTextures.onLostDevice();
	gameoverTexture.onLostDevice();
	playerTextures.onLostDevice();
	hudTexture.onLostDevice();
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void MHM::resetAll()
{
	mapTexture.onResetDevice();
	assetTexture.onResetDevice();
	enemyTextures.onResetDevice();
	gameoverTexture.onResetDevice();
	playerTextures.onResetDevice();
	hudTexture.onResetDevice();
	Game::resetAll();
	return;
}


// Delete all reserved memory.
void MHM::deleteAll()
{

	for (auto it = enemyList.begin(); it != enemyList.end(); )
	{
		if (!initialized)
		{
			SAFE_DELETE(*it);
			it = enemyList.erase(it);
		}
	}

	SAFE_DELETE(wall);
	SAFE_DELETE(trap);
	SAFE_DELETE(slime);
	releaseAll();
	Game::deleteAll();
	return;
}