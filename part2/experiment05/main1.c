/**
 * 问题描述：求 Fibonacci数列的前20项
 * 实现要求：用数组存放，按一行5个数输出
 */
#include <stdio.h>
#define MAX 20

int main(void)
{
	int i;
	int fib[MAX];
	fib[0] = 0;
	fib[1] = 1;
	for (i = 2; i <= MAX; ++i) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	for (i = 0; i < MAX; ++i) {
		printf("%d%c", fib[i], (i%5) == 4? '\n': '\t');
	}
	return 0;
}

