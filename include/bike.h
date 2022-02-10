#ifndef GRIT_BIKE_H
#define GRIT_BIKE_H

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
#include <tonc_core.h>
#include <tonc_video.h>

#define bikeBitmapLen 384


typedef struct Bike
{
	int x,y;
	u16 color;
}Bike;

void drawBikeM3(Bike *b);
void moveBike(Bike *b, int x,int y);
void initBike(Bike *b, int x, int y);
void clearBike(int x, int y);

extern const unsigned char bikeBitmap[384];

#endif // GRIT_BIKE_H

//}}BLOCK(bike)
