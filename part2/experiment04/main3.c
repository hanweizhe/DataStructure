/**
 * 问题描述：假设只有一个医生，在一段时间内随机地来了几个病人，假设病人到达的时间间隔为0～14分钟之间的某个随机值，
 * 每个病人所需的处理时间为1～9分钟之间的某个随机值，使用队列结构进行模拟。
 *
 * 实现要求：要求输出医生的总等待时间和病人的平均等待时间。
 *
 * 程序设计思想：计算机在模拟事件处理时，按模拟环境中事件出现的顺序逐一处理，在本程序中体现为医生逐个为到达的医生看病。
 * 当一个病人就诊完毕，时间立即推进为下一个病人，中间时间为医生空闲时间。若一个病人还未就诊完毕，另有一个病人到达，则
 * 这些病人依次排队，等待就诊。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int arrive;		//定义病人到达时间
	int treat;		//病人处理时间
}Patient;

typedef struct queue {	//定义队列结构
	Patient data;
	struct queue * link;
}Queue;

/**
 * 进队操作
 */
void EnQueue (Queue ** head, Queue ** tail, Patient x)
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
int DeQueue (Queue ** head, Queue ** tail, Patient *cp)
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
		printf("到达时间：[%d]，处理时间：[%d]\n", head->data.arrive, head->data.treat);
		head = head->link;
	}
	printf("\n");
}

/**
 * 生成病人到达及处理时间的随机数列
 * @param pa 病人数组
 * @param n  病人数量
 */
void InitData (Patient *pa, int n)
{
	int parr = 0;
	int i;
	for (i = 0; i < n; ++i) {
		pa[i].arrive = parr + random()%15;   //假设到达的时间间隔 0～14
		pa[i].treat = random()%9 + 1;		//医生的处理时间为1～9
		parr = pa[i].arrive;
		printf("第[%d]个病人到达的时间为[%d]，处理时间：[%d]\n", i+1, parr, pa[i].treat);
	}
}

int main (void)
{
	Queue *head, *tail;
	Patient *p, curr;	//病人达到及处理时间信息，当前出队病人信息
	int n, i, finish;
	int nowtime;		//时钟
	int dwait, pwait;	//doctor wait time    patient wait time
	head = tail = NULL;	//初始化队列

	while ( 1 ) {
		nowtime = dwait = pwait = 0;
		printf("\n-------------------医务室模拟--------------------\n");
		printf("请输入病人总数（1～20），=0：退出\n");
		scanf("%d", &n);
		if (n == 0) {  //退出
			break;
		} 
		if (n > 20 || n < 0) {
			continue;
		}
		if ( ( p = (Patient *)malloc(n * sizeof(Patient)) ) == NULL ) {
			printf("内存申请错误\n");
			exit(-1);
		}
		InitData(p, n);

		//病人到达未结束上一个诊断或还有等待，处理
		for (i = 0; i < n || head != NULL ; /*空*/) {
			//等待队列为空
			if (head == NULL) {
				//病人达到时间比上次处理时间迟
				if (p[i].arrive - nowtime >= 0) {
					dwait += p[i].arrive - nowtime;	//累计医生等待时间
					nowtime = p[i].arrive;			//时钟推进
					EnQueue(&head, &tail, p[i++]);	//病人入队					
				}
			}
			DeQueue(&head, &tail, &curr);	//一个病人出队
			//累计病人等待时间, 病人要开始治疗的时间（当前时间）- 病人来到医院的时间
			pwait += nowtime - curr.arrive;	
			finish = nowtime + curr.treat;	//当前病人处理时间结束
			while (i < n && p[i].arrive <= finish) {
				//下一个病人达到时间在当前病人等待时间结束之前，入队
				EnQueue(&head, &tail, p[i++]);
			}
			nowtime = finish;	//时钟推进到当前病人处理结束时间
		}
		free(p);
		printf("医生等待时间[%d],病人平均等待时间[%.2f]\n", dwait, (float)pwait/n);
	}
	return 0;
}