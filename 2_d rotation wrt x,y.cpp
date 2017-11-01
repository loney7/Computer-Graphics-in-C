/*--------------------------
Ankit Jain
--------------------------*/

/*
* 2D Transformation: Rotation

*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }

#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180)

void rotate(int p[4][2], int n, int hx, int hy, int theta){
    setcolor(WHITE);
    for(int i = 0; i < n-1; i++)
        line(p[i][0], p[i][1], p[i+1][0], p[i+1][1]);
    line(p[n-1][0], p[n-1][1], p[0][0], p[0][1]);


    setcolor(WHITE);
    for(int i = 0; i < n; i++){
        p[i][0] = hx + ( (p[i][0] - hx) * COS(theta) - (p[i][1] - hy) * SIN(theta));
        p[i][1] = hy + ( (p[i][0] - hx) * SIN(theta) + (p[i][1] - hy) * COS(theta));
    }

    for(int i = 0; i < n-1; i++)
        line(p[i][0], p[i][1], p[i+1][0], p[i+1][1]);
    line(p[n-1][0], p[n-1][1], p[0][0], p[0][1]);

    return;
}



void draw(){
    int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

    int xc = (X1 + X2) / 2;
    int yc = (Y1 + Y2) / 2;

    int p[4][2] = {{50,50},{100,50},{100,150},{50,150}};
    rotate(p,4,xc,yc,15);

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
