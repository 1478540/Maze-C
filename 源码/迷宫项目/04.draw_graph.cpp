#include"head.h"

extern int column;
extern int row;
extern int map[max][max];
extern IMAGE door_image;
extern IMAGE door_image1;
extern IMAGE door_image2;
extern IMAGE door_image3;
extern IMAGE wall_image;
extern IMAGE space_image;
extern IMAGE help_image;
extern MOUSEMSG mouse;
extern int game_level;
extern int flag_gamebegin;
extern int r[4][4];
extern coordinate role;
extern int turn;

extern IMAGE mask_image_role_left1;
extern IMAGE mask_image_role_left2;
extern IMAGE mask_image_role_left3;
extern IMAGE role_left1;
extern IMAGE role_left2;
extern IMAGE role_left3;
extern IMAGE mask_image_role_right1;
extern IMAGE mask_image_role_right2;
extern IMAGE mask_image_role_right3;
extern IMAGE role_right1;
extern IMAGE role_right2;
extern IMAGE role_right3;
extern IMAGE mask_image_role_up1;
extern IMAGE mask_image_role_up2;
extern IMAGE mask_image_role_up3;
extern IMAGE role_up1;
extern IMAGE role_up2;
extern IMAGE role_up3;
extern IMAGE mask_image_role;
extern IMAGE mask_image_role_down2;
extern IMAGE mask_image_role_down3;
extern IMAGE role_image;
extern IMAGE role_down2;
extern IMAGE role_down3;
extern IMAGE road_image;

void pre_loading_picture()
{
	loadimage(&road_image, _T("road.png"), min_size, min_size);

	loadimage(&door_image, _T("door.png"), min_size, min_size);
	loadimage(&space_image, _T("space.png"), min_size, min_size);
	loadimage(&wall_image, _T("wall.png"), min_size, min_size);
	loadimage(&help_image, _T("help.png"), min_size, min_size);
	loadimage(&door_image1, _T("door1.png"), min_size, min_size);
	loadimage(&door_image2, _T("door2.png"), min_size, min_size);
	loadimage(&door_image3, _T("door3.png"), min_size, min_size);
	
	loadimage(&role_left1, _T("role_left1.png"), min_size, min_size);
	loadimage(&role_left2, _T("role_left2.png"), min_size, min_size);
	loadimage(&role_left3, _T("role_left3.png"), min_size, min_size);
	mask_image_role_left1 = transparency_map(role_left1);
	mask_image_role_left2 = transparency_map(role_left2);
	mask_image_role_left3 = transparency_map(role_left3);

	loadimage(&role_right1, _T("role_right1.png"), min_size, min_size);
	loadimage(&role_right2, _T("role_right2.png"), min_size, min_size);
	loadimage(&role_right3, _T("role_right3.png"), min_size, min_size);
	mask_image_role_right1 = transparency_map(role_right1);
	mask_image_role_right2 = transparency_map(role_right2);
	mask_image_role_right3 = transparency_map(role_right3);

	loadimage(&role_up1, _T("role_up1.png"), min_size, min_size);
	loadimage(&role_up2, _T("role_up2.png"), min_size, min_size);
	loadimage(&role_up3, _T("role_up3.png"), min_size, min_size);
	mask_image_role_up1 = transparency_map(role_up1);
	mask_image_role_up2 = transparency_map(role_up2);
	mask_image_role_up3 = transparency_map(role_up3);

	loadimage(&role_image, _T("role.png"), min_size, min_size);
	loadimage(&role_down2, _T("role_down2.png"), min_size, min_size);
	loadimage(&role_down3, _T("role_down3.png"), min_size, min_size);
	mask_image_role = transparency_map(role_image);
	mask_image_role_down2 = transparency_map(role_down2);
	mask_image_role_down3 = transparency_map(role_down3);


}

IMAGE transparency_map(IMAGE target_image)
{
	int width = target_image.getwidth();
	int hight = target_image.getheight();

	IMAGE mask_image(width, hight);

	DWORD* target_image_pointer = GetImageBuffer(&target_image);//ָ���ͼ�����ص�ָ��
	DWORD* mask_image_pointer= GetImageBuffer(&mask_image);//ָ������ͼ�����ص�ָ��

	for (int i = 0; i < width * hight; i++)
	{
		if (target_image_pointer[i] == 0x000000)
		{
			mask_image_pointer[i] = WHITE;
		}
		else
			mask_image_pointer[i] = BLACK;
	}
	return mask_image;
}


void mapdraw_rolemove()
{
	for (int i = role.x - 1; i <= role.x + 1; i++)
	{
		for (int j = role.y - 1; j <= role.y + 1; j++)
		{
			if (map[i][j] == space)
			{
				putimage(j * min_size, i * min_size, &space_image);
			}
			if (map[i][j] == road)
			{
				putimage(j * min_size, i * min_size, &road_image);
			}
		}
	}
	switch (turn)//turn�ĳ�ʼֵΪ4��Ϊ�����ý�ɫһ��ʼ����
	{
	case left1:
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_left2, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_left2, SRCPAINT);
		Sleep(50);
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_left3, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_left3, SRCPAINT);
		Sleep(50);
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_left1, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_left1, SRCPAINT);
		break;
	case right1:
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_right2, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_right2, SRCPAINT);
		Sleep(50);
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_right3, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_right3, SRCPAINT);
		Sleep(50);
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_right1, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_right1, SRCPAINT);
		break;
	case up:
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_up2, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_up2, SRCPAINT);
		Sleep(50);
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_up3, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_up3, SRCPAINT);
		Sleep(50);
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_up1, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_up1, SRCPAINT);
		break;
	case down:
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_down2, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_down2, SRCPAINT);
		Sleep(50);
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role_down3, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_down3, SRCPAINT);
		Sleep(50);
		putimage(role.y * min_size, role.x * min_size, &space_image);
		putimage(role.y * min_size, role.x * min_size, &mask_image_role, SRCAND);
		putimage(role.y * min_size, role.x * min_size, &role_image, SRCPAINT);
		break;
	default:
		return;
		break;
	}
}

void mapdraw()
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row+6; j++)
		{
			switch (map[i][j])
			{
			case space:
				putimage(j * min_size, i * min_size, &space_image);
				break;
			case wall:case edge:
				putimage(j * min_size, i * min_size, &wall_image);
				break;
			case door:
				putimage(j * min_size, i * min_size, &door_image);
				break;
			case ball:
				putimage(j * min_size, i * min_size, &space_image);
				putimage(j * min_size, i * min_size, &mask_image_role, SRCAND);//Ŀ��ͼ�� = Ŀ��ͼ�� AND Դͼ��
				putimage(j * min_size, i * min_size, &role_image, SRCPAINT);//	Ŀ��ͼ�� = Ŀ��ͼ�� OR Դͼ��
				break;
			case help:
				putimage(j * min_size, i * min_size, &help_image);
				break;
			case board:
				setfillcolor(RGB(105,105,105));
				solidrectangle(j * min_size, i * min_size, (j + 1) * min_size, (i + 1) * min_size);
				break;
			default:
				break;
			}
		}
	}
	mapdraw_rolemove();
	gamehelp_graph();
}

void gamehelp_graph()
{
	settextcolor(RGB(100, 212, 241));
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, _T("�����п�"));
	outtextxy(760, 85, "��ӭ����ħ���Թ�");
	outtextxy(760, 125, "�뿪ʼ���ð�գ�");

	settextcolor(RGB(100, 212, 241));

	settextstyle(20, 0, _T("�����п�"));
	outtextxy(760, 205, "��ʹ�á�������");
	outtextxy(760, 235, "���ɲ��ݽ�ɫ");
	outtextxy(760, 265, "�����밴��1��");
	outtextxy(760, 295, "�˳��밴��2��");

	settextcolor(RGB(100, 212, 241));

	settextstyle(20, 0, _T("�����п�"));
	outtextxy(760, 385, "����Ϸ��ͼƬ�ز�");
	outtextxy(760, 425, "ȫ�����ħ����Ϸ");
}


void showmap()
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row+6; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

void gameovergraph()
{
	mciSendString("close c", NULL, 0, NULL);
	mciSendString("open dooropen.mp3 alias m", NULL, 0, NULL);
	mciSendString("play m", NULL, 0, NULL);
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row + 6; j++)
		{
			if(map[i][j]==door)
			{
				putimage(j * min_size, i * min_size, &door_image1);
				Sleep(1000);
				putimage(j * min_size, i * min_size, &door_image2);
				Sleep(1000);
				putimage(j * min_size, i * min_size, &door_image3);
				Sleep(1000);
			}
		}
	}
	mciSendString("close m", NULL, 0, NULL);


	mciSendString("open game_over.mp3 alias q", NULL, 0, NULL);
	mciSendString("play q repeat", NULL, 0, NULL);
	closegraph();
	initgraph(500, height);
	
	settextstyle(30, 0, _T("�����п�"));                     
	settextcolor(WHITE);
	outtextxy(165, 110, "��ϲ�㣬����");
	outtextxy(135, 140, "��ɹ�������ħ��");

	outtextxy(165, 410, "������Ϸ��2");
	outtextxy(135, 440, "���´��أ������");

}


void gamebegingraph()
{
	
	mciSendString("close q", NULL, 0, NULL);
	mciSendString("open pre_game.mp3 alias t", NULL, 0, NULL);
	mciSendString("play t repeat", NULL, 0, NULL);

	initgraph(500 ,600);

	RECT R1 = { r[0][0],r[0][1],r[0][2],r[0][3] };
	RECT R2 = { r[1][0],r[1][1],r[1][2],r[1][3] };
	RECT R3 = { r[2][0],r[2][1],r[2][2],r[2][3] };

	RECT R4 = { r[3][0],r[3][1],r[3][2],r[3][3] };

	settextstyle(100, 0, _T("�����п�"));
	settextcolor(WHITE);
	outtextxy(65, 90, "ħ���Թ�");

	settextstyle(40, 0, _T("Brush Script MT"));
	outtextxy(65, 190, "welcome to Magic Tower Labyrinth");

	settextstyle(80, 0, _T("�����п�"));
	drawtext("��", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext("��ͨ", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("����", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	settextstyle(30, 0, _T("�����п�"));
	drawtext("�Զ���", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	int event = 0;//��¼�����һ�ε�λ�ð�ť��Ϣ
	while (true)
	{
		mouse = GetMouseMsg();
		switch(mouse.uMsg)
		{ 
		case WM_MOUSEMOVE:
     		setrop2(R2_XORPEN);	//�����Ǳʺ���Ļ����ɫ����ϣ������������е���ɫ��ϡ�
			//�涨�˻�������ɫ����Ļ��ɫ�Ļ�Ϸ�ʽ
			setlinecolor(LIGHTCYAN);
			setlinestyle(PS_SOLID, 3);
			setfillcolor(WHITE);
			if (button_judge(mouse.x, mouse.y) != 0)
			{
				if (event != button_judge(mouse.x, mouse.y))//ֻ�����λ�ú���һ�β�һ����ʱ��Żᴥ������
				{
					event = button_judge(mouse.x, mouse.y);//��¼��һ�δ����İ�ť
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);
				}
			}
			else
			{
				if (event != 0)//�ϴδ����İ�ťδ������Ϊԭ������ɫ
				{
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//����ͬ��Ϊԭ����ɫ
					event = 0;
				}
			}
			break;
		case WM_LBUTTONDOWN:
			setrop2(R2_NOT);//��������Ļ��ɫ�ķ��档
			for (int i = 0; i <= 10; i++)
			{
				setlinecolor(RGB(250 * i, 250 * i, 250 * i));
				circle(mouse.x, mouse.y, 2 * i);
				Sleep(20);
				circle(mouse.x, mouse.y, 2 * i);
			}
			switch (button_judge(mouse.x, mouse.y))
			{
			case 1:
				game_level = 2;
				FlushMouseMsgBuffer();
				flag_gamebegin = 1;
				break;
			case 2:
				game_level = 1;
				FlushMouseMsgBuffer();
				flag_gamebegin = 1;
				break;
			case 3:
				game_level = 0;
				FlushMouseMsgBuffer();
				flag_gamebegin = 1;
				break;
			case 4:
				game_level = 100;
				FlushMouseMsgBuffer();
				flag_gamebegin = 1;
				break;
			default:
				FlushMouseMsgBuffer();
				break;
			}
			break;
		defalut:
			break;
		}
		if (flag_gamebegin == 1)
		{
			flag_gamebegin = 0;//�Ѿ��ɹ�ѡ����Ϸģʽ������whileѭ��
			break;
		}
	}
	closegraph();
	setrop2(R2_COPYPEN);//���������ǻ��ʵ���ɫ
}

//�ж����λ��
int button_judge(int x, int y)
{
	if (x > r[0][0] && x<r[0][2] && y>r[0][1] && y < r[0][3])return 1;
	if (x > r[1][0] && x<r[1][2] && y>r[1][1] && y < r[1][3])return 2;
	if (x > r[2][0] && x<r[2][2] && y>r[2][1] && y < r[2][3])return 3;
	if (x > r[3][0] && x<r[3][2] && y>r[3][1] && y < r[3][3])return 4;
	return 0;
}
