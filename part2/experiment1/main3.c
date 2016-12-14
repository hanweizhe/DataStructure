/*要求以较高的效率删除线性表中元素值在ｘ到ｙ（ｘ和ｙ自定）之间的所有元素*/
#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"
#define N 20
/**
 * 删除线性表中元素值在ｘ到ｙ（ｘ和ｙ自定）之间的所有元素
 * @param L
 * @param x  int
 * @param y  int
 */
void DeleteList3(List * L, int x, int y);


int main(void)
{
	int x, y;
	int list[N] = {2, 5, 15, 30, 1, 40, 17, 50, 9, 21, 32, 8, 41, 22, 49, 31, 33, 18, 80, 5};
	List L = {list, N, N};

	OutputList(&L);
	printf("请输入x和y,代表删除线性表中元素值[x, y]的元素。\n");
	scanf("%d %d", &x, &y);
	DeleteList3(&L, x, y);
	printf("删除后：\n");
	OutputList(&L);
	return 0;
}

void DeleteList3(List * L, int x, int y)
{
	int i, j;
	List tmp;    //将不在ｘ，ｙ　范围的值插入在ｔｍｐ中
	InitList(&tmp, L->MaxSize);
	for (i = 0; i < L->size; i++) { 			//遍历线性表
		if (L->list[i] > y || L->list[i] < x) { 	//不在ｘ和ｙ之间的保留
			InsertList(&tmp, L->list[i], tmp.size);
		}
	}
	(*L) = tmp;
}