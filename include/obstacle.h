
//{{BLOCK(obstacle)

//======================================================================
//
//	obstacle, 8x8@16, 
//	+ bitmap not compressed
//	Total size: 128 = 128
//
//	Time-stamp: 2022-01-30, 00:49:47
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_OBSTACLE_H
#define GRIT_OBSTACLE_H

#include "bike.h"

#define obstacleBitmapLen 128
#define NR_OBSTACLES 3
#define OBSTACLE_HEIGHT 8
#define OBSTACLE_WIDTH NR_OBSTACLES*OBSTACLE_HEIGHT


extern const unsigned char obstacleBitmap[128];


typedef struct Obstacle
{
	int x,y;
	int active;
}Obstacle;

void initObstacles(Obstacle *o,int len);
void drawObstacles(Obstacle * obs, int len);
void clearObstacles(Obstacle * obs, int len);
void moveObstacles(Obstacle * obs, int len, int rng);
void checkActivateObstacles(Obstacle * obs, int len, int frame);
int isBikeColliding(Bike * b, Obstacle * o);
void updateSpeed(int * speed, int frame);


#endif // GRIT_OBSTACLE_H

//}}BLOCK(obstacle)
