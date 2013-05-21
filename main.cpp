#include <Windows.h>
#include <stdio.h>
#include "struct.h"

extern btn btn_arr[128];
void draw_all();
void click_hook(int x, int y);
void new_btn(char * str, char x, char y, char bg, char fg, void (*func)());
void process_mouse();
void default_func()
{
	MessageBox(0,L"button clicked!",L"...!",MB_OK);
}
void set_color(char bg, char fg);
void create_new_btn()
{
	char label[128];
	int x, y, bg,fg;
	set_color(0,14);
	printf("label:");
	scanf("%s",label);
	printf("x:");
	scanf("%d",&x);
	printf("y:");
	scanf("%d",&y);
	printf("background color:");
	scanf("%d",&bg);
	printf("foreground color:");
	scanf("%d",&fg);

	new_btn(label,(char)x,(char)y,(char)bg,(char)fg,default_func);
}
void init()
{
	memset(btn_arr,0,sizeof(btn)*128);
}
int main()
{
	new_btn("Click here for a new button!",10, 10, 14, 0,create_new_btn);

	while(true)
	{
		process_mouse();
	}

}

void process_mouse()
{
	
	HANDLE hIn;
	HANDLE hOut;
	INPUT_RECORD InRec;
	DWORD NumRead;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ReadConsoleInput(hIn,&InRec,1,&NumRead);

	switch (InRec.EventType)
	{
		case MOUSE_EVENT:
			if(InRec.Event.MouseEvent.dwButtonState == 1)
			{
				int x = InRec.Event.MouseEvent.dwMousePosition.X;
				int y = InRec.Event.MouseEvent.dwMousePosition.Y;
				click_hook(x,y);
			}
			
		break;
	}
}