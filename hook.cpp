#include <string.h>
#include "struct.h"
extern btn btn_arr[128];
extern int selected;

void click_hook(int x, int y)
{
	for(int i = 127; i>=0;i--)//latest button interact first
	{
		int len = strlen(btn_arr[i].str);
		if((btn_arr[i].y == y)&&(btn_arr[i].x<=x)&&(btn_arr[i].x+len>=x))
		{
			selected = i;
			btn_arr[i].func();
		}
	}
}