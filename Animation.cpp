/*--------------------------
Ankit Jain
--------------------------*/

/*
* Ball Animation
* Reference: https://www.thecrazyprogrammer.com/
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }


void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int xc = (X1 + X2) / 2;
	int yc = (Y1 + Y2) / 2;




	int x = xc;//getmaxx()/2;
 	int y = 30;

 	int flag = 0;
 	while (1) {
  		if(y >= getmaxy()-30 || y <= 30)
     	flag = !flag;
     	setcolor(WHITE);
     	circle(x, y, 50);
     	floodfill(x, y,WHITE);

 		delay(150);

 		cleardevice();
 		if(flag){
     		y = y + 5;
 		} else {
     		y = y - 5;
 		}
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
