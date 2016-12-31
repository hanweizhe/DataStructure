/**
 * 通过循环，按行顺序为一个5*5的二位数组A赋1～25的自然数，然后输出该数组的左下半三角
 */

#include <stdio.h>
#define MAX 5

int main()
{
	int i, j, n = 1;
	int a[MAX][MAX];
	for (i = 0; i < MAX; ++i) {
		for (j = 0; j < MAX; ++j) {
			a[i][j] = n++;
		}
	}
	for (i = 0; i < MAX; ++i) {
		for (j = 0; j <= i; ++j) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}