/**
 * 问题描述：有下列多项式
 * (2.3x^4 - 2x^2 + 3.1x + 5) + (3.2x^3 + 2x^2 + 7) = (2.3x^4 + 3.2x^3 + 3.1x + 12)
 * 要求利用辗转相除法求两个多项式的最大公因式。其中，多项式的系数按幂次由高到低的顺序存在一个数组中，多项式
 * 的幂次存于一个变量中。
 *
 * 实现要求：已知其中第一项的系数存于数组A中，第二项的系数存于数组B中，要求相加后的多项式系数存于数组A中
 *
 * 程序设计思路：用其中的一个多项式去除另一个多项式，然后将所得余式变成除式，原除式变成被除式。如此反复相除，
 * 知道余式为0时，最后的除式为最大公因式。
 */

#include <stdio.h>
#include <stdlib.h>
#define MIN 0.00005			//定义近似于0的值

void Print (double *q, int n);
int Remainder (double *pa, int an, double *pb, int bn, double **q);
int Input (double **p, int *n, char * note);

int main(void)
{
	double *pA, *pB; 	//多项式A(x),B(x)的系数数组
	double *q;			//最大公因式系数
	int An, Bn;			//多项式A(x),B(x)的幂次
	int n;
	char a[6] = "A(x)";
	char b[6] = "B(x)";
	for (;;) {
		if (Input(&pA, &An, a) != 0) {
			return 1;
		}
		if (Input(&pB, &Bn, b) != 0) {
			return -1;
		}
		printf("\n表达式A(x)的格式为\n");
		Print(pA, An);

		printf("\n表达式B(x)的格式为\n");
		Print(pB, Bn);

		n = Remainder(pA, An, pB, Bn, &q);
		printf("\n最大公因式表达式为\n");
		Print(q, n);
		free(pA);
		free(pB);
	}
	return 0;
}


/*已知两多项式的系数和幂次，返回最大公因式的幂次，在 *q 中得到系数表的首指针*/
int Remainder (double *pa, int an, double *pb, int bn, double **q)
{
	double x, *temp;
	int k, j;
	//使多项式a(x)的幂次不低于多项式b(x)的幂次
	if (an < bn) { 
		temp = pa;		//使pa pb 值互换
		pa = pb;
		pb = temp;
		k = an;			//使an bn 的值互换
		an = bn;
		bn = k;
	}
	for(;;) {   //等价于 while (1)
		while (*pb<MIN && *pb>-MIN && bn>0) {
			/*忽略多项式b(x)最高次系数为0的项*/
			bn--;
			pb++;
		}
		if (*pb<MIN && *pb>-MIN && bn==0) { //注意判断浮点型变量为0的方式
			break;
		}
		if (bn < 0) {  //无最大公因式
			*q = pb;
			return 0;
		}
		k = 0;
		x = *pb;
		while (k <= bn) { //使多项式b(x)的最高次项系数为1
			pb[k++] /= x;
		}

		for (k = 0; k <= an-bn; ++k) { //求a(x)/b(x)，商多项式有an-bn+1项
			x = pa[k];  //商多项式的当前项系数x = pa[k]
			for (j = 0; j < bn; ++j) { //从a(x)中减去x*b(x)
				pa[k+j+1] -= x * pb[j+1];	//pa[k]应置为0，但不再使用，故未置0
			}
		}

		temp = pa;
		pa = pb;
		pb = temp + an - bn + 1;  //b(x) = a(x) / b(x)后的余数多项式
		an = bn--;

	}
	*q = pa;
	return an;		//返回多项式的幂次
}

//多项式输入
int Input (double **p, int *n, char * note)
{ 
	int i;
	double *pa;
	printf("请输入多项式%s的幂次，<=0退出\n", note);
	scanf("%d", n);
	if (*n <= 0){
		return 1;
	}
	if ( (pa = (double*)malloc( (*n+1) * sizeof(double) ) ) == NULL ){
		printf("内存申请错误\n");
		return -1;
	}
	int k = 0;
	for (i = *n; i >= 0; i--) {
		printf("请输入多项式%s%d次幂的系数\n", note, i);
		scanf("%lf", pa+i);
	}
	*p = pa;
	return 0;
}

//输出最大公因式表达式
void Print (double *q, int n) 
{
	int i;
	for (i = n; i >= 1; i--) {
		if (q[i]>MIN || q[i]<-MIN) {
			printf("%.4lfX^%d ", q[i], i);
		}
	}
	if (q[0]>MIN || q[0]<-MIN) {
		printf("%.4lf", q[0]);
	}
	printf("\n");
}
