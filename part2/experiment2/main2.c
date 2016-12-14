/**
 * 将一个头结点指针为ａ的单链表Ａ分解成两个单链表Ａ和Ｂ，其头结点指针分别为ａ和ｂ，使得Ａ链表含有原链表Ａ中序号为奇数的元素，Ｂ链表含有原链表Ａ中序号为偶数的元素，且保持原来的相对顺序。
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#define N 11

void f (List A, List B)
{
	int i = 1;
	Node *a = A, *b = B;   //头结点指针分别为ａ，ｂ 
	Node * p;  //保存序号偶数的结点
	while (a->next) {
		if ( i%2 == 0 ) { //如果是偶数
			p = a->next;
			a->next = p->next;  //跳过ｐ结点相连

			b->next = p;  // p 接上　Ｂ链表
			b = p;
		} else {
			a = a->next;
		}
		i++;
	}
	b->next = NULL; //使Ｂ链正常结束
}

int main()
{
	int i;
	int data[N] = {12, 34, 11, 54, 71, 24, 55, 34, 80, 5, 25}; 
	List A, B;
	InitList(&A);
	InitList(&B);

	//初始化数据
	for (i = 0; i < N; ++i) {
		InsertList1(A, data[i], i+1);
	}
	printf("原始链表Ａ");
	OutputList(A);
	f(A,B);

	printf("A:");
	OutputList(A);

	printf("B:");
	OutputList(B);

	return 0;
}