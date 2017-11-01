/*--------------------------
Rahul Garg  | 05.Nov.2017 23:03:40
--------------------------*/

/*
* Flood Fill Algo.
* Reference: https://www.thecrazyprogrammer.com/
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }

void floodFill(int x, int y, int oldcolor, int newcolor)
{
    if(getpixel(x,y) == oldcolor){
        putpixel(x,y,newcolor);
        floodFill(x+1,y,oldcolor,newcolor);delay(5);
        floodFill(x,y+1,oldcolor,newcolor);delay(5);
        floodFill(x-1,y,oldcolor,newcolor);delay(5);
        floodFill(x,y-1,oldcolor,newcolor);delay(5);
    }
}

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int xc = (X1 + X2) / 2;
	int yc = (Y1 + Y2) / 2;

	circle(xc,yc,30);
	floodFill(xc,yc,0,14);

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
