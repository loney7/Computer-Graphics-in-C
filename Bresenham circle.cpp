/*--------------------------
Ankit Jain
--------------------------*/

/*
*Bresenham’s Algorithm for Circle generation
*Reference: http://www.geeksforgeeks.org
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }

inline void drawCircle(int xc, int yc, int x, int y){
    putpixel(xc+x, yc+y, WHITE);
    putpixel(xc-x, yc+y, WHITE);
    putpixel(xc+x, yc-y, WHITE);
    putpixel(xc-x, yc-y, WHITE);
    putpixel(xc+y, yc+x, WHITE);
    putpixel(xc-y, yc+x, WHITE);
    putpixel(xc+y, yc-x, WHITE);
    putpixel(xc-y, yc-x, WHITE);
    return;
}

void bresenhamCircle(int xc, int yc, int radius){

	printf("hi");

    int x = 0, y = radius;
    int d = 3 - 2 * radius;
    while (y >= x++){
        drawCircle(xc, yc, x, y);
        d += d > 0 ? 4 * (x - --y) + 10 : 4 * x + 6;
        drawCircle(xc, yc, x, y);
        delay(50);
    }
    return;
}
void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int xc = (X1 + X2) / 2;
	int yc = (Y1 + Y2) / 2;

	int radius = 100;

	bresenhamCircle(xc, yc, radius);

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
