#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "double_linklist.h"

//创建双向链表
pElem CreatList()
{
	pElem head = (pElem)malloc(sizeof(eElem));
	assert(head != NULL);
	head->front = NULL;
	head->next = NULL;	
	
	return head;	
}

//头部插入
void insertElem(pElem head ,int data)
{
	if(head == NULL){
		printf("The list is empty.\n");
		return;
	}
	pElem tmpHead = head;
	if(tmpHead->next == NULL){
		/*当双向链表只有一个头节点时*/
		pElem addition = (pElem)malloc(sizeof(eElem));
		assert(addition != NULL)	;
		addition->data = data;
		addition->next = tmpHead->next;
		tmpHead->next = addition;
		addition->front = tmpHead; 
	}
	else{
		/*当双向链表不只一个头节点时*/
		pElem addition = (pElem)malloc(sizeof(eElem));
		assert(addition != NULL);
		addition->data = data;
		tmpHead->next->front = addition;
		addition->front = tmpHead;
		addition->next = tmpHead->next;
		tmpHead->next = addition;
	}
}
void insertElemTail(pElem head, int data){//尾插
	pElem tmpHead = head;
	while(head->next != NULL){
		head = head->next;
	}
	pElem addition = (pElem)malloc(sizeof(eElem));
	addition->data = data;
	addition->next = head->next;
	addition->front = head;
	head->next = addition;
}
//双向链表的便利
void IlluList(pElem head){
	if(head == NULL){
		printf("The list is empty.\n");
		return;
	}
	pElem tmpHead = head;
	while(tmpHead->next != NULL){
		tmpHead = tmpHead->next;
		printf("%d\n",tmpHead->data);
	}
	while(tmpHead->front->front != NULL){
		printf("%d\n",tmpHead->data);
		tmpHead = tmpHead->front;
	}	
	printf("%d\n",tmpHead->data);
	return;
}

void DeleteElem(pElem head,int data)
{
	if(head == NULL){
		printf("The list is empty.\n");
		return;
	}
	pElem tmpHead = head;
	while(tmpHead->next != NULL){
		tmpHead = tmpHead->next;
		if(tmpHead->data == data){
			tmpHead->front->next = tmpHead->next;
			tmpHead->next->front = tmpHead->front;
			break;
		}
	}
	free(tmpHead); //释放内存
}

void DestroyList(pElem head)
{
	pElem tmp;
	while(head->next != NULL){
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}


