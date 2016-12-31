#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main()
{
	List L;
	int op, i, rc;
	InitList(&L);
	
	while (1) {
		printf("请选择操作：\n１：指定位置追加\t２：升序追加\t３：查找结点\n");
		printf("４：删除结点    \t５：输出链表  \t６：清空链表\n０：退出\n");
		fflush( stdin );
		scanf("%d", &op);
		switch (op) {
			case 0: 			//退出
				return -1;
			case 1:
				printf("请输入新增结点的键值和位置：\n");
				scanf("%d%d", &i, &rc);
				InsertList1(L, i, rc);
				break;
			case 2:
			    printf("请输入新增结点的键值\n");
			    scanf("%d", &i);
			    InsertList2(L, i);
			    break;
			case 3:
				printf("请输入要查找结点的键值\n");    
				scanf("%d", &i);
				rc = FindList(L, i);
				if (rc > 0) {
					printf("位置为[%d]\n", rc);
				} else {
					printf("没找到\n");
				}
				break;
			case 4:
				printf("请输入要删除结点的键值\n");
				scanf("%d", &i);
				rc = DeleteList(L, i);
				if (rc > 0) {
					printf("发现有%d个，删除成功！\n", rc);
				} else {
					printf("没找到\n");
				}
				break;
			case 5:
				OutputList(L);
				break;
			case 6:
			    FreeList(L);
			    break;
			default:
				printf("请输入0～6\n");
				break;
		}
	}
	return 0;
}