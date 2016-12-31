/**
 * 堆排序，快速排序，希尔排序（都不稳定）
 * 
 * 表排序：元素非常大，移动时间不可忽略的排序，建立一个映射表，形成间接排序。N个数字的排列由若干个独立的环组成
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "RadixSort.c"

typedef int ElementType;

#define N 10
int E[N] = {213, 111, 222, 77, 400, 300, 987, 1024, 632, 555};

void Swap( ElementType *a, ElementType *b )
{
     ElementType t = *a; *a = *b; *b = t;
}

/************************堆排序************************/

void PercDown( ElementType A[], int p, int n )
{/* 将n个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType x;
 
    x = A[p]; /* 取出根结点存放的值 */
    for( Parent = p; (Parent*2+1) < n; Parent = Child ) {
        Child = Parent * 2 + 1;
        if( (Child != n-1) && (A[Child] < A[Child+1]) ){
            Child++;  /* Child指向左右子结点的较大者 */
        }
        if( x >= A[Child] ){
        	break; /* 找到了合适位置 */
        } else {  /* 下滤x */
            A[Parent] = A[Child];
        }
    }
    A[Parent] = x;
}

void HeapSort( ElementType A[], int n ) 
{ 
    int i;
    /* 建立最大堆 */    
    for ( i=n/2-1; i>=0; i-- )
        PercDown( A, i, n );
      
    for ( i=n-1; i>0; i-- ) {
        /* 删除最大堆顶 */
        Swap( &A[0], &A[i] );
        PercDown( A, 0, i );
    }
}
/**********************堆排序结束**********************/

/**
 * 希尔排序 + Sedgewick增量
 * 
 * Hibbard:  D(k) = 2^k - 1
 * Sedgewick: 9*4^i - 9*2^i + 1 或 4^i - 3*2^i + 1
 */
void ShellSort( ElementType A[], int n )
{ /* 希尔排序 - 用Sedgewick增量序列 */
    int Si, D, P, i;
    ElementType Tmp;
    /* 这里只列出一小部分增量 */
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
     
    for ( Si=0; Sedgewick[Si]>=n; Si++ ) 
        ; /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */
 
    for ( D=Sedgewick[Si]; D>0; D=Sedgewick[++Si] )
        for ( P=D; P<n; P++ ) { /* 插入排序 D换成1则为直接插入排序*/
            Tmp = A[P];
            for ( i=P; i>=D && A[i-D]>Tmp; i-=D )
                A[i] = A[i-D];
            A[i] = Tmp;
        }
}

/**********************快速排序***********************/
void InsertionSort ( ElementType A[], int n)
{
	int i, j;
	ElementType t;
	for (i = 1; i < n; ++i) {
		t = A[i];  /* 取出未排序序列中的第一个元素*/
		for (j = i; j > 0 && A[j-1] > t; j--) {
			A[j] = A[j-1]; /*依次与已排序序列中元素比较并右移*/
		}
		A[j] = t; /* 放进合适的位置 */
	}
}

ElementType Median3( ElementType A[], int Left, int Right )
{ 
    int Center = (Left+Right) / 2;
    if ( A[Left] > A[Center] )
        Swap( &A[Left], &A[Center] );
    if ( A[Left] > A[Right] )
        Swap( &A[Left], &A[Right] );
    if ( A[Center] > A[Right] )
        Swap( &A[Center], &A[Right] );
    /* 此时A[Left] <= A[Center] <= A[Right] */
    Swap( &A[Center], &A[Right-1] ); /* 将基准Pivot藏到右边*/
    /* 只需要考虑A[Left+1] … A[Right-2] */
    return  A[Right-1];  /* 返回基准Pivot */
}
 
void Qsort( ElementType A[], int Left, int Right )
{ /* 核心递归函数 */ 
    int Pivot, Cutoff, Low, High;
    Cutoff = 5;   
    if ( Cutoff <= Right-Left ) { /* 如果序列元素充分多，进入快排 */
        Pivot = Median3( A, Left, Right ); /* 选基准 */ 
        Low = Left; High = Right-1;
        while (1) { /*将序列中比基准小的移到基准左边，大的移到右边*/
            while ( A[++Low] < Pivot ) ;
            while ( A[--High] > Pivot ) ;
            if ( Low < High ) Swap( &A[Low], &A[High] );
            else break;
        }
        Swap( &A[Low], &A[Right-1] );   /* 将基准换到正确的位置 */ 
        Qsort( A, Left, Low-1 );    /* 递归解决左边 */ 
        Qsort( A, Low+1, Right );   /* 递归解决右边 */  
    }
    else InsertionSort( A+Left, Right-Left+1 ); /* 元素太少，用简单排序 */ 
}
 
void QuickSort( ElementType A[], int n )
{ /* 统一接口 */
    Qsort( A, 0, n-1 );
}
/*********************快速排序结束**********************/

int main(void)
{
	int i, op;

	printf("初始数据序列：\n");
	for (i = 0; i < N; ++i) {
		printf("%5d", E[i]);
	}
	printf("\n");

	printf("请选择哪种排序：\n");
	printf("1、堆排序 \t 2、希尔排序 \t 3、快速排序 \t 4、基数排序\n");
	scanf("%d", &op);

	switch (op) {
		case 1: 
			HeapSort(E, N);
			break;
		case 2:
			ShellSort(E, N);		
			break;
		case 3:
			QuickSort(E, N);
			break;
		case 4:
			LSDRadixSort(E, N);
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
