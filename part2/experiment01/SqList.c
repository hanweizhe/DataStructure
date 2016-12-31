#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

void InitList (List * L, int ms)
{
	L->list = (int *)malloc(ms * sizeof(int));
	if ( L->list == NULL ) {
		printf("内存申请错误！\n");
		exit(1);
	}
	L->size = 0;
	L->MaxSize = ms;
}

int InsertList (List * L, int item, int rc)
{
	int i;
	if (L->size >= L->MaxSize) { //线性表已满
		return -1;
	}
	//修改不正确的位置
	if (rc < 0) rc = 0;
	if (rc > L->size) rc = L->size;

	for (i = L->size - 1; i >= rc; i--) { //将线性表后移
	 	L->list[i+1] = L->list[i];
	} 
	//插入
	L->list[rc] = item;
	L->size++;
	return 0;
}

void OutputList (List * L)
{
	int i;
	for (i = 0; i < L->size; ++i) {
		printf("%d\n", L->list[i]);
	}
}

int FindList (List * L, int item)
{
	int i;
	for (i = 0; i < L->size; ++i) {
		if (L->list[i] == item) {		//找到相同的元素，返回位置
			return i;
		}
	}
	return -1;		//没找到
}

int DeleteList1 (List * L, int item)
{
	int i, rc, cnt = 0;
	rc = FindList(L, item);
	while (rc != -1) {
		for (i = rc; i < L->size-1; ++i) {
			L->list[i] = L->list[i+1];
		}
		L->size--;
		cnt++;
		rc = FindList(L, item);	
	}
	return cnt;
}

int DeleteList2 (List * L, int rc)
{
	int i;
	//不正确的位置
	if (rc < 0 || rc >= L->size) {
		return -1;
	}
	for (i = rc; i < L->size-1; ++i) {
		L->list[i] = L->list[i+1];
	}
	L->size--;	
	return rc;
}