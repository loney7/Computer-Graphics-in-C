/*--------------------------
Ankit Jain
--------------------------*/

/*
* 3D - scaling
* Reference: http://www.programsformca.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }


int maxx,maxy,midx,midy;
void axis(){

	cleardevice();
	line(midx,0,midx,maxy);
	line(0,midy,maxx,midy);
}





void draw(){
	int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

	int xc = (X1 + X2) / 2;
	int yc = (Y1 + Y2) / 2;



	int x,y,z,o,x1,x2,y1,y2;

	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;

	axis();

	bar3d(midx+50,midy-100,midx+60,midy-90,5,1);

	x=3;y=2;z=2;

	bar3d(midx+(x*50),midy-(y*100),midx+(x*60),midy-(y*90),5*z,1);


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
