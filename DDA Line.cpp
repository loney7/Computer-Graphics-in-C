/*--------------------------
Ankit Jain
--------------------------*/

/*
*DDA Line generation

*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }


void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int dx = abs(X2 - X1);
	int dy = abs(Y2 - Y1);

	int steps = min(dx, dy);

	float x_inc = dx / (float) steps;
	float y_inc = dy / (float) steps;

	int x = X1;
	int y = Y1;

	for(int i = 0; i < steps; i++){
		delay(50);
		putpixel(x, y, GREEN);
		x += x_inc;
		y += y_inc;
	}

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
