/*--------------------------
Ankit Jain
--------------------------*/

/*
*Mid-Point Algorithm for Line generation
*Reference: http://electrofriends.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
	return;
}


void midPointLine(int x1, int y1, int x2, int y2){

	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

	int slope = 0;
	if(dy > dx){
		swap(&x1, &y1);
		swap(&x2, &y2);
		swap(&dx, &dy);
		slope = 1;
	}

	if(x1 > x2){
		swap(&x1, &x2);
		swap(&y1, &y2);
	}

	int incry = y1 > y2 ? -1 : 1;
	int d = 2 * dy - dx;

	while(x1++ < x2){
		d += d <= 0 ? 2 * dy : 2 * (dy - dx), y1 += incry;
		slope ? putpixel(y1, x1, WHITE) : putpixel(x1, y1, WHITE);
		delay(50);
	}
	return;
}

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int x1 = 50, x2 = 250;
	int y1 = 50, y2 = 250;

	midPointLine(x1, y1, x2, y2);

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
