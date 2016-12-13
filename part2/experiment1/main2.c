/*将两个有序的线性表进行合并，要求同样的数据只出现一次*/
#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"



/**
 * 合并线性表
 * @param  L1 
 * @param  L2 
 * @return    新的线性表
 */
List MergeList(List * L1, List * L2);

int main(void)
{
	int list1[15] = {2, 5, 7, 8, 10, 14, 19, 22, 25, 30};
	int list2[15] = {3, 5, 8, 9, 11, 18, 22, 28, 30, 32, 35};
	List L1 = {list1, 10, 15};
	List L2 = {list2, 11, 15};
	List L3 = MergeList(&L1, &L2);
	OutputList(&L3);
	return 0;
}

List MergeList(List * L1, List * L2)
{
	List L3;
	int i = 0, j = 0;
	int L1Size = L1->size, L2Size = L2->size;
	
	InitList(&L3, L1Size + L2Size);
	while (L1Size && L2Size) {
		if (L1->list[i] <= L2->list[j]) {
			InsertList(&L3, L1->list[i], L3.size);							
			if (L1->list[i] == L2->list[j]) {      
				j++;
				L2Size--;	//L2->list 移到下一个元素
			}
			i++;
			L1Size--;		//L1->list 移到下一个元素
		} else {
			InsertList(&L3, L2->list[j], L3.size);
			j++;
			L2Size--;	//L2->list 移到下一个元素
		}
	}

	//剩余的Ｌ１
	while (L1Size) {
		InsertList(&L3, L1->list[i], L3.size);
		i++;
		L1Size--;		//L1->list 移到下一个元素
	}

	//剩余的Ｌ2
	while (L2Size) {
		InsertList(&L3, L2->list[j], L3.size);
		j++;
		L2Size--;		//L2->list 移到下一个元素
	}

	return L3;
}
