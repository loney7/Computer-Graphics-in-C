/*--------------------------
Ankit jain
--------------------------*/

/*
*Mid-Point Algorithm for Circle generation
*Reference: http://electrofriends.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include<math.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }

#define PI 3.14159265358979323846
float startangle = 0,endangle = 360;
int x,y;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
	return;
}

int Can_draw( float theta ){
	if( theta >= startangle && theta <= endangle ) return 1;
	else return 0;
}

void Circlepoints(int x,int y,int xc,int yc){
	float theta;
	theta = atan( (float) y / x );
	theta = theta * (180 / M_PI);

	if( Can_draw(theta))
		putpixel( xc + x, yc - y, WHITE);
	if( Can_draw(360 - theta))
		putpixel(xc + x, yc + y, WHITE);

	if( Can_draw(90 - theta))
		putpixel(xc + y, yc - x, WHITE);
	if( Can_draw(270 + theta))
		putpixel(xc + y, yc + x, WHITE);

 	if( Can_draw(180 - theta))
		putpixel(xc - x, yc - y, WHITE);
	if( Can_draw(180 + theta))
		putpixel(xc - x, yc + y, WHITE);

	if( Can_draw(90 + theta))
		putpixel(xc - y, yc - x, WHITE);
	if( Can_draw(270 - theta))
		putpixel(xc - y, yc + x, WHITE);

	return;
}

void midPointCircle(int xc, int yc, int rad){

	float d = (5/4.0) - rad;
	x = 0,y = rad;

	while(y > x ++){
		d += d < 0 ? 2 * x + 3 : 2 * (x - y--) +5;
		Circlepoints(x,y,xc,yc);
		delay(100);
	}
	return;
}

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int xc = (X1 + X2) / 2;
	int yc = (Y1 + Y2) / 2;

	int radius = 100;

	midPointCircle(xc, yc, radius);

	return;
}

void init_graph(){
	int gdriver = DETECT, gmode, err;
	initgraph(&gdriver, &gmode, NULL);
	return;
}

void close_graph(){
	//fflush(stdin);
	getchar();
	closegraph();
	return;
}

int main(){
	init_graph();
	draw();
	close_graph();
	return 0;
}
