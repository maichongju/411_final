/**
 * This file contain all the constant for the program
 */
#ifndef SRC_CONSTANT_HPP_
#define SRC_CONSTANT_HPP_

#define WIN_WIDTH					1000
#define WIN_HEIGHT					1000

#define WIN_TITLE 					"City Skyline"

#define GLOBAL_TIME					0.0025

#define MAP_SIZE_WIDTH				3
#define MAP_SIZE_HEIGHT				3

#define TEXTURE_SUN					0
#define TEXTURE_MOON				1
#define TEXTURE_LEAF				2
#define TEXTURE_TREE_BARK			3

#define TEXTURE_BUILDING1			4
#define TEXTURE_BUILDING2			5
#define TEXTURE_BUILDING3			6
#define TEXTURE_BUILDING4			7
#define TEXTURE_BUILDING5			8

#define TEXTURE_PYRAMID				9

#define BUILDING_WINDOW_FRONT		0
#define BUILDING_WINDOW_RIGHT		1
#define BUILDING_WINDOW_REAR		2
#define BUILDING_WINDOW_LEFT		3

#define TRAFFICLIGHT_SOUTH			0
#define TRAFFICLIGHT_NORTH			180
#define TRAFFICLIGHT_EAST			90
#define TRAFFICLIGHT_WEST			-90

#define CAR_EAST					0
#define CAR_SOUTH					-90
#define CAR_NORTH					90
#define CAR_WEST					180

#define CAR_LIST_EAST				0
#define CAR_LIST_WEST				1
#define CAR_LIST_NORTH				2
#define CAR_LIST_SOUTH				3

#define TRAFFIC_LIGHT_RED			0
#define TRAFFIC_LIGHT_YELLOW		1
#define TRAFFIC_LIGHT_GREEN			2
#define TRAFFIC_LIGHT_OFF			3

#define CAR_MOVE_MOVING				0
#define	CAR_MOVE_STOPPING			1
#define CAR_MOVE_STOPPED			2

#define MENU_TIME_MORNING			0
#define MENU_TIME_NIGHT				1
#define MENU_TIME_PAUSE				2
#define MENU_TIME_RESUME			3

#define CAMERA_MOVE_SPEED			0.025
#define CAMERA_MOVE_FORWARD			0
#define CAMERA_MOVE_BACKWARD		1

#define CAMERA_TURN_SPEED			1
#define CAMERA_TURN_LEFT			-1
#define CAMERA_TURN_RIGHT			1

#define CAMERA_UP					1
#define CAMERA_DOWN					-1

#define CAMERA_EYE					0
#define CAMERA_REF					1

#define TREE_CONE					0
#define TREE_CUBE					1
#define TREE_SPHERE					2
#define TREE_CONE_MULTIPLE			3



#define SOLAR_ROTATE				360/(24/GLOBAL_TIME)

#endif /* SRC_CONSTANT_HPP_ */
