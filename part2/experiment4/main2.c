/*环形队列*/
#include <stdio.h>
#include <stdlib.h>

#define MAXN 11   //环形队列的存储长度为10

/**
 * 进队操作
 */
int EnQueue (int *queue, int maxn, int *head, int *tail, int x)
{
	/*进队操作，返回1为队满*/
	if ( (*tail+1) % maxn == *head) {
		return 1;
	} 
	//队尾指针+1
	*tail = (*tail + 1) % maxn;
	//元素进队尾
	queue[*tail] = x;
	return 0;   
}

/**
 * 出队操作， 返回1为队空
 */
int DeQueue (int *queue, int maxn, int *head, int *tail, int *cp)
{
	if (*head == *tail) { //队空
		return 1;
	}
	*head = (*head + 1) % maxn;	//队首指针+1
	*cp = queue[*head];  //取出队首元素
	return 0;
}

//输出队列的元素
void OutputQueue (int * queue, int maxn, int h, int t)
{
	while (h != t) { 
		h = (h+1)%maxn;
		printf("%d \n", queue[h]);
	}
	printf("\n");
}

int main (void)
{
	int q[MAXN]; 	//假设环形队列的元素类型为int
	int q_h = 0, q_t = 0;	//初始化队列
	int op, i;

	while (1) {
		printf("请选择操作,1.进队  2.出队  0.退出\n");
		fflush(stdin);
		scanf("%d", &op);
		switch(op) {
			case 0:
			    return 0;
			case 1:
				printf("请输入进队元素：\n");
				scanf("%d", &i);
				if (EnQueue(q, MAXN, &q_h, &q_t, i) != 0) {
					printf("队列满\n");
				} else {
					printf("队列内元素为：\n");
					OutputQueue(q, MAXN, q_h, q_t);	
				}
				break;
			case 2:
			    if (DeQueue(q, MAXN, &q_h, &q_t, &i) == 0) {
			    	printf("出队元素为：[%d],队列内元素为：\n", i);
					OutputQueue(q, MAXN, q_h, q_t);	
			    } else {
			    	printf("队空\n");
			    }
                break;
		}
	}

	return 0;
}