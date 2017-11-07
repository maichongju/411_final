// Important Constant for the program
#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

// Window Size
#define WIN_WIDTH				800
#define WIN_HEIGHT				800

// Snake Length Start
#define SNAKE_START_LENGTH		4

// Game Block Size
#define GAME_BLOCK_SIZE			2

// Game Size (Coordinate)
#define GAME_SIZE_WIDTH			100
#define GAME_SIZE_HEIGHT		100

// Game Zone Size (Must can be divide by 2 and can be divide by block size)
#define GAME_ZONE_WIDTH			100
#define GAME_ZONE_HEIGHT		96

// Game Status
#define GAME_STATUS_NEW 		0
#define GAME_STATUS_RUNNING 	1
#define GAME_STATUS_PAUSE 		2
#define GAME_STATUS_END 		3

// Game Level
#define GAME_LEVEL_EASY 		1
#define GAME_LEVEL_NORMAL 		2
#define GAME_LEVEL_HARD 		3
#define GAME_LEVEL_EXPERT 		4

// Key direction
#define GAME_KEY_NULL			0
#define GAME_KEY_UP				1
#define GAME_KEY_DOWN			2
#define GAME_KEY_LEFT			3
#define GAME_KEY_RIGHT			4

//size of array function
#define length(a) sizeof(a)/sizeof(a[0])

#endif
