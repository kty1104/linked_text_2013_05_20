#include <Windows.h>
#include <stdio.h>
#include "struct.h"
extern btn btn_arr[128];
extern int selected;


void goto_xy(int x, int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
void set_color(char bg, char fg)
{
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE ); 
	SetConsoleTextAttribute ( h, ((bg%16)<<4)|(fg%16));
}

void draw_btn(int i)
{
	char bg = btn_arr[i].bg;
	char fg = btn_arr[i].fg;
	int x = btn_arr[i].x;
	int y = btn_arr[i].y;
	set_color(bg,fg);
	goto_xy(x,y);
	printf("%s",btn_arr[i].str);
}


void draw_all()
{
	int k = 80*25;
	goto_xy(0,0);
	while(k--)
	{
		printf(" ");
	}

	for(int i = 0; i<128;i++)
	{
		draw_btn(i);
	}
}


