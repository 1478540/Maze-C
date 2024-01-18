#include"head.h"

extern int column;
extern int row;
extern int flag;
extern coordinate role;
extern int map[max][max];
extern int vis[max][max];
extern coordinate end_door;
extern int game_level;

extern int turn;



void initgame()
{
	mciSendString("close t", NULL, 0, NULL);
	mciSendString("open backsound.mp3 alias c", NULL, 0, NULL);
	mciSendString("play c repeat", NULL, 0, NULL);

	initgraph(width,height,0);
	turn = 4;

	
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			map[i][j] = wall;
		}
	}
	
	for (int i = 0; i < column; i++)
	{
		for (int j = row; j < row + 6; j++)
		{
			map[i][j] = help;
		}
	}
	
	for (int i = 2; i < 12; i++)
	{
		for (int j = row+1; j <= row+4; j++)
		{
			map[i][j] = board;
		}
		if (i == 3 ||i==7)
			i = i + 1;
	}
	
	for (int i = 0; i < row; i++)
		map[0][i] = map[column - 1][i] = edge;
	for (int i = 0; i < column; i++)
		map[i][0] = map[i][row - 1] = edge;


	if (game_level == 100)
	{
		custom_maze();
	}
	else
		DFS_maze();
	
	pre_loading_picture();
}



void rolemove()
{
	coordinate next;
	next = role;
	switch (_getch())
	{
	case'w':case'W':case 72:
		next.x = next.x - 1;
		turn = up;
		break;
	case's':case 'S':case 80:
		next.x = next.x + 1;
		turn = down;
		break;
	case'a':case'A':case 75:
		next.y = next.y - 1;
		turn = left1;
		break;
	case'd':case'D':case 77:
		next.y = next.y + 1;
		turn = right1;
		break;
	case'1':
		queue_find(); //next.x = end_door.x; next.y = end_door.y;*/
		break;
	case'2':
		exit(0);
	default:
		return;
		break;
	}
	if (map[next.x][next.y] == wall)
		return;
	if (map[next.x][next.y] == space|| map[next.x][next.y] == road)
	{
		map[role.x][role.y] = space;
		role = next;
		map[role.x][role.y] = ball;
	}
	if (map[next.x][next.y] == door)
	{
		flag = 1;
	}
	mapdraw_rolemove();
}
