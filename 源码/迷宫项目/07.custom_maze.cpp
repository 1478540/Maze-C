#include"head.h"

extern int map[max][max];
extern int column;
extern int row;
extern coordinate role;
extern coordinate end_door;

void custom_maze()
{
	int a;
	int i = 0; int j = 0;
	FILE* fp;
	fopen_s(&fp, "custom_maze.txt", "r");
	if (fp == NULL)
	{
		cout << "不能打开文件" << endl;
	}
	else
	{
		for (int i = 0; i < column; i++)
		{
			for (int j = 0; j < row; j++)
			{
				fscanf_s(fp, "%d", &a);
				map[i][j] = a;
			}
		}
	}
	role.x = 1;
	role.y = 1;
	end_door.x = 13;
	end_door.y = 16;
	fclose(fp);
	return;
}