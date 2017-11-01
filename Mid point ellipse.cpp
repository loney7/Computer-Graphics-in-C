/*--------------------------
Ankit Jain
--------------------------*/

/*
*Mid-Point Algorithm for Ellipse generation
*Reference: http://cfetch.blogspot.in
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include<math.h>
inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }


void midPointEllipse(int xc, int yc, int rx, int ry){

   int x = 0, y=ry;


   int p = (ry * ry) - (rx * rx * ry) + ((rx*rx) / 4);

   while((2 * x * ry * ry) < (2 * y * rx * rx)){

        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        x ++;

        if(p < 0)
     		p = p + (2 * ry * ry * x)  +  (ry * ry);
        else
     		p=p + (2 * ry * ry * x + ry * ry) - (2 * rx * rx * --y);

     	delay(50);
	}

    p=((float)x + 0.5) * ((float)x + 0.5) * ry * ry + (y - 1) * (y - 1) * rx * rx - rx * rx * ry * ry;

    while(y >= 0) {

        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        y --;

        if(p > 0)
     		p=p-(2*rx*rx*y)+(rx*rx);
        else
     		p=p+(2 * ry * ry * ++x) - (2 * rx * rx * y) - (rx * rx);

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


	midPointEllipse(xc, yc, r_a, r_b);

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
