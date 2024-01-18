#ifndef HEAD_H
#define HEAD_H

#include<graphics.h>
#include<iostream>


#include<conio.h>

#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<queue>
#include<stack>
#include<windows.h>


#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
using namespace std;


#define max 35



enum element
{
	wall, space, ball, door, edge, help, board, road,
	//¥∞ø⁄ Ù–‘
	width = 960, height = 600, min_size = 40
};



enum turn
{
	down,up, right1, left1
};



typedef struct coordinate
{
	int x;
	int y;
}coordinate;


void initgame();
void mapdraw();
void showmap();
void rolemove();
void gamebegingraph();
void gameovergraph();
void dfs_maze(int x,int y);
void DFS_maze();
void Random_direction(coordinate* direction);
void show_road();
void queue_find();
void pre_queue_find();
void pre_loading_picture();
void gamehelp_graph();
IMAGE transparency_map(IMAGE target_image);
int button_judge(int x, int y);
void mapdraw_rolemove();
void custom_maze();

#endif
