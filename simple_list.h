#ifndef _SIMPLE_LIST_
#define _SIMPLE_LIST_
typedef struct _row{
	char text[256];
	int  time;
	struct _row *next;
} LinkList;

extern LinkList *create(int n);
extern void change(LinkList *list, int n);
extern void delet(LinkList *list, int n); 
extern LinkList *insert(LinkList *list, int n); 

#endif
