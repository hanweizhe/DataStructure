/** 
 *    问题描述：某集团公司为发展生产向社会公开招聘m个工种的工作人员，每个工种各有不同的编号（0～m-1）和计划招聘人数，
 * 参加应聘人数有n个（编号为0～n-1）。每位应聘者需申报两个工种，并参加公司组织的考试，公司将按照应聘者的成绩从高到低
 * 的顺序进行录取。公司的录取原则是，从高分到低分一次对每位应聘者先按其第一志愿录取，当不能按第一职员录取时，便将他的
 * 成绩扣去5分，然后重新排队，并按其第二志愿录取。
 *    
 * 	  实现要求：要求程序输出每个工作的录用信息（编号，成绩），以及落选者的信息（编号，成绩）
 *
 * 	  程序设计思路：程序按应聘者的成绩从高到低的顺序进行录取，如果某应聘者在第一志愿队列中落选，便将他的成绩扣去5分，
 * 然后重新排队，并将其第二志愿录取。程序为每个工种保留一个录取者的有序队列，录取处理循环直至招聘额满或已对所有应聘者
 * 做了录用处理。
 */

#include <stdio.h>
#include <stdlib.h>
#define DEMARK 5	//按第二批录用的扣分成绩

typedef struct stu {
	int no, total, z[2], sortm, zi;  //编号，总成绩，志愿，排除成绩，录取志愿号
	struct stu * next;
}Stu;

typedef struct job {
	int lmt, count;		//计划录取人数， 已录用人数
	Stu * stu;			//录用者有序队列
}Job;

/**
 * 输出应聘人数有序队列中的编号与成绩
 */
void Output (Stu * p)
{
	for (/*空*/;p != NULL; p = p->next) {
		printf("%d(%d)\t", p->no, p->total);
	}
}

//释放应聘人员的空间
void FreeStu (Stu ** p)
{
	Stu *q;
	while (*p != NULL) {
		q = *p;
		*p = (*p)->next;
		free(q);
	}
}

//按排除成绩从大到小顺序插队
void Insert (Stu **p, Stu *u)
{
	Stu *v, *q;		//插队元素的前，后元素指针
	for (q = *p; q != NULL; v = q, q = q->next) {
		if (q->sortm < u->sortm) {
			break;
		}
	}
	if (q == *p) { //插入队首
		*p = u;
	} else {
		v->next = u;
	}
	u->next = q;
}

//随机生成工种信息
int InitJob (Job ** h, int n, int *all) 
{
	int i;
	Job *p;
	*all = 0;
	printf("工种信息{工种号（计划招聘人数）}\n");
	if ( (p = (Job *)malloc(n * sizeof(Job))) == NULL) {
		printf("内存申请错误\n");
		return -1;
	}
	for (i = 0; i < n; ++i) {
		p[i].lmt = random()%10 + 1; //假设工种招聘人数1～10
		p[i].count = 0;
		p[i].stu = NULL;
		*all += p[i].lmt;
		printf("%d（ %d ）\n", i, p[i].lmt);
	}
	printf("\n总招聘人数[%d]\n", *all);
	*h = p;
	return 0;
}

//随机生成应聘人员信息
int InitStu (Stu ** h, int n, int m)
{
	Stu *p;
	int i;
	printf("应聘人员信息{编号，总成绩，志愿1，志愿2}\n");
	for (i = 0; i < n; ++i) {
		if ( (p = (Stu *)malloc(sizeof(Stu))) == NULL) {
			printf("内存申请错误\n");
			return -1;
		}
		p->no = i;
		p->total = p->sortm = random()%201;
		p->z[0] = random()%m;
		p->z[1] = random()%m;
		p->zi = 0;  //录取志愿初始化为0，即第一志愿
		printf("%d, %3d, %d, %d\n", i, p->total, p->z[0], p->z[1]);
		Insert(h, p);
	}
	return 0;
}

int main()
{
	int i;
	int m;		//工种总数，编号为0～m-1
	int n;  	//应聘人员总数
	Job *rz; 	
	int all;	//计划招聘人员总数
	Stu *head = NULL, *over = NULL;
	Stu *p;

	while (1) {
		m = n = 0;
		printf("\n--------------------招聘模拟-----------------\n");
		printf("请输入工种总数（1～20），=0：退出\n");
		scanf("%d", &m);
		if (m == 0) {	//退出
			break;
		} 
		if (m > 20 || m < 0) {
			continue;
		}
		if ( InitJob(&rz, m, &all) != 0 ) {
			break;
		}

		printf("\n请输入应聘人员总数（5～400）,=0:退出\n");
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		if (n < 5 || n > 400) {
            free(rz);   
			continue;
		}
		if ( InitStu(&head, n, m) != 0 ){
			break;
		}
		
		printf("\n应聘人员队列\n");
		Output(head);
		printf("\n");
		//当人员没有招满且队列不为空
		while (all > 0 && head != NULL) {
			p = head; 
			head = head->next;
			i = p->z[p->zi];	//取该应聘人员的应聘工种号
			//如果该工种没有招满
			if (rz[i].count < rz[i].lmt) {
				rz[i].count++;
				Insert(&rz[i].stu, p);
				all--;
				continue;
			}
			if (p->zi >= 1) {
				p->next = over;   //该工人入落聘者队列
				over = p;
				continue;
			}
			p->sortm -= DEMARK;		//该工种已招满，工人分数降档
			p->zi = 1;				//该工人改为第二志愿
			Insert(&head, p);		//重新入队
		}
		//打印各工种招聘情况
		for (i = 0; i < m; ++i) {
			printf("\n工种[%d]招聘情况\n", i);
			Output(rz[i].stu);
		}
		printf("\n\n落聘人员\n");
		Output(head);
		Output(over);

		//释放空间
		for (i = 0; i < m; ++i) {
			FreeStu (&rz[i].stu);
		}
		FreeStu(&head);
		FreeStu(&over);
		free(rz);
	}

	return 0;
}
