
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

#define obstacleBitmapLen 128
#include "bike.h"

extern const unsigned char obstacleBitmap[128];

typedef struct Obstacle
{
	int x,y;
	int active;
}Obstacle;

void * initObstacles(Obstacle *o,int len);
void drawObstacles(Obstacle * obs, int len);
void clearObstacles(Obstacle * obs, int len);
void moveObstacles(Obstacle * obs, int len);
int isBikeColliding(Bike * b, Obstacle * o);


#endif // GRIT_OBSTACLE_H

//}}BLOCK(obstacle)
