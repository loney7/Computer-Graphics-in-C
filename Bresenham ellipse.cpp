/*--------------------------
Ankit Jain
--------------------------*/

/*
*Bresenham's Algorithm for Ellipse generation
*Reference: http://meansofmine.blogspot.in
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }


void bresenhamEllipse(int xc, int yc, int rx, int ry){

    int x = 0;
    int y = ry;

    int d1 = ry * ry - (rx * rx * ry) + (0.25 * rx * rx);

    int dx = 2 * ry * ry * x;
    int dy = 2 * rx * rx * y;
    while (dx < dy) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);

        if (d1 < 0){
            x = x + 1;
            y = y;
            dx = dx + 2 * ry * ry;
            d1 = d1 + dx + ry * ry;
        }
        else{
            x = x + 1;
            y = y - 1;

            dx = dx + 2 * ry * ry;
            dy = dy - 2 * rx * rx;

            d1 = d1 + dx - dy + ry * ry;
        }

        delay(50);

    }

    int d2 = ry * ry * ( x + 0.5) * ( x + 0.5 ) + rx * rx * (y - 1) * (y-1) - rx * rx * ry * ry;

    while ( y > 0){
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);

        if(d2 >0){
            x = x;
            y = y-1;

            dy = dy - 2 * rx * rx;
            d2 = d2 - dy + rx * rx;
        }
        else{
            x = x + 1;
            y = y - 1;

            dy = dy - 2 * rx * rx;
            dx = dx + 2 * ry * ry;

            d2 = d2 + dx -dy + rx * rx;
        }

        delay(50);

    }


	return;
}

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int xc = (X1 + X2) / 2;
	int yc = (Y1 + Y2) / 2;

	int r_a = 100;
	int r_b = 50;


	bresenhamEllipse(xc, yc, r_a, r_b);

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
