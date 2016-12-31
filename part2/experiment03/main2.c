/*假设一个算术表达式中包含圆括号、方括号和花括号3种类型的括号，编写一个判断表达式中的括号是否正确匹配的函数correct(char *exp)，其中，传入参数为表达式*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXN 20

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

bool correct (char *exp)
{
	int i, flag = true;  //括号匹配标志，0为正确
	char c;
	//初始化栈
	char s[MAXN];
	int top = 0;  

	//循环条件为表达式未结束且括号匹配
	for (i = 0; i < strlen(exp) && flag; ++i) {
		//遇到括号的左半部分则入栈
	 	if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{') {
	 		push(s, MAXN, &top, exp[i]);
	 	}
	 	//遇到括号的右半部分则出栈
	 	if (exp[i]==')' || exp[i]=='[' || exp[i]=='{') {
	 		//先判断栈是否为空，
	 		if ( top == 0 ) {
	 			flag = false; 
	 			break;
	 		} 
	 		pop(exp, &top, &c);
	 		//看出栈的左半括号元素与遇到的右半括号是否不匹配
	 		if ( (exp[i] == ')' && c != '(') ||
		 		 (exp[i] == ']' && c != '[') ||
		 		 (exp[i] == '}' && c != '{') ) {
	 			flag = false; //说明括号不匹配，跳出循环
	 		}
	 	
		}
	}
	//栈不为空，表面还有左半括号在栈里没匹配
	if (top != 0) {
	 	flag = false;
	} 
	return flag;
}

int main()
{
	char exp[1024];
	while (1) {
		printf("请输入表达式，输入0退出\n");
		gets(exp);
		exp[MAXN] = '\0';		//表达式长度<=MAXN
		if (strcmp(exp,"0") == 0) {
			break;
		}
		if (correct(exp)) {
			printf("表达式括号匹配\n");
		} else {
			printf("表达式内容为:\n%s\n表达式括号不匹配\n", exp);
		}
	}

	return 0;
}