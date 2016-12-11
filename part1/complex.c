//复数数据类型的运算

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*存储表示，结构体类型的定义*/
typedef struct 
{
	float x;
	float y;
}Complex;

/*子函数的原型声明*/
void create (Complex * a);
void output (Complex a);
Complex Add (Complex a, Complex b);
Complex Sub (Complex a, Complex b);
Complex Mul (Complex a, Complex b);
Complex Div (Complex a, Complex b);
float Mod (Complex a);

int main (void)
{ 
	Complex a, b, c;

	create(&a);
	output(a);
	
	create(&b);
	output(b);

	printf("加法");
	c = Add(a, b);
	output(c);

	printf("减法");
	c = Sub(a, b);
	output(c);

	printf("乘法");
	c = Mul(a, b);
	output(c);

	printf("除法");
	c = Div(a, b);
	output(c);

	printf("模\n");
	printf("%f\n", Mod(c));

	return 0;
}

//创建一个复数
void create (Complex * a)
{
	float x, y;
	printf("输入实部 x = ");
	scanf("%f", &x);
	printf("输入虚部 y = ");
	scanf("%f", &y);
	a->x = x;
	a->y = y;
}

//输出一个复数
void output (Complex a)
{
	if (a.y == 0) {
		printf("\n%f\n\n", a.x);
	} else if (a.y > 0) {
		printf("\n%f + %fi\n\n", a.x, a.y);
	} else {
		printf("\n%f - %fi\n\n", a.x, -a.y);
	}
}

//两复数相加
Complex Add(Complex a, Complex b)
{
	Complex c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

//复数相减
Complex Sub(Complex a, Complex b)
{
	Complex c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

//复数相乘
Complex Mul (Complex a, Complex b)
{
	Complex c;
	c.x = a.x * b.x - a.y * b.y;    //实部　＝　对应相乘的差
	c.y = a.x * b.y + a.y * b.x;	//虚部　＝　交叉相乘的和
	return c;
}

//复数相除
Complex Div (Complex a, Complex b)
{
	Complex c;
	float denominator;
	denominator = b.x * b.x + b.y * b.y;			//实部和虚部的分母
	c.x = (a.x * b.x + a.y * b.y) / denominator;	//实部分子　=　对应相乘的和
	c.y = (a.y * b.x - a.x * b.y) / denominator;	//虚部分子　=　交叉相乘的差
	return c;
}

//复数的模
float Mod (Complex a)
{
	return sqrt(a.x * a.x + a.y * a.y);    // （实部平方＋虚部平方）开根号
}

