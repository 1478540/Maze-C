#include"head.h"

extern int column;
extern int row;
extern int flag;
extern int game_level;

int main()
{
	srand((unsigned)time(NULL));
	while (1)
	{
		gamebegingraph();
		initgame();
		mapdraw();
		showmap();
		while (1)
		{
			rolemove();
			if (flag == 1)
			{
				flag = 0;
				gameovergraph();
				break;
			}
		}
		char c=_getch();
		closegraph();
		if (c == '2')
			exit(0);
	}
	return 0;
}
