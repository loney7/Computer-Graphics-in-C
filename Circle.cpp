/*--------------------------
Ankit Jain
--------------------------*/

/*
*Circle generation

*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int x = (X1 + X2) / 2;
	int y = (Y1 + Y2) / 2;

	int radius = 100;

	//outtextxy(x-100, 50, "Circle in C Graphics");
	circle(x, y, radius);

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
