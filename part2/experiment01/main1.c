#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

int main(void)
{
	List L;
	int i, r;
	printf("list addr = %p\tsize = %d\tMaxSize = %d\n", L.list, L.size, L.MaxSize);
	InitList(&L, 100);
	printf("list addr = %p\tsize = %d\tMaxSize = %d\n", L.list, L.size, L.MaxSize);
	
	while (1) {
		printf("请输入元素值，输入0结束插入操作：");
		fflush(stdin);
		scanf("%d", &i);
		if (i == 0) {
			break;
		}
		printf("请输入插入位置：");
		scanf("%d", &r);

		InsertList(&L, i, r-1);
		printf("线性表为：\n");
		OutputList(&L);
	}

	while (1) {
		printf("请输入查找元素值，输入0结束查找操作：");
		fflush(stdin);
		scanf("%d", &i);
		if (i == 0) {
			break;
		}
		r = FindList(&L, i);
		if (r < 0) {
			printf("没找到\n");
		} else {
			printf("有符合条件的元素，位置为：%d\n线性表为：\n", r+1);
			OutputList(&L);
		}
	}

	while (1) {
		printf("请输入删除的元素，输入0结束删除操作：");
		fflush(stdin);
		scanf("%d", &i);
		if (i == 0) {
			break;
		}
		r = DeleteList1(&L, i);
		if (r == 0) {
			printf("没找到\n");
		} else {
			printf("有符合条件的元素有%d个，\n删除后线性表为：\n", r);
			OutputList(&L);
		}
	}

	while (1) {
		printf("请输入删除元素的位置，输入0结束删除操作：");
		fflush(stdin);
		scanf("%d", &r);
		if (r == 0) {
			break;
		}
		i = DeleteList2(&L, r-1);
		if (i < 0) {
			printf("位置越界\n");
		} else {
			printf("线性表为：\n");
			OutputList(&L);
		}
	}
	return 0;
}