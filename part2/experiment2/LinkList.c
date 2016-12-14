#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

void InitList (List * L)
{
	//生成头结点
	(*L) = (List)malloc(sizeof(Node));
	(*L)->next = NULL;
}

Node * CreateNode (int item)
{
	Node * u = (List)malloc(sizeof(Node));
	u->data = item;
	u->next = NULL;
	return u;
}

void InsertList1 (List L, int item, int rc)
{
	//u：新结点　q:插入点前驱　
	Node *q = L;  
	Node *u = CreateNode(item);

	int i;
	for (i = 1; i < rc && q->next != NULL; i++) {
		q = q->next;
	}
	u->next = q->next;
	q->next = u;
}

void InsertList2 (List L, int item)
{
	//u：新结点　q:插入点前驱
	Node *q = L;  
	Node *u = CreateNode(item);

	while (q->next != NULL) {
		if (item < q->next->data) { 
			//多次用到这两句插入操作
			u->next = q->next;
			q->next = u;
			break;
		}
		q = q->next;
	}
}

void OutputList (List L)
{
	Node *q = L; 
	printf("\n链表如下：\n");
	while (q->next != NULL) {
		printf("%d\n", q->next->data); 
		q = q->next;
	}
	printf("\n");
}

int FindList (List L, int item)
{
	int i;
	Node *q;  

	for (i = 1, q = L->next; q != NULL; q = q->next, i++) {
		if (item == q->data) { 
			return i;
		}
	}
	return -1; //没找到
}
int DeleteList (List L, int item)
{
	int cnt = 0;
	Node * q;		//删除结点前驱
	Node * tmp;		//删除结点
	for (q = L, tmp = q->next; tmp != NULL; q = tmp, tmp = q->next) {
		if (tmp->data == item) {	//找到，进行删除操作
			q->next = tmp->next;
			free(tmp);
			cnt++;		//符合数加一
		}
	}
	return cnt;
}

void FreeList (List L)
{
	Node * head = L;   //保存L的头结点
	Node * tmp = L->next;  
	while (tmp) {
		L = tmp->next;
		free(tmp);
		tmp = L;
	}
	head->next = NULL;	
}