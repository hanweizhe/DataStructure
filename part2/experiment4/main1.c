/*链接队列*/
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {		//定义队列结构
	int data;				//队列元素类型为int
	struct queue *link;
}Queue;

/**
 * 进队操作
 */
void EnQueue (Queue ** head, Queue ** tail, int x)
{
	Queue *p = (Queue *)malloc(sizeof(Queue));
	p->data = x;
	p->link = NULL; //队尾指向空
	//队首为空，即为空队列
	if (*head == NULL) {
		*head = *tail = p;
	} else {
		(*tail)->link = p;   //新单元进队列尾
		*tail = p;		//队尾指向新入队单元
	}
}

/**
 * 出队操作
 * @param  head 队首
 * @param  tail 队尾
 * @param  cp   存储队首单元
 * @return      状态码
 */
int DeQueue (Queue ** head, Queue ** tail, int *cp)
{
	Queue *p;
	p = *head;
	if (*head == NULL) { //队空
		return 1;
	}
	*cp = (*head)->data;
	*head = (*head)->link;
	if (*head == NULL) { //如果队列原本只有一个单元
		*tail = NULL;	//删除仅剩的单元后队尾也指向NULL
	}
	free(p);	//释放单元

	return 0;
}

/**
 * 输出队列
 * @param head 
 */	
void OutputQueue (Queue * head)
{
	while (head) {
		printf("%d ", head->data);
		head = head->link;
	}
	printf("\n");
}

int main (void)
{
	Queue *head, *tail;
	int op, i;
	//初始化队列
	head = tail = NULL;  

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
				EnQueue(&head, &tail, i);
				printf("队列内元素为：\n");
				OutputQueue(head);
				break;
			case 2:
			    if (DeQueue(&head, &tail, &i) == 0) {
			    	printf("出队元素为：[%d],队列内元素为：\n", i);
			    	OutputQueue(head);
			    } else {
			    	printf("队空\n");
			    }
                break;
		}
	}
	return 0;
}

