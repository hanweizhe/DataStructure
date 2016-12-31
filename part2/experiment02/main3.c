/**
 * 逆置链表
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#define N 11

void reverse(List L)
{
	Node * p = L->next;	//遍历Ｌ的结点
	Node * pOld = NULL; //新链表的较后结点
	Node * pNew;	//pOld的前一个结点
	while (p) {
		pNew = p->next;　　//保存p的下一个结点

		p->next = pOld;　　//改变链表方向

		pOld = p;　　

		p = pNew;
	}
	L->next = pOld;
}

int main()
{
	int i;
	int data[N] = {12, 34, 11, 54, 71, 24, 55, 34, 80, 5, 25}; 
	List L;
	InitList(&L);

	//初始化数据
	for (i = 0; i < N; ++i) {
		InsertList1(L, data[i], i+1);
	}
	OutputList(L);

	printf("逆置后");
	reverse(L);

	OutputList(L);

	return 0;
}