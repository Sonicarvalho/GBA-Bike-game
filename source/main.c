#include "Intellisense.h"
#include "bike.h"
#include "obstacle.h"
#include "m3_gfx.h"
#include "posprintf.h"
#include <tonc_core.h>
#include <tonc_video.h>
#include <tonc_input.h>
#include <tonc_tte.h>
#include <tonc_text.h>
#include <malloc.h>	

int gameSpeed = 31;

int main()
{
	//set GBA rendering context to MODE 3 Bitmap Rendering
	REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

	Obstacle * obstacles = (Obstacle *) malloc(sizeof(Obstacle) * NR_OBSTACLES);
	int rng;
	Bike b;
	int frame=0;
	int newX;
	int t = 0;
	int colliding = 0;
	int score = 0;
	char score_str[20];
	 
	sqran(50);
	txt_init_std();
	initObstacles(obstacles,NR_OBSTACLES);
	//m3_rect(0,0,20,20,RGB15(14,20,31));
	m3_puts(140, 40, "yo man",RGB15(14,15,12));
	//m3_rect(200,150,200+16,150+8, RGB15(5,15,31));

	//drawSprite_M3(50,50,8,24,&bikeBitmap);
	initBike(&b, 140 ,15*8);
	drawBikeM3(&b);
	//drawSprite_M3(obs,obs,8,8,&obstacleBitmap);
	//drawBikeM3(50,50);
	//m3_line(10,10,230,10,CLR_WHITE);
	//m3_line(10,150,230,150,CLR_WHITE);
	
	
	while(1){
		vid_vsync();
		rng = qran_range(0,27*8);


		
        key_poll();
		if(((frame & gameSpeed) == 0) && colliding == 0){
			score++;
			posprintf(score_str, "score: %d", score);
			m3_clrs(140, 0, score_str,RGB15(0,0,0));
			m3_puts(140, 0, score_str ,RGB15(14,15,31));
			checkActivateObstacles(obstacles,NR_OBSTACLES,frame);
			clearObstacles(obstacles,NR_OBSTACLES);
			moveObstacles(obstacles,NR_OBSTACLES, rng);
			drawObstacles(obstacles,NR_OBSTACLES);
			updateSpeed(&gameSpeed, frame);
			for (int i = 0; i<NR_OBSTACLES; i++){
				colliding |= isBikeColliding(&b,&(obstacles[i]));
			}
		}
		

		if(key_hit(KEY_RIGHT)){
			clearBike(b.x,b.y);
			newX = b.x + 8;
			moveBike(&b,newX,b.y);
			drawBikeM3(&b);
			//drawSprite_M3(rng,rng,8,8,&obstacleBitmap);
			sqran(frame);
		}
		if(key_hit(KEY_LEFT)){
			clearBike(b.x,b.y);
			newX = b.x - 8;
			moveBike(&b,newX,b.y);
			drawBikeM3(&b);
			sqran(frame);
		}

		if(key_hit(KEY_A)){
			m3_puts(140, 40, "yo man",RGB15(14,15,31));
		}

		if(key_hit(KEY_B)){
			m3_clrs(140, 40, "yo man",RGB15(0,0,0));
		}
		
		
        frame++;
		
	++t;
	}
	return 0;
}