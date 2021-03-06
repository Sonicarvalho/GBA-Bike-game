#include <tonc_core.h>
#include <tonc_video.h>
#include "obstacle.h"
#include "bike.h"
#include "m3_gfx.h"
//{{BLOCK(obstacle)

//======================================================================
//
//	obstacle, 8x8@16, 
//	+ bitmap fake compressed
//	Total size: 132 = 132
//
//	Time-stamp: 2022-01-30, 00:54:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned char obstacleBitmap[128] __attribute__((aligned(4)))=
{
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x1F,0x0A,0x1F,0x0A,0xFF,0x7F,0xFF,0x7F,0x00,0x00,
	0x00,0x00,0xFF,0x7F,0x1F,0x0A,0x1F,0x09,0x1F,0x09,0x1F,0x0A,0xFF,0x7F,0x00,0x00,
	0xFF,0x7F,0x1F,0x0A,0x1F,0x09,0x94,0x52,0x94,0x52,0x1F,0x09,0x1F,0x0A,0xFF,0x7F,
	0xFF,0x7F,0x1F,0x0A,0x1F,0x09,0x94,0x52,0x94,0x52,0x1F,0x09,0x1F,0x0A,0xFF,0x7F,
	0x00,0x00,0xFF,0x7F,0x1F,0x0A,0x1F,0x09,0x1F,0x09,0x1F,0x0A,0xFF,0x7F,0x00,0x00,
	0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x1F,0x0A,0x1F,0x0A,0xFF,0x7F,0xFF,0x7F,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
};
//static int activeObs = 0;

void initObstacles(Obstacle *o,int len){
	for (int i = 0; i<len; i++){
		o[i].x = 0+i*40;
		o[i].y = 0;
		o[i].active = 0;
	}
}

void drawObstacles(Obstacle * obs, int len){
	for (int i = 0; i<len; i++){
		for (int j = 0; j<3; j++){
			if(obs[i].active != 0){
				drawSprite_M3(obs[i].x + j*8,obs[i].y,8,8,&obstacleBitmap);
			}
		}
	}
}

void clearObstacles(Obstacle * obs, int len){
	for (int i = 0; i<len; i++){
		if(obs[i].active != 0)
			m3_rect(obs[i].x,obs[i].y,obs[i].x + 8*3,obs[i].y+8, CLR_BLACK);
	}
}

void checkActivateObstacles(Obstacle * obs, int len, int frame){
	switch(frame){
		case 0:
			obs[0].active = 1;
			break;
		case 8*32:	
			obs[1].active = 1;
			break;
		case 12*32:
			obs[2].active = 1;
			break;
	}
}

void updateSpeed(int * speed, int frame){
	switch(frame){
		case 20*32:
			*speed = 15;
			break;
		case 20*32 + 20*16:	
			*speed = 7;
			break;
		case 20*32 + 20*8:
			*speed = 3;
			break;
	}
}

void moveObstacles(Obstacle * obs, int len, int rng){
	for (int i = 0; i<len; i++){
		if(obs[i].active != 0){
			int y = obs[i].y + 8;		
			
			if(y > 160){
				y -= 168;
				obs[i].x = rng;
			}
				

			obs[i].y = y;
		}
	}
}

int isBikeColliding(Bike * b, Obstacle * o){

	if(o->y +8 <= b->y) // if the obstacle is not even near enough vertically
		return 0;
	else if(o->y >= b->y +24){  // if the obstacle passed the bike vertically
		return 0;
	}
	else if(o->x +24 <=b->x){ // if the obstacle past the bike on it's left
		return 0;
	}
	else if(o->x >= b->x + 8){ // if the obstacle past the bike on it's right
		return 0;
	}
	else {
		return 1;  //Colliding
	}
}

//}}BLOCK(obstacle)
