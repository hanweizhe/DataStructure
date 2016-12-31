#include <stdio.h>
#include <string.h>

/*简单模式匹配算法*/

int simple_match (char *t, char *p)
{
	int n, m, i, j, k;
	n = strlen(t);
	m = strlen(p);
	for (j = 0; j <= n-m; j++) {	//顺序考察从t[j]开始的子串
		//从t[j]开始的子串与字符串p做比较
		for (i = 0; i < m && t[j+i] == p[i]; i++) ; 		
		//匹配成功
		if (i == m) return 0; 
	}
	return 1; //匹配失败
}

int main()
{
	char s1[3][10] = {"Abcabc", "Abc123ab", "eeefffg"};
	char s2[3][10] = {"abc", "c123", "fge"};
	int i;
	for (i = 0; i < 3; i++) {
		printf("长字符串[%s]匹配子串[%s]\n", s1[i], s2[i]);
		if (simple_match(s1[i], s2[i]) == 0){
			printf("匹配成功\n");
		} else {
			printf("匹配失败\n");
		}
	}
	return 0;
}