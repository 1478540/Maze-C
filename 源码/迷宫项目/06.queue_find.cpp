#include"head.h"

std::queue<coordinate> que;
std::stack<coordinate> sta;
extern coordinate direction[4];
extern int map[max][max];
extern coordinate end_door;
extern int row;
extern int column;
extern coordinate role;
extern int turn;
extern IMAGE road_image;
extern IMAGE role_image;

static coordinate parents[max][max];
static int queue_vis[max][max];


void queue_find()
{
	pre_queue_find();
	coordinate next_role;
	que.push(role);
	parents[role.x][role.y].x = -1;
	parents[role.x][role.y].y = -1;
	queue_vis[role.x][role.y] = 1;
	while (!que.empty())
	{
		if (que.front().x == end_door.x && que.front().y == end_door.y)
		{
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			next_role.x = que.front().x + direction[i].x;
			next_role.y = que.front().y + direction[i].y;
			if ((map[next_role.x][next_role.y] == space|| map[next_role.x][next_role.y]==door)&&queue_vis[next_role.x][next_role.y]==0)
			{
				que.push(next_role);
				queue_vis[next_role.x][next_role.y] = 1;
				parents[next_role.x][next_role.y].x = que.front().x;
				parents[next_role.x][next_role.y].y = que.front().y;
			}
		}
		que.pop();
	}
	if (que.empty())
	{
		cout << "没有通路" << endl;
	}
	else
	{
		show_road();
	}
}


void show_road()
{
	coordinate a, b;
	a.x = end_door.x - 1; a.y = end_door.y;
	b.x = end_door.x ; b.y = end_door.y-1;
	if (role.x != 1 || role.y != 1)
	{
		sta.push(end_door);

		while (parents[sta.top().x][sta.top().y].x != -1 || parents[sta.top().x][sta.top().y].y != -1)
		{
			map[sta.top().x][sta.top().y] = road;
			sta.push(parents[sta.top().x][sta.top().y]);
			putimage(sta.top().y * min_size, sta.top().x * min_size, &road_image);
		}
		map[end_door.x][end_door.y] = door;
	}
	else
	{
		if (map[b.x][b.y] == space)
		{
			sta.push(b);
			putimage(b.y * min_size, b.x * min_size, &road_image);

			while (parents[sta.top().x][sta.top().y].x != -1 || parents[sta.top().x][sta.top().y].y != -1)
			{
				map[sta.top().x][sta.top().y] = road;
				sta.push(parents[sta.top().x][sta.top().y]);
				putimage(sta.top().y * min_size, sta.top().x * min_size, &road_image);
			}
		}
		if (map[a.x][a.y] == space)
		{
			sta.push(a);
			putimage(a.y * min_size, a.x * min_size, &road_image);

			while (parents[sta.top().x][sta.top().y].x != -1 || parents[sta.top().x][sta.top().y].y != -1)
			{
				map[sta.top().x][sta.top().y] = road;
				sta.push(parents[sta.top().x][sta.top().y]);
				putimage(sta.top().y * min_size, sta.top().x * min_size, &road_image);
			}
		}
	}
	putimage(role.y * min_size, role.x * min_size, &role_image);
//	map[b.x][b.y] = road;

/*	do
	{
		int x = sta.top().x;
		int y = sta.top().y;
		sta.pop();
		map[sta.top().x][sta.top().y] = ball;
		role.x = sta.top().x;
		role.y = sta.top().y;
		map[x][y] = road;
		if (role.x - x == 1)
			turn = down;
		if (role.x - x == -1)
			turn = up;
		if (role.y - y == 1)
			turn = right1;
		if (role.y - y == -1)
			turn = left1;
		mapdraw_rolemove();
	} while (sta.size() > 2);
*/
}


void pre_queue_find()
{
	for(int i=0;i<=column;i++)
		for (int j = 0; j <= row; j++)
		{
			parents[i][j].x = 0;
			parents[i][j].y = 0;
			queue_vis[i][j] = 0;
		}
	while (!que.empty())
		que.pop();
	while (!sta.empty())
		sta.pop();
}