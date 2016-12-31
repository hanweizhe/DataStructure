#include <stdio.h>
#include <string.h>

void compute_prefix(int *next, char *p)
{
	int		i, n, k;

	n = strlen(p);
	next[1] = next[0] = 0;
	k = 0;		/* 第i次迭代开始之前，k表示next[i-1]的值 */	
	for (i = 2; i <= n; i++) {
		for (; k != 0 && p[k] != p[i-1]; k = next[k])
			;
		
		if (p[k] == p[i-1]) 
			k++;
		next[i] = k;
	}
}

void kmp_match(char *text, char *p, int *next)
{
	int 	m, n, s, q;

	m = strlen(p);
	n = strlen(text);
	q = s = 0;	/* q表示上一次迭代匹配了多少个字符，
				   s表示这次迭代从text的哪个字符开始比较 */ 
	while (s < n) {
		for (q = next[q]; q < m && p[q] == text[s]; q++, s++)
			;
		if (q == 0) 
			s++;
		else if (q == m) {
			printf("pattern occurs with shift %d\n", s-m);
		}
	}
}

int main()
{
	int 	next[101], n;
	char	p[6] = "ca";
	char	text[10] = "cacca";

	compute_prefix(next, p);
	kmp_match(text, p, next);

	return 0;
}