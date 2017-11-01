/*--------------------------
Ankit Jain
--------------------------*/

/*
* 3D - rotation
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
	delay(1000);
	printf("Enter rotating angle");
	//scanf("%d",&o);
	o=20;
 	x1=50*cos(o*3.14/180)-100*sin(o*3.14/180);
 	y1=50*sin(o*3.14/180)+100*cos(o*3.14/180);
 	x2=60*cos(o*3.14/180)-90*sin(o*3.14/180);
 	y2=60*sin(o*3.14/180)+90*cos(o*3.14/180);
 	//axis();
	printf("After rotation about z axis  ");
	delay(2000);
	bar3d(midx+x1,midy-y1,midx+x2,midy-y2,5,1);
	//axis();
	printf("After rotation  about x axis  ");
	delay(2000);
	bar3d(midx+50,midy-x1,midx+60,midy-x2,5,1);
	//axis();
	printf("After rotation about yaxis  ");
	delay(2000);
	bar3d(midx+x1,midy-100,midx+x2,midy-90,5,1);


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
