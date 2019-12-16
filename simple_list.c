#include <stdio.h>

#include "simple_list.h"

LinkList *create(int n){
	LinkList *head, *node, *end;
	head = (LinkList*)malloc(sizeof(LinkList));
	end = head;
	for(int i = 0; i < n; i++){
		node = (LinkList*)malloc(sizeof(LinkList));
		end->next = node;
		end = node;		
	}
	end->next = NULL;
	return head;
}

//改变第n+1个节点的值
void change(LinkList *list, int n){
	LinkList *t = list;
	int i = 0;
	while(i < n && t != NULL){
		t = t->next;
		i++;
	}
	if(t != NULL){
		puts("输入要修改的值");
		scanf("%s", &t->text);
	}else{
		puts("节点不存在");
	}
}

//删除第n个节点
void delet(LinkList *list, int n){
	LinkList *t = list, *in;
	int i = 0;
	while (i < n && t != NULL){
		in = t;
		t = t->next;
		i++;
	}
	if(t != NULL){
		in->next = t->next;
		free(t);
	}else{
		puts("节点不存在");
	}
}

//插入到第n个节点后面
LinkList *insert(LinkList *list, int n){
	LinkList *t = list, *in;
	int i = 0;
	while(i < n && t != NULL){
		t = t->next;
		i++;
	}
	if(t != NULL){
		in = (LinkList*)malloc(sizeof(LinkList));
		in->next = t->next;
		t->next = in;		
	}else{
		puts("节点不存在");
	}
	return in;
}

//清空链表



