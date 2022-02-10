#include <tonc_core.h>
#include <tonc_video.h>
#include "bike.h"
#include "m3_gfx.h"

//{{BLOCK(bike)

//======================================================================
//
//	bike, 8x24@16, 
//	+ bitmap not compressed
//	Total size: 384 = 384
//
//	Time-stamp: 2022-01-29, 00:11:31
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================


const unsigned char bikeBitmap[384] __attribute__((aligned(4)))=
{
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,
	0x00,0x00,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0x00,0x00,
	0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,
	0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,
	0x00,0x00,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0x00,0x00,
	0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,
	0x00,0x00,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0x00,0x00,
	0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,
	0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,
	0x00,0x00,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0x00,0x00,
	0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
};

void drawBikeM3(Bike *b){
	drawSprite_M3(b->x,b->y,8,24,&bikeBitmap);
}

void moveBike(Bike *b, int x,int y){
	b->x = x;
	b->y = y;
}

void initBike(Bike *b, int x, int y){
	b->x = x;
	b->y = y;
}

void clearBike(int x, int y){
	m3_rect(x,y,x+8,y+24, CLR_BLACK);
}
//}}BLOCK(bike)