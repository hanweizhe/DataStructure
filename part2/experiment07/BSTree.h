#ifndef _BSTREE_H
#define _BSTREE_H
#include <stdbool.h>

typedef struct
{
	char petname[32];
	char petkind[32];
}ElemType;

typedef struct node
{
	ElemType item;
	struct node * left;
	struct node * right;
}Node;

typedef struct
{
	Node * root;
	int size;
}BSTree;


/********************************
*	操作：把一个树初始化为空树  		*
* 操作前：T 指向一棵树				*
* 操作后：该树已被初始化为空树  		*
********************************/
void InitBSTree(BSTree * T); 

/********************************************
*	操作：确定树是否为空树					    *
* 操作前：T 指向一棵树						    *
* 操作后：如果树为空则返回true,否则返回false  		*
********************************************/
bool BSTreeIsEmpty(const BSTree * T);

/********************************************
*	操作：确定树是否已满					  	*
* 操作前：T 指向一棵树						  	*
* 操作后：如果树已满则返回true,否则返回false  		*
********************************************/
bool BSTreeIsFull(const BSTree * T);

/**************************************
*	操作：向树中添加一个项目				  *
* 操作前：T 指向一棵树, item是待添加的项	  *
* 操作后：可以添加则返回true,否则返回false  *
**************************************/
bool AddItem(BSTree * T, ElemType * item);

/**************************************
*	操作：向树中删除一个项目				  *
* 操作前：T 指向一棵树, item是待删除的项	  *
* 操作后：成功删除则返回true,否则返回false  *
**************************************/
bool DeleteItem(BSTree * T, ElemType * item);

/**
 * 向树中查找一个项目
 * @param  T    指向一棵树
 * @param  item 带查找项目
 * @return      是否找到
 */
bool InBSTree(const BSTree * T, ElemType * item);


/**
 * 查找一个项目，pfun指向的函数被作用于树中每个项目
 * @param T 	指向一棵树
 * @param pfun	指向一个没有返回值的函数
 */
void Traverse(const BSTree * T, void (* pfun)(ElemType item));

/**
 * 删除整棵树
 * @param T 已初始化的树
 */
void DeleteAll(BSTree * T);

#endif