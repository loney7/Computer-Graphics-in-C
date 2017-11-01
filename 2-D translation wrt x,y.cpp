/*--------------------------
Ankit Jain
--------------------------*/

/*
* 2D Transformation: Translation

*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }

void transPoint(int x, int y, int tx, int ty, int hx, int hy){

	putpixel(x,y,WHITE);

	x = x + tx - hx;
	y = y + ty - hy;

	putpixel(x,y,GREEN);

	return;
}

void transLine(int x1, int y1, int x2, int y2, int tx, int ty, int hx, int hy){

	setcolor(WHITE);
	line(x1, y1, x2, y2);

	x1 += tx - hx;
	y1 += ty - hy;
	x2 += tx - hx;
	y2 += ty - hy;

	setcolor(GREEN);
	line(x1, y1, x2, y2);

	return;
}

void transRect(int x1, int y1, int x2, int y2, int tx, int ty, int hx, int hy){

	setcolor(WHITE);
	rectangle(x1, y1, x2, y2);

	x1 += tx - hx;
	y1 += ty - hy;
	x2 += tx - hx;
	y2 += ty - hy;

	setcolor(GREEN);
	rectangle(x1, y1, x2, y2);

	return;
}

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int xc = (X1 + X2) / 2;
	int yc = (Y1 + Y2) / 2;


	transPoint(9, 9, 10, 20, 10, 10);
	transLine(50, 50, 150, 150, 10, 30, 10, 10);
	transRect(100, 150, 300, 300, 200, 200, 100, 100);

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
