#include <stdio.h>
#include <stdlib.h>
#define N 10

int E[N] = {213, 111, 222, 77, 400, 300, 987, 1024, 632, 555};

/**
 * 选择排序
 * @param e 存储线性表的数组
 * @param n 线性表的节点数
 */
void s_sort (int e[], int n)
{
	int i, j, k, t;
	//控制n-1趟的选择步骤
	for (i = 0; i < n-1; ++i) {
		//在e[i],e[i+1],....,e[n-1]之间选择最小值e[k]
		for (k = i, j = i+1; j < n; ++j) {
			if (e[k] > e[j]) {
				k = j;
			}
		}
		if (i != k) {	//交换e[i]与e[k]
			t = e[i];
			e[i] = e[k];
			e[k] = t;
		}
	}
}

/**
 * 直接插入排序
 * @param e 待排数组
 * @param n 数组长度
 */
void si_sort (int e[], int n)
{
	int i, j, t;
	//控制e[i],e[i+1],...e[n-1]的比较插入步骤
	for (i = 1; i < n; ++i) {
		//找结点e[i]的插入位置。
		for (t = e[i], j = i-1; j >= 0 && t < e[j]; j--) {
			e[j+1] = e[j];
		}
		e[j+1] = t;
	}
}

/**
 * 冒泡排序
 * @param e 待排数组
 * @param n 数组长度
 */
void sb_sort (int e[], int n)
{
	int j, h, t;
	for (h = n-1 ; h > 0; h--) {
		for (j = 0; j < h; j++) {
			if (e[j] > e[j+1]) {
				t = e[j];
				e[j] = e[j+1];
				e[j+1] = t;
			}
		}
	}
}

/***************归并算法*******************/

/**
 * 两个相邻有序段的合并
 * @param e 两段有序数组
 * @param a 存储排好的数组
 * @param L 第一段有序数组的开始下标
 * @param R 第二段有序数组的开始下标
 * @param RightEnd 第二段有序数组的结束下标
 */
void merge_step (int e[], int a[], int L, int R, int RightEnd)
{
	int LeftEnd, Tmp;
      
    LeftEnd = R - 1; /* 左边终点位置 */
    Tmp = L;         /* 有序序列的起始位置 */
      
    while( L <= LeftEnd && R <= RightEnd ) {
        if ( e[L] <= e[R] )
            a[Tmp++] = e[L++]; /* 将左边元素复制到TmpA */
        else
            a[Tmp++] = e[R++]; /* 将右边元素复制到TmpA */
    }
 
    while( L <= LeftEnd )
        a[Tmp++] = e[L++]; /* 直接复制左边剩下的 */
    while( R <= RightEnd )
        a[Tmp++] = e[R++]; /* 直接复制右边剩下的 */
}

/**
 * 完成一趟完整的合并
 * @param e   原数组
 * @param a   临时数组
 * @param n   数组长度
 * @param len 有序段的长度
 */
void merge_pass (int e[], int a[], int n, int len) 
{
	int i, j;
	for (i = 0; i <= n-2*len; i += 2*len)
		merge_step(e, a, i, i+len, i+2*len-1);
	if (i+len < n) {  //归并最后两个子列
		merge_step(e, a, i, i+len, n-1);
	} else {	//最后只剩一个子列
		for (j = i; j < n; j++)
			a[j] = e[j]; 
	}	
}

/**
 * 归并排序
 * @param e 待排数组
 * @param n 数组长度
 */
void merge(int e[], int n)
{
	int *p, len = 1;
	p = (int *)malloc(n * sizeof(int));
	
	while (len < n) {		
		//交替地在e[]和p[]之间来回合并
		merge_pass(e, p, n, len);
		len *= 2;	//一趟合并后，有序结点数加倍
		
		merge_pass(p, e, n, len);
		len *= 2;	
	}
	free(p);
}		


/***************归并算法结束**************/

int main(void)
{
	int i, op;

	printf("初始数据序列：\n");
	for (i = 0; i < N; ++i) {
		printf("%5d", E[i]);
	}
	printf("\n");

	printf("请选择哪种排序：\n");
	printf("1、冒泡排序 \t 2、选择排序 \t 3、直接插入排序 \t 4、归并排序\n");
	scanf("%d", &op);

	switch (op) {
		case 1: 
			sb_sort(E, N);
			break;
		case 2:		
			s_sort(E, N);
			break;
		case 3:
			si_sort(E, N);
			break;
		case 4:
			merge(E, N);
			break;
		default:
			printf("选择1~4\n");
			break;
	}

	printf("排序后的数据序列：\n");
	for (i = 0; i < N; ++i) {
		printf("%5d", E[i]);
	}
	printf("\n");


	return 0;
} 