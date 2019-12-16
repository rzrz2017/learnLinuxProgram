#ifndef _DOUBLE_LINKLIST_
#define _DOUBLE_LINKLIST_
typedef struct List{
	int time;
	char text[256];
	struct List *next;
	struct List *front;
};
typedef struct List* pElem;
typedef struct List eElem;

extern pElem CreatList(void);
extern void insertElem(pElem head, int time, char text[]);
extern void IlluList(pElem head); 
extern void DeleteElem(pElem head, char text[]);
extern void DestroyList(pElem head); 
extern void insertElemTail(pElem head, int time, char text[]);

#endif
