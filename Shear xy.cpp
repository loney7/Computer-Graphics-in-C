/*--------------------------
Rahul Garg  | 25-Oct-2017
--------------------------*/

/*
* 2D Transformation: Shear
* Reference: http://www.geeksforgeeks.org
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }


void shear(int x1, int y1, int x2, int y2, double shx, int y){

	setcolor(WHITE);
	rectangle(x1, y1, x2, y2);



	setcolor(GREEN);
	//rectangle(x1, y1, x2 + shx*y, y2);
	line(x1,y1,x1+shx*y2 - shx*y,y2);
	line(x2,y1,x2+shx*y2 - shx*y,y2);
	line(x1+shx*y2 - shx*y,y2,x2+shx*y2 - shx*y,y2);

	return;
}

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int xc = (X1 + X2) / 2;
	int yc = (Y1 + Y2) / 2;


	shear(100, 150, 250, 300, 0.1, 4);

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
