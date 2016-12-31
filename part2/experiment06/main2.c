#include <stdio.h>
#include <string.h>

int commstr (char *str1, char *str2, int *lenpt)
{
	int len1, len2, ln, count, i, k, p;
	char *st, form[20];
	if ( (len1 = strlen(str1)) < (len2 = strlen(str2)) ) { //使str1的长度不小于str2
		st = str1;
		str1 = str2;
		str2 = st;
		ln = len1;
		len1 = len2;
		len2 = ln;
	}
	count = 0;
	//找长为ln的公共子串
	for (ln = len2; ln > 0; ln--) { 
		//自str2[k]开始的长为ln的子串与str1中的子串做比较
		for (k = 0; k+ln <= len2; k++) {
			//str1中的str1[p]开始，两子串的比较通过对应字符逐一比较实现
			for (p = 0; p+ln <= len1; p++) {

				for (i = 0; i<ln && str2[k+i] == str1[p+i]; i++) ;

				//找到最长公共子串
				if (i == ln) {
					sprintf(form, "子串%%d[%%%d.%ds]\n", ln, ln);
					printf(form, ++count, str2+k);
				}
			}
		}
		if (count) break;
	}

	*lenpt = ln;
	return count;
}

int main()
{
	int c, len;
	char s1[] = "Abc1AbcsAbcd123";
	char s2[] = "123Abc";
	c = commstr(s1, s2, &len);
	printf("共有%d个长为%d的公共子串\n", c, len);

	return 0;
}