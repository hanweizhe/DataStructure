#ifndef _LINKLIST_H_
#define _LINKLIST_H_

/**
 * 定义链表结构
 */
typedef struct Node
{
	int data;			//数据域
	struct Node *next;   //指针域
}Node, *List;


/**
 * 初始化链表
 * @param L
 */
void InitList (List * L);


/**
 * 生成一个结点
 * @param  data 数据
 * @return      结点
 */
Node * CreateNode (int item);

/**
 * 向链表的指定位置插入元素
 * @param  L
 * @param  item 记录值
 * @param  rc   插入位置
 */
void InsertList1 (List L, int item, int rc);

/**
 * 向有序链表的指定位置插入元素
 * @param  L
 * @param  item 记录值
 */
void InsertList2 (List L, int item);

/**
 * 输出操作
 * @param L
 */
void OutputList (List L);


/**
 * 查找元素的位置
 * @param  L
 * @param  item 待查找元素
 * @return      >=1:元素位置,　-1:没找到
 */
int FindList (List L, int item);


/**
 * 删除指定元素值的链表记录
 * @param  L
 * @param  item
 * @return 　删除个数
 */
int DeleteList(List L,int item);

/**
 * 释放链表空间
 * @param L
 */
void FreeList (List L);
#endif