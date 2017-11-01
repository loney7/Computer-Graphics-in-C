/*--------------------------
Ankit Jain
--------------------------*/

/*
* 2D Transformation: Scaling

*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

inline int min(int a, int b){ return a < b ? a : b ; }
inline int max(int a, int b){ return a > b ? a : b ; }


void transform(int s[][2], int t[][1]){
    int temp[2][1] = { {0} };

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 1; j++)
            for (int k = 0; k < 2; k++)
                temp[i][j] += (s[i][k] * t[k][j]);

    t[0][0] = temp[0][0];
    t[1][0] = temp[1][0];
}


void scale(int p[3][2], int sx, int sy){

    line(p[0][0], p[0][1], p[1][0], p[1][1]);
    line(p[1][0], p[1][1], p[2][0], p[2][1]);
    line(p[2][0], p[2][1], p[0][0], p[0][1]);


    int s[2][2] = {{sx, 0}, {0, sy}};
    int t[2][1] = {{0}};


    for (int i = 0; i < 3; i++){

        t[0][0] = p[i][0];
        t[1][0] = p[i][1];

        transform(s, t);

        p[i][0] = t[0][0];
        p[i][1] = t[1][0];
    }

    line(p[0][0], p[0][1], p[1][0], p[1][1]);
    line(p[1][0], p[1][1], p[2][0], p[2][1]);
    line(p[2][0], p[2][1], p[0][0], p[0][1]);

    return;
}



void draw(){
    //puts("hhhhhh");
    int X1 = 0, Y1 = 0, X2 = getmaxx(), Y2 = getmaxy();

    int xc = (X1 + X2) / 2;
    int yc = (Y1 + Y2) / 2;

    int p[3][2] = {{250,250},{150,50},{100,100}};
    scale(p, 2, 2);

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
    //printf("hi");
    init_graph();
    draw();
    close_graph();
    return 0;
}
