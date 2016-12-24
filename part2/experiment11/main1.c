#include <stdio.h>
#include <stdbool.h>

#define N 10
int E[N] = {213, 111, 222, 77, 400, 300, 987, 1024, 632, 555};

/**
 * 交换函数
 * @param x 
 * @param y 
 */
void Swap (int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * 冒泡排序
 * @param a 数组
 * @param n 数组长度
 */
void BubbleSort3 (int a[], int n)
{
	int j, k, flag;

	flag = n;
	while (flag > 0) {
		k = flag;
		flag = 0;

		for (j = 1; j < k; ++j) {
			if (a[j-1] > a[j]) {
				Swap(&a[j-1], &a[j]);
				flag = j;
			}
		}
	}
}

//无序线性表的顺序排序
int Search1 (int *k, int n, int key)
{
	int i;
	for (i = 0; i < n && key != k[i]; ++i) 
		; //什么也不执行
	return (i < n ? i: -1);
}

//有序线性表的顺序排序
int Search2 (int *k, int n, int key)
{
	int i;
	for (i = 0; i < n && key > k[i]; ++i) 
		; //什么也不执行

	if (i < n && key == k[i]) {
		return i;
	}
	return -1;
}

//二分法查找
int bin_search (int *k, int n, int key) 
{
	int low = 0, high = n-1, mid;
	while (low <= high) {
		mid = (low+high) / 2;
		if (key == k[mid]) {
			return mid;
		}
		if (key > k[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int i, j;

	printf("初始数据序列为：\n");
	for (i = 0; i < N; i++) {
		printf("%5d", E[i]);
	}

	printf("\n输入要查到的关键码");
	scanf("%d", &i);
	if ( (j = Search1(E, N, i)) >= 0 ) {
		printf("找到关键字，位置为%d\n", j+1);
	} else {
		printf("找不到\n");
	}
	
	BubbleSort3(E, N);
	printf("\n排序后数据序列为：\n");
	for (i = 0; i < N; i++) {
		printf("%5d", E[i]);
	}

	printf("\n\n输入要查到的关键码");
	scanf("%d", &i);
	if ( (j = Search2(E, N, i)) >= 0 ) {
		printf("找到关键字，位置为%d\n", j+1);
	} else {
		printf("找不到\n");
	}

	printf("\n输入要查到的关键码");
	scanf("%d", &i);
	if ( (j = bin_search(E, N, i)) >= 0 ) {
		printf("找到关键字，位置为%d\n", j+1);
	} else {
		printf("找不到\n");
	}

	return 0;
}