//  Module:             Gameplay Programming
//  Assignment1:        My Haunted Mansion
//  Student Name:       Kok Yi Lin, Rachel Ho
//  Student Number:     S10170928G, S10170615D

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(255,255,0,255)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "My Haunted Mansion";
const char GAME_TITLE[] = "My Haunted Mansion";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH =  1024;               // width of game in pixels
const UINT GAME_HEIGHT = 768;               // height of game in pixels
//512x512

// game
const double PI = 3.14159265;
const float FRAME_RATE = 200.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const float GRAVITY = 6.67428e-11f;             // gravitational constant

const int TILE_SIZE = 32;
const int LIGHT_SIZE = 512;
const int MAP_COLUMN = (GAME_WIDTH / TILE_SIZE);
const int MAP_ROW = (GAME_HEIGHT / TILE_SIZE);

// graphic images

const char TEXTURE_IMAGE[] = "pictures\\rothens_tiles_2.png";
const char MAP_IMAGE[] = "pictures\\levelone.png";
const char KEY_IMAGE[] = "pictures\\keys.png";
const char ENEMY_IMAGE[] = "pictures\\enemysprites.png";		// enemies textures
const char PLAYER_TEXTURE[] = "pictures\\Player.png";			// player texture

// HUD
const char LIGHT_TEXTURE[] = "pictures\\light.png";
const char HUD_TEXTURE[] = "pictures\\HUD_KEY.png";
const char GAME_END_SCREEN[] = "pictures\\GameScreen.png";

//sound
const char BACKGROUND_MUSIC[] = "sounds\\awesomeness.wav";
const char BACKGROUND_MUSIC_V2[] = "sounds\\mysticaltheme.mp3";


// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY      = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY      = VK_MENU;         // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;       // Enter key
const UCHAR SPACE_KEY = VK_SPACE;

const UCHAR UP_KEY = VK_UP;
const UCHAR DOWN_KEY = VK_DOWN;
const UCHAR LEFT_KEY = VK_LEFT;
const UCHAR RIGHT_KEY = VK_RIGHT;

#endif
