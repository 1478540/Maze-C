#include"head.h"

extern int column;
extern int row;
extern int game_level;
extern int map[max][max];
extern coordinate role;
extern coordinate direction[4];
extern coordinate end_door;

void Random_direction(coordinate* direction)
{
	for (int i = 0; i < 4; i++)
	{
		int r = rand() % 4;
		coordinate temp = direction[0];
		direction[0] = direction[r];
		direction[r] = temp;
	}
}

void dfs_maze(int x, int y)
{
	int count = 0;//计算当前格子上下左右四个方位共有几个
	
	if (map[x][y] == edge)
		return;

	Random_direction(direction);//随机调换方向的函数

	for (int i = 0; i < 4; i++)
	{
		int dx = x;
		int dy = y;
		int number = 1 + game_level;//由游戏水平决定往下挖的深度
		while (number--)
		{
			dx = dx + direction[i].x;
			dy = dy + direction[i].y;

			if ( map[dx][dy] == edge)
				break;

			count = 0;
			for (int j = dx - 1; j < dx + 2; j++) {
				for (int k = dy - 1; k < dy + 2; k++) {
					//确保只判断九宫格的四个特定位置
					if (abs(j - dx) + abs(k - dy) == 1 && map[j][k] == space) {
						count++;
					}
				}
			}

			if (count > 1) 
			{
				break;
			}

			map[dx][dy] = space;
		}
		if (count <= 1)
			dfs_maze(dx, dy);
	}
}


void DFS_maze()
{
	dfs_maze(1, 1);

	role.x = 1;
	role.y = 1;
	map[role.x][role.y] = ball;


	for (int i = column - 2; i >= 1; i--)
	{
		if (map[i][row - 2] == space)
		{
			map[i][row-1] = door;
			end_door.x = i;
			end_door.y = row - 1;
			break;
		}
	}

	FILE* fp;
	fopen_s(&fp, "maze.txt", "w");
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			fprintf_s(fp, "%d ", map[i][j]);
		}
		fprintf_s(fp, "\n");
	}
	fclose(fp);
}