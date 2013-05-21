#include <string.h>
#include "struct.h"
extern btn btn_arr[128];
void draw_all();
int find_empty_index()
{
	for(int i = 0; i < 128; i++)
	{
		if(strcmp(btn_arr[i].str,"")==0)
		{
			return i;
		}
	}
	return -1;
}

void new_btn(char * str, char x, char y, char bg, char fg, void (*func)())
{
	int i;
	i = find_empty_index();
	strcpy(btn_arr[i].str,str);
	btn_arr[i].x = x;
	btn_arr[i].y = y;
	btn_arr[i].bg = bg;
	btn_arr[i].fg = fg;
	btn_arr[i].func = func;
	
	draw_all();
}

