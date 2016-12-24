/**
 * 问题描述： 采用随机函数产生职工的工号和他所完成产品个数的数据信息，对同一职工多次完成的产品个数进行累计，
 * 最后按“职工完成产品数量的名次，该名次每位职工完成的产品数量，同一名次的职工人数和他们的职工号”的格式输出。
 */
/**
 * 输出结果：
 * ORDER		QUANTITY		COUNT		NUMBER
 * 1			375				3			10		20		21
 * 4			250				2			3		5
 * 6			200				1			9
 * 7			150				2			11		14
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXQ 15   //最大工作量
#define MAXN 25	  //最大人数

typedef struct workman{
	int no;			//工人工号
	int q;			//完成数量
	struct workman * next;
}Workman;

/**
 * 初始化数据 生产一个存储所有员工信息的链表
 * @param  num 可以自定义员工人数
 * @return     
 */
Workman * InitData(int num)
{
	int i;
	
	srand((unsigned)time(NULL));
	//头结点，不存数据
	Workman * head = (Workman *)malloc(sizeof(Workman)); 
	head->next = NULL;

	Workman *newNode;	//新结点
	Workman *p = head;	//辅助结点
	for (i = 1; i <= num; i++) {
		//赋予结点数据
		newNode = (Workman *)malloc(sizeof(Workman)); 
		newNode->no = i;
		newNode->q = rand()%MAXQ + 1;
		//连接
		p->next = newNode;
		p = newNode;			
	}
	// 以NULL结束链表
	p->next = NULL;

	return head;
}

/**
 * 交换两个结点的数据
 * @param x [description]
 * @param y [description]
 */
void Swap (Workman *x, Workman *y)
{
	int tmp_no = x->no;
	int tmp_q = x->q;
	x->no = y->no;
	x->q = y->q;
	y->no = tmp_no;
	y->q = tmp_q;
}

/**
 * 链表排序
 * @param w 
 */
void Sort (Workman * w)
{
	Workman *i, *j;
	for (i = w->next; i != NULL; i = i->next) {
		for (j = w->next; j != NULL; j = j->next) {
			if (i->q < j->q) {
				Swap (i, j);
			}	
		}
	}
}

/**
 * 输出链表，用做测试
 * @param w 
 */
void Output(Workman * w)
{
	printf("职员工号\t\t完成产品数量\n");
	while (w->next) {
		printf("%d\t\t\t%d\n", w->next->no, w->next->q);
		w = w->next;
	}
}

/**
 * 打印题目想要的结果
 * @param w 
 */
void Print(Workman *w)
{
	int i, count = 1, order = 1, number[MAXN], quantity;
	workman * p = w->next; //遍历链表的结点
	printf("ORDER \t QUANTITY  COUNT  NUMBER\n");
	while ( p ) {
		number[0] = p->no;   
		while ( p->next ) { //如果有下一个结点
			//两个相邻结点的q相等
			if ( p->next->q == p->q ) {
				p = p->next;
				number[count++] = p->no;		 
			} else {
				quantity = p->q;
				break;
			}
		}
		
		printf("%5d \t %5d \t %5d \t %5d", order, quantity, count, number[0]);
		for (i = 1; i < count; i++) {
			printf("%6d", number[i]);
		}
		printf("\n");

		order += count;		//新排名 = 重复数量 + 旧排名
		count = 1; 			//重置重复数量
		p = p->next;
	}
}


int main()
{
	Workman * w = InitData(MAXN);
	Sort(w);
	Output(w);
	Print(w);
	return 0;
}