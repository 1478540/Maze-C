#include"head.h"

int row = 18, column = 15;
int map[max][max];
int game_level;
coordinate direction[4] = { {0,1},{0,-1},{1,0},{-1,0} };
MOUSEMSG mouse;
coordinate role;
coordinate end_door;
int r[4][4] = { {150,300,350,380},{150,400,350,480},{150,500,350,580},{400,560,500,600} };

int flag = 0;
int flag_gamebegin = 0;
int turn;

IMAGE road_image;
IMAGE wall_image;
IMAGE space_image;
IMAGE door_image;
IMAGE door_image1;
IMAGE door_image2;
IMAGE door_image3;
IMAGE help_image;

IMAGE role_image;
IMAGE role_down2;
IMAGE role_down3;
IMAGE mask_image_role_down2;
IMAGE mask_image_role_down3;
IMAGE mask_image_role;

IMAGE role_left1;
IMAGE role_left2;
IMAGE role_left3;
IMAGE mask_image_role_left1;
IMAGE mask_image_role_left2;
IMAGE mask_image_role_left3;

IMAGE role_right1;
IMAGE role_right2;
IMAGE role_right3;
IMAGE mask_image_role_right1;
IMAGE mask_image_role_right2;
IMAGE mask_image_role_right3;

IMAGE role_up1;
IMAGE role_up2;
IMAGE role_up3;
IMAGE mask_image_role_up1;
IMAGE mask_image_role_up2;
IMAGE mask_image_role_up3;

