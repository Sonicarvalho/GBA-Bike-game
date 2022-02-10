#include "m3_gfx.h"
#include <tonc_core.h>
#include <tonc_video.h>

void drawSprite_M3(int x,int y,int width, int height, const void * bitmap){
	for(int i = 0; i<height; i++) {
		COLOR * address = ((COLOR *) m3_mem)+ x + 240*(i+y) ;
		tonccpy(address , ((u8 *)bitmap) + i*(width*2),width*2);

	}
}