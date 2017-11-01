/*--------------------------
Ankit Jain
--------------------------*/

/*
*Plot a pixel
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();
	int x = (X1 + X2) / 2, y = (Y1 + Y2) / 2;
	putpixel(x, y, GREEN);
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
