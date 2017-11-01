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

void transPoint(int x, int y, int tx, int ty){

	putpixel(x,y,WHITE);

	x = x + tx;
	y = y + ty;

	putpixel(x,y,WHITE);

	return;
}

void transLine(int x1, int y1, int x2, int y2, int tx, int ty){

	setcolor(WHITE);
	line(x1, y1, x2, y2);

	x1 += tx;
	y1 += ty;
	x2 += tx;
	y2 += ty;

	setcolor(GREEN);
	line(x1, y1, x2, y2);

	return;
}

void transRect(int x1, int y1, int x2, int y2, int tx, int ty){

	setcolor(WHITE);
	rectangle(x1, y1, x2, y2);

	x1 += tx;
	y1 += ty;
	x2 += tx;
	y2 += ty;

	setcolor(GREEN);
	rectangle(x1, y1, x2, y2);

	return;
}

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int xc = (X1 + X2) / 2;
	int yc = (Y1 + Y2) / 2;


	transPoint(90, 90, 10, 20);
	transLine(20, 10, 50, 50, 10, 30);
	transRect(250, 250, 300, 300, 20, 20);

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
