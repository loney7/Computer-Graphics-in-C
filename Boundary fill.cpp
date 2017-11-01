/*--------------------------
Ankit Jain
--------------------------*/

/*
* Boundary Fill Algo.
* Reference: https://jee-appy.blogspot.in
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }

void b_fill(int x,int y,int f,int b)
{
  int c;
  c=getpixel(x,y);
  if((c!=b)&&(c!=f))
  {
      putpixel(x,y,WHITE);
      delay(10);
      b_fill(x+1,y,f,b);delay(1);
      b_fill(x,y+1,f,b);
      b_fill(x+1,y+1,f,b);
      b_fill(x-1,y-1,f,b);
      b_fill(x-1,y,f,b);
      b_fill(x,y-1,f,b);
      b_fill(x-1,y+1,f,b);
      b_fill(x+1,y-1,f,b);
  }
}

void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int xc = (X1 + X2) / 2;
	int yc = (Y1 + Y2) / 2;

	rectangle(50,50,100,100);
  	b_fill(55,55,4,15);

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
