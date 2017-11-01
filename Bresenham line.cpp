/*--------------------------
Ankit Jain
--------------------------*/

/*
*Bresenham’s Algorithm for Line generation
*Reference: http://www.geeksforgeeks.org
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }

void bresenhamLine(int x1, int y1, int x2, int y2){
	int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new - (x2 - x1);
 	for (int x = x1, y = y1; x <= x2; x++){
  	  putpixel(x, y, WHITE);
  	  delay(50);
      slope_error_new += m_new;
      if (slope_error_new >= 0){
      	y++;
        slope_error_new  -= 2 * (x2 - x1);
      }
    }
	return;
}

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int x1 = 50, x2 = 250;
	int y1 = 50, y2 = 250;

	bresenhamLine(x1, y1, x2, y2);

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
