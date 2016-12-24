/*将中缀表达式转换成后缀表达式，并计算表达式的值*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXN 100

bool push (char * stack, int maxn, int *toppt, char x)
{
	//栈满
	if ( *toppt >= maxn ){			
		return false;			
	}
	stack[*toppt] = x;
	(*toppt)++;
	return true;
}

bool pop (char * stack, int *toppt, char *cp)
{
	//栈空
	if (*toppt == 0) {
		return false;
	}
	--(*toppt);
	*cp = stack[*toppt];
	return true;
}

int eval (char tag, int a1, int a2)
{
	switch (tag) {
		case '+':
			return a1 + a2;
		case '-':
			return a1 - a2;
		case '*':
			return a1 * a2;
		case '/':
			return a1 / a2;
	}
	return 0;
}

/**
 * 计算后缀表达式的值，返回0为成功，返回-1为表达式错误，返回-2为栈满
 * @param  str 
 * @param  exp 
 * @return     
 */
int operate (char * str, int * exp)
{
	char c;
	int i, opd1, opd2, temp, c1, s[MAXN];
	int top = 0;
	
	for (i = 0; str[i] != '\0'; ++i) {
		c = str[i];
		if (c >= '0' && c<= '9') {  	//数字进栈
			c1 = c - '0';				//字符换成数字
			if (top >= MAXN) {
				printf("表达式太长，栈满\n");
				return -2;
			}
			s[top++] = c1;

		} else if (c == '+' || c == '-' || c == '*' || c == '/') {
			opd1 = s[--top];		
			if (top <= 0 ) {	//如果遇到运算符而栈里没有两个数字，说明出错
				return -1;
			}
			opd2 = s[--top]; 
			temp = eval(c, opd2, opd1);
			s[top++] = temp;
		} else {
			return -1;
		}
	}
	//取出结果
	*exp = s[--top];
	if (top != 0) {			//栈非空
		return -1;
	}
	return 0;
}

/**
 * 将中缀表达式转换成后缀表达式，返回0为处理成功
 * @param  sin  中缀表达式
 * @param  sout 后缀表达式
 * @return      状态码
 */
int trans (char * sin, char * sout)
{
	char s[MAXN], c;		//定义栈、栈元素
	int top = 0;			//设置为空栈
	int off = 0;			//数组下标
	int i;

	//遍历中缀表达式
	for (i = 0; sin[i] != '\0'; ++i) {
		//如果是数字，直接进入后缀表达式数组
		if (sin[i] >= '0' && sin[i] <= '9') {
			sout[off++] = sin[i];
		} else switch (sin[i]) {
			case '(' :				//左括号，括号入栈
				push(s, MAXN, &top, sin[i]);
				break;
			case ')' :				//右括号，将栈中左括号前的元素出栈，存入数组
				while (1) {
					if ( pop(s, &top, &c) == false ) {  //栈空
						printf("表达式括号不匹配\n");	
						return -1;
					}
					if ( c == '(' ) {  //找到匹配的括号
						break;
					}
					sout[off++] = c;	//栈顶元素入数组
				}
				break;
			case '+' :
			case '-' :			//当符号为 '+' '-' 时，将栈中左括号前的元素，存入数组
				while (top > 0 && s[top-1] != '(') {
					pop(s, &top, &c);
					sout[off++] = c;
				}
				push(s, MAXN, &top, sin[i]);		//将 '+' '-' 入栈
				break;
			case '*' :
			case '/' :			// 当符号为'*' '/' 时，将栈顶'*' '/'符号出栈，存入数组
				while ( top > 0 && (s[top-1] == '*' || s[top-1] == '/') ) {
					pop(s, &top, &c);
					sout[off++] = c;
				}
				push(s, MAXN, &top, sin[i]);		//将 '*' '/' 入栈
				break;
		}
		
		
	}
	//最后将栈里元素全部出栈，存入数组
	while (pop(s, &top, &c)) {
		sout[off++] = c;
	}
	//加休止符
	sout[off] = '\0';		
	
	return 0;
}

int main()
{
	char sin[1024], sout[1024];
	int result;
	printf("请输入表达式：\n");
	gets(sin);
	//转换成功
	if (trans(sin, sout) == 0) {
		printf("后缀表达式为：[%s]\n", sout);		
		//计算后缀表达式
		switch( operate(sout, &result) ) {
			case 0:
				printf("计算结果为：[%d]\n", result);
				break;
			case -1:
				printf("表达式错误\n");
				break;
			case -2:
			    printf("栈操作错误\n");
			    break;
		}
	}
	return 0;
}