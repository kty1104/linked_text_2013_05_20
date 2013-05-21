#ifndef STRUCT_H
#define STRUCT_H
typedef struct _btn
{
	char str[128];
	char x,y;
	char bg,fg;
	void (*func)();
} btn;

#endif